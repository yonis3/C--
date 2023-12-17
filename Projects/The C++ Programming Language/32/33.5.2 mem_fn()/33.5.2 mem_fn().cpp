#include <iostream>
#include <functional>

// A function that takes three arguments
void printValues(int a, double b, std::string c) {
    std::cout << "Values: " << a << ", " << b << ", " << c << std::endl;
}

int main() {
    // Using std::bind to create a function adaptor
    auto adaptor = std::bind(printValues, 42, std::placeholders::_1, "Hello");

    // Calling the adapted function with a double argument
    adaptor(3.14);

    return 0;
}
