#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    // Sample vector of integers
    std::vector<int> numbers = {5, 2, 8, 3, 1, 7, 4, 6};

    // Using function objects for sorting
    std::sort(numbers.begin(), numbers.end());  // Sorting in ascending order
    std::cout << "Ascending Order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    std::sort(numbers.begin(), numbers.end(), std::greater<int>{});  // Sorting in descending order
    std::cout << "Descending Order: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    // Using function objects for comparisons
    int a = 5, b = 3;

    std::cout << "Equal: " << std::equal_to<int>{}(a, b) << "\n";
    std::cout << "Not Equal: " << std::not_equal_to<int>{}(a, b) << "\n";
    std::cout << "Greater: " << std::greater<int>{}(a, b) << "\n";
    std::cout << "Less: " << std::less<int>{}(a, b) << "\n";

    // Using function objects for arithmetic operations
    int x = 8, y = 3;

    std::cout << "Sum: " << std::plus<int>{}(x, y) << "\n";
    std::cout << "Difference: " << std::minus<int>{}(x, y) << "\n";
    std::cout << "Product: " << std::multiplies<int>{}(x, y) << "\n";
    std::cout << "Quotient: " << std::divides<int>{}(x, y) << "\n";

    return 0;
}
