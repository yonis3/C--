#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void printContainer(const T& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Initialize a vector
    std::vector<int> numbers = {1, 2, 3, 4, 2, 5, 2, 6};

    // Remove elements with value 2 using remove
    auto removeEnd = std::remove(numbers.begin(), numbers.end(), 2);
    printContainer(numbers);

    // Remove elements satisfying a condition using remove_if
    auto removeIfEnd = std::remove_if(numbers.begin(), numbers.end(),
                                      [](int x) { return x % 2 == 0; });
    printContainer(numbers);

    // Remove and copy elements with value 2 using remove_copy
    std::vector<int> removedCopy(numbers.size());
    auto removeCopyEnd = std::remove_copy(numbers.begin(), numbers.end(),
                                          removedCopy.begin(), 2);
    printContainer(removedCopy);

    // Remove and copy elements satisfying a condition using remove_copy_if
    std::vector<int> removedCopyIf(numbers.size());
    auto removeCopyIfEnd = std::remove_copy_if(numbers.begin(), numbers.end(),
                                               removedCopyIf.begin(),
                                               [](int x) { return x % 2 == 0; });
    printContainer(removedCopyIf);

    // Reverse the order of elements using reverse
    std::reverse(numbers.begin(), numbers.end());
    printContainer(numbers);

    // Copy and reverse the order of elements using reverse_copy
    std::vector<int> reverseCopy(numbers.size());
    auto reverseCopyEnd = std::reverse_copy(numbers.begin(), numbers.end(),
                                            reverseCopy.begin());
    printContainer(reverseCopy);

    return 0;
}
