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

//#include "SCLDefines.h"
namespace SlopeCraft {
extern const float RGBBasicSource[256 * 3];

const float RGBBasicSource[256 * 3] = {
    0 / 255.0f,   90 / 255.0f,  174 / 255.0f, 140 / 255.0f, 180 / 255.0f,
    113 / 255.0f, 118 / 255.0f, 0 / 255.0f,   180 / 255.0f, 116 / 255.0f,
    107 / 255.0f, 79 / 255.0f,  45 / 255.0f,  101 / 255.0f, 180 / 255.0f,
    152 / 255.0f, 126 / 255.0f, 72 / 255.0f,  162 / 255.0f, 90 / 255.0f,
    171 / 255.0f, 54 / 255.0f,  108 / 255.0f, 54 / 255.0f,  90 / 255.0f,
    36 / 255.0f,  72 / 255.0f,  72 / 255.0f,  108 / 255.0f, 18 / 255.0f,
    176 / 255.0f, 65 / 255.0f,  52 / 255.0f,  0 / 255.0f,   91 / 255.0f,
    79 / 255.0f,  148 / 255.0f, 112 / 255.0f, 105 / 255.0f, 79 / 255.0f,
    131 / 255.0f, 73 / 255.0f,  113 / 255.0f, 40 / 255.0f,  95 / 255.0f,
    61 / 255.0f,  86 / 255.0f,  54 / 255.0f,  54 / 255.0f,  54 / 255.0f,
    100 / 255.0f, 26 / 255.0f,  133 / 255.0f, 104 / 255.0f, 65 / 255.0f,
    16 / 255.0f,  41 / 255.0f,  61 / 255.0f,  14 / 255.0f,  69 / 255.0f,
    131 / 255.0f, 89 / 255.0f,  0 / 255.0f,   0 / 255.0f,   0 / 255.0f,
    110 / 255.0f, 213 / 255.0f, 172 / 255.0f, 220 / 255.0f, 138 / 255.0f,
    144 / 255.0f, 0 / 255.0f,   220 / 255.0f, 141 / 255.0f, 130 / 255.0f,
    97 / 255.0f,  55 / 255.0f,  123 / 255.0f, 220 / 255.0f, 186 / 255.0f,
    154 / 255.0f, 88 / 255.0f,  198 / 255.0f, 110 / 255.0f, 209 / 255.0f,
    66 / 255.0f,  132 / 255.0f, 66 / 255.0f,  110 / 255.0f, 44 / 255.0f,
    88 / 255.0f,  88 / 255.0f,  132 / 255.0f, 22 / 255.0f,  216 / 255.0f,
    79 / 255.0f,  64 / 255.0f,  0 / 255.0f,   111 / 255.0f, 97 / 255.0f,
    180 / 255.0f, 137 / 255.0f, 129 / 255.0f, 97 / 255.0f,  160 / 255.0f,
    89 / 255.0f,  138 / 255.0f, 49 / 255.0f,  116 / 255.0f, 75 / 255.0f,
    105 / 255.0f, 66 / 255.0f,  66 / 255.0f,  66 / 255.0f,  123 / 255.0f,
    32 / 255.0f,  163 / 255.0f, 128 / 255.0f, 79 / 255.0f,  19 / 255.0f,
    50 / 255.0f,  74 / 255.0f,  17 / 255.0f,  85 / 255.0f,  160 / 255.0f,
    109 / 255.0f, 0 / 255.0f,   0 / 255.0f,   0 / 255.0f,   127 / 255.0f,
    247 / 255.0f, 199 / 255.0f, 255 / 255.0f, 160 / 255.0f, 167 / 255.0f,
    0 / 255.0f,   255 / 255.0f, 164 / 255.0f, 151 / 255.0f, 112 / 255.0f,
    64 / 255.0f,  143 / 255.0f, 255 / 255.0f, 216 / 255.0f, 178 / 255.0f,
    102 / 255.0f, 229 / 255.0f, 127 / 255.0f, 242 / 255.0f, 76 / 255.0f,
    153 / 255.0f, 76 / 255.0f,  127 / 255.0f, 51 / 255.0f,  102 / 255.0f,
    102 / 255.0f, 153 / 255.0f, 25 / 255.0f,  250 / 255.0f, 92 / 255.0f,
    74 / 255.0f,  0 / 255.0f,   129 / 255.0f, 112 / 255.0f, 209 / 255.0f,
    159 / 255.0f, 149 / 255.0f, 112 / 255.0f, 186 / 255.0f, 103 / 255.0f,
    160 / 255.0f, 57 / 255.0f,  135 / 255.0f, 87 / 255.0f,  122 / 255.0f,
    76 / 255.0f,  76 / 255.0f,  76 / 255.0f,  142 / 255.0f, 37 / 255.0f,
    189 / 255.0f, 148 / 255.0f, 92 / 255.0f,  22 / 255.0f,  58 / 255.0f,
    86 / 255.0f,  20 / 255.0f,  98 / 255.0f,  186 / 255.0f, 126 / 255.0f,
    0 / 255.0f,   0 / 255.0f,   0 / 255.0f,   67 / 255.0f,  131 / 255.0f,
    105 / 255.0f, 135 / 255.0f, 85 / 255.0f,  88 / 255.0f,  0 / 255.0f,
    135 / 255.0f, 87 / 255.0f,  80 / 255.0f,  59 / 255.0f,  34 / 255.0f,
    76 / 255.0f,  135 / 255.0f, 114 / 255.0f, 94 / 255.0f,  54 / 255.0f,
    121 / 255.0f, 67 / 255.0f,  128 / 255.0f, 40 / 255.0f,  81 / 255.0f,
    40 / 255.0f,  67 / 255.0f,  27 / 255.0f,  54 / 255.0f,  54 / 255.0f,
    81 / 255.0f,  13 / 255.0f,  132 / 255.0f, 49 / 255.0f,  39 / 255.0f,
    0 / 255.0f,   68 / 255.0f,  59 / 255.0f,  111 / 255.0f, 84 / 255.0f,
    79 / 255.0f,  59 / 255.0f,  98 / 255.0f,  55 / 255.0f,  85 / 255.0f,
    30 / 255.0f,  71 / 255.0f,  46 / 255.0f,  65 / 255.0f,  40 / 255.0f,
    40 / 255.0f,  40 / 255.0f,  75 / 255.0f,  20 / 255.0f,  100 / 255.0f,
    78 / 255.0f,  49 / 255.0f,  12 / 255.0f,  31 / 255.0f,  46 / 255.0f,
    11 / 255.0f,  52 / 255.0f,  98 / 255.0f,  67 / 255.0f,  0 / 255.0f,
    0 / 255.0f,   0 / 255.0f,   126 / 255.0f, 164 / 255.0f, 140 / 255.0f,
    0 / 255.0f,   113 / 255.0f, 118 / 255.0f, 88 / 255.0f,  180 / 255.0f,
    119 / 255.0f, 77 / 255.0f,  79 / 255.0f,  45 / 255.0f,  84 / 255.0f,
    178 / 255.0f, 90 / 255.0f,  54 / 255.0f,  108 / 255.0f, 162 / 255.0f,
    144 / 255.0f, 90 / 255.0f,  54 / 255.0f,  108 / 255.0f, 90 / 255.0f,
    44 / 255.0f,  54 / 255.0f,  54 / 255.0f,  90 / 255.0f,  36 / 255.0f,
    18 / 255.0f,  168 / 255.0f, 155 / 255.0f, 90 / 255.0f,  153 / 255.0f,
    61 / 255.0f,  1 / 255.0f,   125 / 255.0f, 58 / 255.0f,  61 / 255.0f,
    76 / 255.0f,  94 / 255.0f,  83 / 255.0f,  54 / 255.0f,  29 / 255.0f,
    76 / 255.0f,  65 / 255.0f,  52 / 255.0f,  44 / 255.0f,  35 / 255.0f,
    58 / 255.0f,  42 / 255.0f,  16 / 255.0f,  34 / 255.0f,  44 / 255.0f,
    18 / 255.0f,  89 / 255.0f,  100 / 255.0f, 31 / 255.0f,  127 / 255.0f,
    69 / 255.0f,  106 / 255.0f, 118 / 255.0f, 0 / 255.0f,   0 / 255.0f,
    0 / 255.0f,   154 / 255.0f, 201 / 255.0f, 172 / 255.0f, 0 / 255.0f,
    138 / 255.0f, 144 / 255.0f, 107 / 255.0f, 220 / 255.0f, 145 / 255.0f,
    94 / 255.0f,  97 / 255.0f,  55 / 255.0f,  103 / 255.0f, 217 / 255.0f,
    110 / 255.0f, 66 / 255.0f,  132 / 255.0f, 198 / 255.0f, 176 / 255.0f,
    110 / 255.0f, 66 / 255.0f,  132 / 255.0f, 110 / 255.0f, 54 / 255.0f,
    66 / 255.0f,  66 / 255.0f,  110 / 255.0f, 44 / 255.0f,  22 / 255.0f,
    205 / 255.0f, 189 / 255.0f, 110 / 255.0f, 187 / 255.0f, 74 / 255.0f,
    2 / 255.0f,   153 / 255.0f, 71 / 255.0f,  75 / 255.0f,  93 / 255.0f,
    115 / 255.0f, 101 / 255.0f, 66 / 255.0f,  35 / 255.0f,  92 / 255.0f,
    79 / 255.0f,  63 / 255.0f,  53 / 255.0f,  43 / 255.0f,  71 / 255.0f,
    52 / 255.0f,  19 / 255.0f,  41 / 255.0f,  54 / 255.0f,  22 / 255.0f,
    109 / 255.0f, 123 / 255.0f, 38 / 255.0f,  155 / 255.0f, 85 / 255.0f,
    129 / 255.0f, 144 / 255.0f, 0 / 255.0f,   0 / 255.0f,   0 / 255.0f,
    178 / 255.0f, 233 / 255.0f, 199 / 255.0f, 0 / 255.0f,   160 / 255.0f,
    167 / 255.0f, 124 / 255.0f, 255 / 255.0f, 168 / 255.0f, 109 / 255.0f,
    112 / 255.0f, 64 / 255.0f,  119 / 255.0f, 252 / 255.0f, 127 / 255.0f,
    76 / 255.0f,  153 / 255.0f, 229 / 255.0f, 204 / 255.0f, 127 / 255.0f,
    76 / 255.0f,  153 / 255.0f, 127 / 255.0f, 63 / 255.0f,  76 / 255.0f,
    76 / 255.0f,  127 / 255.0f, 51 / 255.0f,  25 / 255.0f,  238 / 255.0f,
    219 / 255.0f, 128 / 255.0f, 217 / 255.0f, 86 / 255.0f,  2 / 255.0f,
    177 / 255.0f, 82 / 255.0f,  87 / 255.0f,  108 / 255.0f, 133 / 255.0f,
    117 / 255.0f, 77 / 255.0f,  41 / 255.0f,  107 / 255.0f, 92 / 255.0f,
    73 / 255.0f,  62 / 255.0f,  50 / 255.0f,  82 / 255.0f,  60 / 255.0f,
    22 / 255.0f,  48 / 255.0f,  63 / 255.0f,  25 / 255.0f,  126 / 255.0f,
    142 / 255.0f, 44 / 255.0f,  180 / 255.0f, 98 / 255.0f,  150 / 255.0f,
    167 / 255.0f, 0 / 255.0f,   0 / 255.0f,   0 / 255.0f,   94 / 255.0f,
    123 / 255.0f, 105 / 255.0f, 0 / 255.0f,   85 / 255.0f,  88 / 255.0f,
    66 / 255.0f,  135 / 255.0f, 89 / 255.0f,  58 / 255.0f,  59 / 255.0f,
    34 / 255.0f,  63 / 255.0f,  133 / 255.0f, 67 / 255.0f,  40 / 255.0f,
    81 / 255.0f,  121 / 255.0f, 108 / 255.0f, 67 / 255.0f,  40 / 255.0f,
    81 / 255.0f,  67 / 255.0f,  33 / 255.0f,  40 / 255.0f,  40 / 255.0f,
    67 / 255.0f,  27 / 255.0f,  13 / 255.0f,  126 / 255.0f, 116 / 255.0f,
    68 / 255.0f,  115 / 255.0f, 46 / 255.0f,  1 / 255.0f,   94 / 255.0f,
    43 / 255.0f,  46 / 255.0f,  57 / 255.0f,  70 / 255.0f,  62 / 255.0f,
    41 / 255.0f,  22 / 255.0f,  57 / 255.0f,  49 / 255.0f,  39 / 255.0f,
    33 / 255.0f,  26 / 255.0f,  43 / 255.0f,  32 / 255.0f,  12 / 255.0f,
    25 / 255.0f,  33 / 255.0f,  13 / 255.0f,  67 / 255.0f,  75 / 255.0f,
    23 / 255.0f,  95 / 255.0f,  52 / 255.0f,  79 / 255.0f,  88 / 255.0f,
    0 / 255.0f,   0 / 255.0f,   0 / 255.0f,   40 / 255.0f,  115 / 255.0f,
    140 / 255.0f, 0 / 255.0f,   180 / 255.0f, 118 / 255.0f, 0 / 255.0f,
    180 / 255.0f, 130 / 255.0f, 54 / 255.0f,  79 / 255.0f,  180 / 255.0f,
    51 / 255.0f,  173 / 255.0f, 36 / 255.0f,  152 / 255.0f, 152 / 255.0f,
    36 / 255.0f,  18 / 255.0f,  116 / 255.0f, 54 / 255.0f,  108 / 255.0f,
    108 / 255.0f, 126 / 255.0f, 126 / 255.0f, 36 / 255.0f,  36 / 255.0f,
    36 / 255.0f,  18 / 255.0f,  54 / 255.0f,  150 / 255.0f, 180 / 255.0f,
    41 / 255.0f,  35 / 255.0f,  0 / 255.0f,   114 / 255.0f, 25 / 255.0f,
    76 / 255.0f,  97 / 255.0f,  25 / 255.0f,  37 / 255.0f,  55 / 255.0f,
    25 / 255.0f,  69 / 255.0f,  65 / 255.0f,  62 / 255.0f,  65 / 255.0f,
    25 / 255.0f,  30 / 255.0f,  32 / 255.0f,  11 / 255.0f,  35 / 255.0f,
    68 / 255.0f,  20 / 255.0f,  95 / 255.0f,  99 / 255.0f,  44 / 255.0f,
    94 / 255.0f,  69 / 255.0f,  89 / 255.0f,  105 / 255.0f, 0 / 255.0f,
    0 / 255.0f,   0 / 255.0f,   48 / 255.0f,  141 / 255.0f, 172 / 255.0f,
    0 / 255.0f,   220 / 255.0f, 144 / 255.0f, 0 / 255.0f,   220 / 255.0f,
    159 / 255.0f, 66 / 255.0f,  97 / 255.0f,  220 / 255.0f, 62 / 255.0f,
    211 / 255.0f, 44 / 255.0f,  186 / 255.0f, 186 / 255.0f, 44 / 255.0f,
    22 / 255.0f,  142 / 255.0f, 66 / 255.0f,  132 / 255.0f, 132 / 255.0f,
    154 / 255.0f, 154 / 255.0f, 44 / 255.0f,  44 / 255.0f,  44 / 255.0f,
    22 / 255.0f,  66 / 255.0f,  184 / 255.0f, 220 / 255.0f, 50 / 255.0f,
    42 / 255.0f,  0 / 255.0f,   139 / 255.0f, 31 / 255.0f,  93 / 255.0f,
    119 / 255.0f, 31 / 255.0f,  46 / 255.0f,  67 / 255.0f,  30 / 255.0f,
    85 / 255.0f,  79 / 255.0f,  76 / 255.0f,  79 / 255.0f,  30 / 255.0f,
    36 / 255.0f,  40 / 255.0f,  14 / 255.0f,  42 / 255.0f,  84 / 255.0f,
    25 / 255.0f,  116 / 255.0f, 121 / 255.0f, 53 / 255.0f,  115 / 255.0f,
    85 / 255.0f,  109 / 255.0f, 129 / 255.0f, 0 / 255.0f,   0 / 255.0f,
    0 / 255.0f,   56 / 255.0f,  163 / 255.0f, 199 / 255.0f, 0 / 255.0f,
    255 / 255.0f, 167 / 255.0f, 0 / 255.0f,   255 / 255.0f, 184 / 255.0f,
    77 / 255.0f,  112 / 255.0f, 255 / 255.0f, 72 / 255.0f,  245 / 255.0f,
    51 / 255.0f,  216 / 255.0f, 216 / 255.0f, 51 / 255.0f,  25 / 255.0f,
    165 / 255.0f, 76 / 255.0f,  153 / 255.0f, 153 / 255.0f, 178 / 255.0f,
    178 / 255.0f, 51 / 255.0f,  51 / 255.0f,  51 / 255.0f,  25 / 255.0f,
    77 / 255.0f,  213 / 255.0f, 255 / 255.0f, 58 / 255.0f,  49 / 255.0f,
    0 / 255.0f,   161 / 255.0f, 36 / 255.0f,  108 / 255.0f, 138 / 255.0f,
    36 / 255.0f,  53 / 255.0f,  78 / 255.0f,  35 / 255.0f,  98 / 255.0f,
    92 / 255.0f,  88 / 255.0f,  92 / 255.0f,  35 / 255.0f,  42 / 255.0f,
    46 / 255.0f,  16 / 255.0f,  49 / 255.0f,  97 / 255.0f,  29 / 255.0f,
    134 / 255.0f, 140 / 255.0f, 62 / 255.0f,  133 / 255.0f, 98 / 255.0f,
    126 / 255.0f, 149 / 255.0f, 0 / 255.0f,   0 / 255.0f,   0 / 255.0f,
    30 / 255.0f,  86 / 255.0f,  105 / 255.0f, 0 / 255.0f,   135 / 255.0f,
    88 / 255.0f,  0 / 255.0f,   135 / 255.0f, 97 / 255.0f,  41 / 255.0f,
    59 / 255.0f,  135 / 255.0f, 38 / 255.0f,  130 / 255.0f, 27 / 255.0f,
    114 / 255.0f, 114 / 255.0f, 27 / 255.0f,  13 / 255.0f,  87 / 255.0f,
    40 / 255.0f,  81 / 255.0f,  81 / 255.0f,  94 / 255.0f,  94 / 255.0f,
    27 / 255.0f,  27 / 255.0f,  27 / 255.0f,  13 / 255.0f,  41 / 255.0f,
    113 / 255.0f, 135 / 255.0f, 31 / 255.0f,  26 / 255.0f,  0 / 255.0f,
    85 / 255.0f,  19 / 255.0f,  57 / 255.0f,  73 / 255.0f,  19 / 255.0f,
    28 / 255.0f,  41 / 255.0f,  19 / 255.0f,  52 / 255.0f,  49 / 255.0f,
    47 / 255.0f,  49 / 255.0f,  19 / 255.0f,  22 / 255.0f,  24 / 255.0f,
    8 / 255.0f,   26 / 255.0f,  51 / 255.0f,  15 / 255.0f,  71 / 255.0f,
    74 / 255.0f,  33 / 255.0f,  70 / 255.0f,  52 / 255.0f,  67 / 255.0f,
    79 / 255.0f,  0 / 255.0f,   0 / 255.0f,

};
} // namespace SlopeCraft
