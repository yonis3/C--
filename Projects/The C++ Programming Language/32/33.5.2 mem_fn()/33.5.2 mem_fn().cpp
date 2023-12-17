#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

class Shape {
public:
    void draw() const {
        std::cout << "Drawing a shape\n";
    }
};

void draw_all(const std::vector<Shape*>& shapes) {
    std::for_each(shapes.begin(), shapes.end(), std::mem_fn(&Shape::draw));
}

int main() {
    std::vector<Shape*> shapes = {new Shape(), new Shape(), new Shape()};
    draw_all(shapes);

    // Don't forget to clean up the dynamically allocated objects
    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}
