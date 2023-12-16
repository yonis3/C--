#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> vi = {1, 2, 3};

    // Using insert_iterator to insert at a specific position
    std::insert_iterator<std::vector<int>> insertIt(vi, vi.begin() + 1);
    *insertIt = 99;  // Inserts 99 before the element at vi.begin() + 1

    // Using back_insert_iterator to insert at the end
    std::back_insert_iterator<std::vector<int>> backInsertIt(vi);
    *backInsertIt = 42;  // Inserts 42 at the end

    // Using front_insert_iterator to insert at the beginning
    std::front_insert_iterator<std::vector<int>> frontInsertIt(vi);
    *frontInsertIt = 100;  // Inserts 100 at the beginning

    // Output the modified vector
    for (const auto& elem : vi) {
        std::cout << elem << " ";
    }

    return 0;
}
