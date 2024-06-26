/*
 Copyright © 2021-2023  TokiNoBug
This file is part of SlopeCraft.

    SlopeCraft is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    SlopeCraft is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with SlopeCraft. If not, see <https://www.gnu.org/licenses/>.

    Contact with me:
    github:https://github.com/SlopeCraft/SlopeCraft
    bilibili:https://space.bilibili.com/351429231
*/

#include <fmt/format.h>
#include <json.hpp>
#include <tl/expected.hpp>
#include <zip.h>
#include <libpng_reader.h>

#include "SlopeCraftL.h"
#include "TokiSlopeCraft.h"
#include "simpleBlock.h"
#include "WriteStringDeliver.h"

using namespace SlopeCraft;

// AbstractBlock *AbstractBlock::create() { return new simpleBlock; }

void AbstractBlock::clear() noexcept {
  setBurnable(false);
  setDoGlow(false);
  setEndermanPickable(false);
  setId("minecraft:air");
  setIdOld("");
  setNeedGlass(false);
  setVersion(0);
  setNameZH("");
  setNameEN("");
  // setWallUseable(false);
}

Kernel::Kernel() {}

using namespace SlopeCraft;

std::pair<uint8_t, simpleBlock> parse_block(const nlohmann::json &jo) noexcept(
    false) {
  simpleBlock ret;
  const int basecolor = jo.at("baseColor");
  if (basecolor < 0 || basecolor >= 64) {
    throw std::runtime_error{fmt::format("Invalid base color: {}", basecolor)};
  }

  ret.id = jo.at("id");
  ret.nameZH = jo.at("nameZH");
  ret.nameEN = jo.at("nameEN");
  ret.imageFilename = jo.at("icon");
  ret.version = jo.at("version");
  if (jo.contains("idOld")) {
    ret.idOld = jo.at("idOld");
  } else {
    ret.idOld = ret.id;
  }

  if (jo.contains("endermanPickable")) {
    ret.endermanPickable = jo.at("endermanPickable");
  }

  if (jo.contains("isGlowing")) {
    ret.doGlow = jo.at("isGlowing");
  }

  if (jo.contains("burnable")) {
    ret.burnable = jo.at("burnable");
  }

  if (jo.contains("needGlass")) {
    ret.needGlass = jo.at("needGlass");
  }

  return {basecolor, ret};
}

// BlockListInterface *impl_createBlockList(const char *filename,
//                                          const blockListOption &option,
//                                          std::string &errmsg) noexcept {
//   errmsg.reserve(4096);
//   errmsg.clear();
//
//   BlockList *bl = new BlockList;
//   using njson = nlohmann::json;
//   try {
//     std::ifstream ifs(filename);
//     njson jo = njson::parse(ifs, nullptr, true, true);
//
//     njson::array_t arr;
//     if (jo.contains("FixedBlocks")) {
//       arr = std::move(jo.at("FixedBlocks"));
//     } else {
//       arr = std::move(jo.at("CustomBlocks"));
//     }
//
//     // parse blocks
//     for (size_t idx = 0; idx < arr.size(); idx++) {
//       auto temp = parse_block(arr[idx], option.image_dir);
//
//       auto ptr = new simpleBlock;
//       *ptr = std::move(temp.second);
//       bl->blocks().emplace(ptr, temp.first);
//     }
//
//   } catch (std::exception &e) {
//     delete bl;
//     errmsg += fmt::format(
//         "Exception occured when parsing blocklist json: \"{}\"\n", e.what());
//     return nullptr;
//   }
//
//   // load images
//   for (auto &pair : bl->blocks()) {
//     pair.first->image.resize(16, 16);
//     if (!option.callback_load_image(pair.first->getImageFilename(),
//                                     pair.first->image.data())) {
//       errmsg += fmt::format(
//           "Failed to load image \"{}\", this error will be ignored.\n",
//           pair.first->getImageFilename());
//       continue;
//     }
//     pair.first->image.transposeInPlace();
//   }
//
//   return bl;
// }

struct zip_deleter {
  void operator()(zip_t *archive) const noexcept {
    if (archive == nullptr) {
      return;
    }
    zip_close(archive);
  }
};

std::tuple<tl::expected<BlockListInterface *, std::string>, std::string>
impl_create_block_list_from_zip(const char *zip_path) noexcept {
  std::string warnings{};
  int error_code = ZIP_ER_OK;
  std::unique_ptr<zip_t, zip_deleter> archive{
      zip_open(zip_path, ZIP_RDONLY | ZIP_CHECKCONS, &error_code)};
  if (archive == nullptr) {
    return {tl::make_unexpected(fmt::format(
                "Failed to open archive \"{}\" with libzip error code {}",
                zip_path, error_code)),
            warnings};
  }
  if (error_code != ZIP_ER_OK) {
    auto ret = tl::make_unexpected(fmt::format(
        "Failed to open archive \"{}\" : \"{}\" libzip error code = {}",
        zip_path, zip_strerror(archive.get()), error_code));
    return {ret, warnings};
  }

  auto extract_file =
      [zip_path, &archive](
          const char *filename,
          std::vector<uint8_t> &dest) -> tl::expected<void, std::string> {
    dest.clear();

    int error_code = ZIP_ER_OK;
    const int64_t index_i =
        zip_name_locate(archive.get(), filename, ZIP_FL_UNCHANGED);
    if (index_i < 0) {
      return tl::make_unexpected(fmt::format(
          "File \"{}\" doesn't exist in archive \"{}\"", filename, zip_path));
    }
    const uint64_t index = uint64_t(index_i);

    zip_stat_t stat;
    error_code = zip_stat_index(archive.get(), index, ZIP_FL_UNCHANGED, &stat);
    if (error_code != ZIP_ER_OK) {
      return tl::make_unexpected(fmt::format(
          "Failed to get size of file \"{}\"  in archive \"{}\" : \"{}\", "
          "error code = {}",
          filename, zip_path, zip_strerror(archive.get()), error_code));
    }

    const uint64_t file_size = stat.size;
    dest.resize(file_size);

    auto file = zip_fopen(archive.get(), filename, ZIP_FL_UNCHANGED);
    if (file == nullptr) {
      return tl::make_unexpected(
          fmt::format("Failed to extract \"{}\" from archive \"{}\" : \"{}\" ",
                      filename, zip_path, zip_strerror(archive.get())));
    }

    const int64_t read_bytes = zip_fread(file, dest.data(), dest.size());
    if (read_bytes != int64_t(file_size)) {
      return tl::make_unexpected(
          fmt::format("Failed to extract \"{}\" from archive \"{}\", expected "
                      "{} bytes, but extracted {} bytes : \"{}\" ",
                      filename, zip_path, file_size, read_bytes,
                      zip_strerror(archive.get())));
    }
    return {};
  };

  std::vector<uint8_t> buffer;
  {
    auto err = extract_file("BlockList.json", buffer);
    if (!err) {
      return {tl::make_unexpected(err.error()), warnings};
    }
  }

  BlockList *bl = new BlockList;

  using njson = nlohmann::json;
  try {
    njson jo = njson::parse(buffer, nullptr, true, true);
    if (!jo.is_array()) {
      return {tl::make_unexpected(
                  fmt::format("Json should contain an array directly")),
              warnings};
    }

    // parse blocks
    for (size_t idx = 0; idx < jo.size(); idx++) {
      auto [version, block] = parse_block(jo[idx]);
      bl->blocks().emplace(std::make_unique<simpleBlock>(block), version);
    }

  } catch (const std::exception &e) {
    delete bl;
    return {tl::make_unexpected(
                fmt::format("nlohmann json exception : {}", e.what())),
            warnings};
  }
  // load images
  std::vector<uint32_t> buf_pixel;
  for (auto &pair : bl->blocks()) {
    {
      auto err = extract_file(pair.first->imageFilename.c_str(), buffer);
      if (!err) {
        warnings +=
            fmt::format("{}, required by {}", err.error(), pair.first->id);
        continue;
      }
    }

    pair.first->image.resize(16, 16);
    {
      auto [result, warns] = parse_png_into_argb32(buffer, buf_pixel);
      warnings += warns;

      if (!result) {
        fmt::format_to(std::back_insert_iterator{warnings},
                       "Failed to load image \"{}\" because \"{}\"\n",
                       pair.first->getImageFilename(), result.error());
        //        for (uint8_t byte : buffer) {
        //          printf("%02X ", int(byte));
        //        }
        //        printf("\n");
        continue;
      }
      auto image_size = result.value();
      if (image_size.rows != 16 || image_size.cols != 16) {
        fmt::format_to(std::back_insert_iterator{warnings},
                       "{} has invalid shape, expected 16x16, but found {} "
                       "rows x {} cols.\n",
                       pair.first->getImageFilename(), image_size.rows,
                       image_size.cols);
        continue;
      }
    }
    assert(buf_pixel.size() == 16 * 16);
    memcpy(pair.first->image.data(), buf_pixel.data(), 256 * sizeof(uint32_t));
  }

  return {bl, warnings};
}

extern "C" {

SCL_EXPORT Kernel *SCL_createKernel() { return new TokiSlopeCraft; }
SCL_EXPORT void SCL_destroyKernel(Kernel *k) {
  delete static_cast<TokiSlopeCraft *>(k);
}

SCL_EXPORT AbstractBlock *SCL_createBlock() { return new simpleBlock; }
SCL_EXPORT void SCL_destroyBlock(AbstractBlock *b) { delete b; }

SCL_EXPORT BlockListInterface *SCL_createBlockList(
    const char *zip_filename, const BlockListCreateOption &option) {
  auto [res, warnings] = impl_create_block_list_from_zip(zip_filename);

  SlopeCraft::write(*option.warnings, warnings);
  if (!res) {
    SlopeCraft::write(*option.error, res.error());
    return nullptr;
  }

  return res.value();
}

SCL_EXPORT void SCL_destroyBlockList(BlockListInterface *) {}

SCL_EXPORT AiCvterOpt *SCL_createAiCvterOpt() { return new AiCvterOpt; }
void SCL_EXPORT SCL_destroyAiCvterOpt(AiCvterOpt *a) { delete a; }

void SCL_EXPORT SCL_setPopSize(AiCvterOpt *a, unsigned int p) {
  a->popSize = p;
}
void SCL_EXPORT SCL_setMaxGeneration(AiCvterOpt *a, unsigned int p) {
  a->maxGeneration = p;
}
void SCL_EXPORT SCL_setMaxFailTimes(AiCvterOpt *a, unsigned int p) {
  a->maxFailTimes = p;
}
void SCL_EXPORT SCL_setCrossoverProb(AiCvterOpt *a, double p) {
  a->crossoverProb = p;
}
void SCL_EXPORT SCL_setMutationProb(AiCvterOpt *a, double p) {
  a->mutationProb = p;
}

unsigned int SCL_EXPORT SCL_getPopSize(const AiCvterOpt *a) {
  return a->popSize;
}
unsigned int SCL_EXPORT SCL_getMaxGeneration(const AiCvterOpt *a) {
  return a->maxGeneration;
}
unsigned int SCL_EXPORT SCL_getMaxFailTimes(const AiCvterOpt *a) {
  return a->maxFailTimes;
}
double SCL_EXPORT SCL_getCrossoverProb(const AiCvterOpt *a) {
  return a->crossoverProb;
}
double SCL_EXPORT SCL_getMutationProb(const AiCvterOpt *a) {
  return a->mutationProb;
}

SCL_EXPORT void SCL_getColorMapPtrs(const float **const rdata,
                                    const float **const gdata,
                                    const float **const bdata,
                                    const uint8_t **mapdata, int *num) {
  TokiSlopeCraft::getColorMapPtrs(rdata, gdata, bdata, mapdata, num);
}

SCL_EXPORT const float *SCL_getBasicColorMapPtrs() {
  return TokiSlopeCraft::getBasicColorMapPtrs();
}

SCL_EXPORT const char *SCL_getSCLVersion() {
  return TokiSlopeCraft::getSCLVersion();
}

SCL_EXPORT SCL_gameVersion SCL_basecolor_version(uint8_t basecolor) {
  if (basecolor <= 51) {
    return SCL_gameVersion::ANCIENT;
  }

  if (basecolor <= 58) {
    return SCL_gameVersion::MC16;
  }

  if (basecolor <= 61) {
    return SCL_gameVersion::MC17;
  }
  return SCL_gameVersion::FUTURE;
}

SCL_EXPORT uint8_t SCL_maxBaseColor() { return 61; }

SCL_EXPORT int SCL_getBlockPalette(const AbstractBlock **blkpp,
                                   size_t capacity) {
  return TokiSlopeCraft::getBlockPalette(blkpp, capacity);
}
}
