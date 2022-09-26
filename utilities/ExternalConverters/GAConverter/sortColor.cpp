/*
 Copyright © 2021-2022  TokiNoBug
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
    along with SlopeCraft.  If not, see <https://www.gnu.org/licenses/>.

    Contact with me:
    github:https://github.com/ToKiNoBug
    bilibili:https://space.bilibili.com/351429231
*/

#include "sortColor.h"

using namespace GACvter;
using namespace SlopeCraft;

sortColor::sortColor() noexcept {}

void sortColor::calculate(ARGB rgb) noexcept {
  const float r = getR(rgb) / 255.0f, g = getG(rgb) / 255.0f,
              b = getB(rgb) / 255.0f;

  auto diffR = SlopeCraft::AllowedRGB4External(0) - r;
  // SlopeCraft::Allowed4External.col(0)-r;
  // SlopeCraft::Allowed4External.col(0)-r;
  auto diffG = SlopeCraft::AllowedRGB4External(1) - g;
  auto diffB = SlopeCraft::AllowedRGB4External(2) - b;

  TempVectorXf diff = diffR.square() + diffG.square() + diffB.square();

  for (order_t o = 0; o < OrderMax; o++) {
    int tempIdx = 0;
    // errors[o]=
    diff.minCoeff(&tempIdx);
    mapCs[o] = SlopeCraft::AllowedMapList4External()[tempIdx];
    // Converter::mapColorSrc->operator[](tempIdx);
    diff[tempIdx] = heu::internal::pinfF;
  }
}
