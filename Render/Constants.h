#pragma once
#include <cstdint>


constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

constexpr uint32_t alpha = 255;
constexpr uint32_t red = 255;
constexpr uint32_t green = 255;
constexpr uint32_t blue = 255;
constexpr uint32_t white = (alpha << 24) | (red << 16) | (green << 8) | blue;
constexpr uint32_t black_red = 0;
constexpr uint32_t black_green = 0;
constexpr uint32_t black_blue = 0;
constexpr uint32_t black =  (alpha << 24) | (black_red << 16) | (black_green << 8) | black_blue;