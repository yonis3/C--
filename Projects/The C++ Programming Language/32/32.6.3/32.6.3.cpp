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
    std::vector<int> set1 = {1, 2, 3, 4, 5};
    std::vector<int> set2 = {3, 4, 5, 6, 7};

    // includes
    bool includesResult = std::includes(set1.begin(), set1.end(), set2.begin(), set2.end());
    std::cout << "includes result: " << std::boolalpha << includesResult << std::endl;

    // set_union
    std::vector<int> unionResult(set1.size() + set2.size());
    auto unionEnd = std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), unionResult.begin());
    unionResult.resize(std::distance(unionResult.begin(), unionEnd));
    std::cout << "Union result: ";
    printContainer(unionResult);

    // set_intersection
    std::vector<int> intersectionResult(set1.size() + set2.size());
    auto intersectionEnd = std::set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), intersectionResult.begin());
    intersectionResult.resize(std::distance(intersectionResult.begin(), intersectionEnd));
    std::cout << "Intersection result: ";
    printContainer(intersectionResult);

    // set_difference
    std::vector<int> differenceResult(set1.size());
    auto differenceEnd = std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), differenceResult.begin());
    differenceResult.resize(std::distance(differenceResult.begin(), differenceEnd));
    std::cout << "Set difference result: ";
    printContainer(differenceResult);

    // set_symmetric_difference
    std::vector<int> symmetricDifferenceResult(set1.size() + set2.size());
    auto symmetricDifferenceEnd = std::set_symmetric_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), symmetricDifferenceResult.begin());
    symmetricDifferenceResult.resize(std::distance(symmetricDifferenceResult.begin(), symmetricDifferenceEnd));
    std::cout << "Symmetric difference result: ";
    printContainer(symmetricDifferenceResult);

    return 0;
}
