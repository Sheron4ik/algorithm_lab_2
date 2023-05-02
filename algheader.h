#ifndef LAB2_ALGHEADER_H
#define LAB2_ALGHEADER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <chrono>

struct Rectangle {
    std::pair<int, int> start, end;
};

size_t first(std::vector<Rectangle> &rectangles, std::vector<std::pair<int, int>> &points);

std::pair<size_t, size_t> second(std::vector<Rectangle> &rectangles, std::vector<std::pair<int, int>> &points);

std::pair<size_t, size_t> third(std::vector<Rectangle> &rectangles, std::vector<std::pair<int, int>> &points);

#endif //LAB2_ALGHEADER_H
