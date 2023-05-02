#include "algheader.h"

size_t modexp(size_t x, size_t y, size_t N) {
    if (y == 0) return 1;
    size_t z = modexp(x, y / 2, N);
    if (y % 2 == 0)
        return (z*z) % N;
    else
        return (x*z*z) % N;
}

void generateRectangles(std::vector<Rectangle>& rectangles, int n) {
    double i = 0;
    while (i < n) {
        Rectangle rectangle;
        rectangle.start.first = 10 * i; rectangle.start.second = 10 * i;
        rectangle.end.first = 10 * (2*n - i); rectangle.end.second = 10 * (2*n - i);
        rectangles.push_back(rectangle);
        i += 1.3;
    }
}

void generatePoints(std::vector<std::pair<int, int>> &points, int n) {
    double i = 0;
    while (i < n) {
        std::pair<int, int> point;
        point.first = modexp(9973*i, 31, 20 * n);
        point.second = modexp(9967*i, 31, 20 * n);
        points.push_back(point);
        i += 1.3;
    }
}

int main() {
    std::vector<Rectangle> rectangles;
    std::vector<std::pair<int, int>> points;
    std::cout << "N\t|\tfirst\t|\tsecond_preparation second_search\t|\tthird_preparation third_search\n";
    int n = 20;
    while (n < 50000) {
        std::cout << n << "\t|\t";
        rectangles.clear();
        points.clear();

        generateRectangles(rectangles, n);
        generatePoints(points, n);

        std::cout << first(rectangles, points) << "\t|\t";
        std::pair<size_t, size_t> second_time = second(rectangles, points);
        std::cout << second_time.first << ' ' << second_time.second << "\t|\t";
        std::pair<size_t, size_t> third_time = third(rectangles, points);
        std::cout << third_time.first << ' ' << third_time.second << '\n';

        n *= 1.5;
    }

    return 0;
}
