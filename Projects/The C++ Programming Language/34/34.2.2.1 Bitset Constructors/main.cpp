#include <bitset>
#include <iostream>
#include <stdexcept>

using namespace std;

int main() {
    // Default constructor: Creates a bitset with all bits set to 0
    bitset<10> b1;
    cout << "b1 (Default Constructor): " << b1 << endl;

    // Constructor from unsigned long long int: Initializes bits using the provided integer
    bitset<16> b2 = 0xaaaa; // 1010101010101010
    cout << "b2 (Constructor from ULL): " << b2 << endl;

    bitset<32> b3 = 0xaaaa; // 00000000000000001010101010101010
    cout << "b3 (Constructor from ULL): " << b3 << endl;

    // Constructor from a basic string: Initializes bits based on '0' and '1' characters in the string
    bitset<10> b4{"1010101010"}; // 1010101010
    cout << "b4 (Constructor from String): " << b4 << endl;

    // Constructor from a substring of a basic string
    bitset<10> b5{"10110111011110", 4}; // 0111011110
    cout << "b5 (Constructor from Substring): " << b5 << endl;

    // Constructor from a basic string object
    bitset<10> b6{string{"1010101010"}}; // 1010101010
    cout << "b6 (Constructor from String Object): " << b6 << endl;

    // Constructor from a substring of a basic string object
    bitset<10> b7{string{"10110111011110"}, 4}; // 0111011110
    cout << "b7 (Constructor from Substring Object): " << b7 << endl;

    // Constructor from a substring with custom characters for zero and one
    bitset<10> b8{string{"10110111011110"}, 2, 8}; // 0011011101
    cout << "b8 (Constructor with Custom Characters): " << b8 << endl;

    // Constructor from a basic string (invalid_argument exception)
    try {
        bitset<10> b9{string{"n0g00d"}};
    } catch (const invalid_argument& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}
