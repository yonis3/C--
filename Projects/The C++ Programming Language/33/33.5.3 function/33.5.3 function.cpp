#include <iostream>
#include <functional>

int add(int a, int b) {
    return a + b;
}

int main() {
    auto boundAdd = std::bind(add, 10, std::placeholders::_1);
    std::function<int(int)> boundFunction = boundAdd;

    int result = boundFunction(5);

    std::cout << "Result: " << result << std::endl;

    return 0;
}
