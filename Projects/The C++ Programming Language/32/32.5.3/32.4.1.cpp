#include <iostream>
#include <vector>
#include <algorithm>

void increment_all(std::vector<int>& v) {
    // Increment each element of the vector using for_each
    std::for_each(v.begin(), v.end(), [](int& x) { ++x; });
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Use for_each to print each element
    std::for_each(numbers.begin(), numbers.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    // Use the increment_all function to increment each element
    increment_all(numbers);

    // Print the incremented elements
    std::for_each(numbers.begin(), numbers.end(), [](int x) { std::cout << x << " "; });
    std::cout << std::endl;

    return 0;
}
