#ifndef SLOPECRAFT_VISUALCRAFT_VCWIND_H
#define SLOPECRAFT_VISUALCRAFT_VCWIND_H

#include <QMainWindow>
#include <VisualCraftL.h>
#include <map>

class QListWidget;
class QListWidgetItem;
class VC_block_class;

namespace Ui {
class VCWind;
}

class VCWind : public QMainWindow {
  Q_OBJECT
public:
  struct convert_option {
    SCL_convertAlgo algo;
    bool dither;

    inline bool operator==(convert_option another) const noexcept {
      return this->algo == another.algo && this->dither == another.dither;
    }

    inline bool operator!=(convert_option another) const noexcept {
      return !((*this) == another);
    }
  };

  struct basic_colorset_option {
    std::vector<QString> zips;
    std::vector<QString> jsons;
    VCL_face_t face;
    SCL_gameVersion version;
    int layers;
  };

  struct allowed_colorset_option {
    std::vector<VCL_block *> blocks;
  };

private:
  // for all pages
  Ui::VCWind *ui;
  VCL_Kernel *const kernel{nullptr};
  // for page 0
  VCL_resource_pack *rp{nullptr};
  VCL_block_state_list *bsl{nullptr};
  // bool is_basical_colorset_changed{true};

  // for page 1
  std::map<VCL_block_class_t, VC_block_class *> map_VC_block_class{};
  // bool is_allowed_colorset_changed{true};
  //  for page 2
  std::map<QString, std::pair<QImage, QImage>> image_cache;
  // for page 3
  // for page 4
  QPoint prev_compute_device{-3, -3};

  // static bool have_special(QListWidget *qlw) noexcept;

public:
  explicit VCWind(QWidget *parent = nullptr);
  ~VCWind();

private:
  // for all pages
  static void callback_progress_range_set(void *, int, int, int) noexcept;
  static void callback_progress_range_add(void *, int) noexcept;

  // for page 0 ------------------------------------------
  //  create and set this->rp
  void create_resource_pack() noexcept;
  // create and set this->bsl
  void create_block_state_list() noexcept;

  // receive current selected version from ui
  SCL_gameVersion current_selected_version() const noexcept;
  VCL_face_t current_selected_face() const noexcept;

  basic_colorset_option current_basic_option() const noexcept;

  QByteArray checksum_basic_colorset_option(
      const basic_colorset_option &opt) const noexcept;

  static QByteArray
  checksum_allowed_colorset_option(const allowed_colorset_option &opt) noexcept;

  bool is_basical_colorset_changed() const noexcept;

  static void append_default_to_rp_or_bsl(QListWidget *qlw,
                                          bool is_rp) noexcept;
  void setup_basical_colorset() noexcept;

  // void connect_when_basical_colorset_changed() noexcept;
  //  for page 1 ------------------------------------------
  size_t selected_blocks(std::vector<VCL_block *> *blocks_dest) const noexcept;
  bool is_allowed_colorset_changed(allowed_colorset_option *opt) const noexcept;

  void setup_allowed_colorset() noexcept;

  bool is_convert_algo_changed() const noexcept;

  // void connect_when_allowed_colorset_changed() noexcept;

  // for page 2 ------------------------------------------
  void setup_image(const QImage &img) noexcept;
  SCL_convertAlgo current_selected_algo() const noexcept;
  void show_image(decltype(image_cache)::iterator) noexcept;

  void clear_convert_cache() noexcept;

  convert_option current_convert_option() const noexcept;

  // for page 3 ------------------------------------------
  // for page 4 ------------------------------------------
  void refresh_gpu_info() noexcept;
  void select_default_device() noexcept;
private slots:

  // for page 0

  // auto connected
  void on_pb_add_rp_clicked() noexcept;
  void on_pb_remove_rp_clicked() noexcept;
  // auto connected
  void on_pb_add_bsl_clicked() noexcept;
  void on_pb_remove_bsl_clicked() noexcept;

  // manually connected
  // void when_basical_colorset_changed() noexcept;

  // for page 1

  // manually connected
  void setup_block_widgets() noexcept;
  // void when_allowed_colorset_changed() noexcept;
  //  for page 2

  // auto connected
  void on_tb_add_images_clicked() noexcept;
  void on_tb_remove_images_clicked() noexcept;

  // auto connected
  void on_cb_show_raw_size_stateChanged(int state) noexcept;
  void on_cb_show_raw_stateChanged(int state) noexcept;
  void on_cb_show_converted_stateChanged(int state) noexcept;
  void on_lw_image_files_itemClicked(QListWidgetItem *item) noexcept;

  // manually connected
  void when_algo_dither_bottons_toggled() noexcept;

  // for page 3
  // for page 4

  // auto connected
  void on_sb_threads_valueChanged(int val) noexcept;

  // auto connected
  void on_combobox_select_device_currentIndexChanged(int idx) noexcept;
};

#endif // SLOPECRAFT_VISUALCRAFT_VCWIND_H
