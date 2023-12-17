#include <iostream>
#include <functional>
#include <cmath>

int my_round(double x) {
    return static_cast<int>(floor(x + 0.5));
}

enum class Round_style { truncate, round };

struct Round {
    Round_style s;

    Round(Round_style ss) : s(ss) { }

    int operator()(double x) const {
        return (s == Round_style::round) ? static_cast<int>(x + 0.5) : static_cast<int>(x);
    }
};

int main() {
    // Using the provided my_round function directly
    double value = 7.8;
    int result = my_round(value);
    std::cout << "Direct my_round function result: " << result << std::endl;

    // Using std::function to hold the my_round function
    std::function<int(double)> f = my_round;
    result = f(value);
    std::cout << "std::function with my_round function result: " << result << std::endl;

    // Using the Round function object directly
    Round roundObject(Round_style::round);
    result = roundObject(value);
    std::cout << "Direct Round function object result: " << result << std::endl;

    // Using std::function to hold the Round function object
    std::function<int(double)> g = roundObject;
    result = g(value);
    std::cout << "std::function with Round function object result: " << result << std::endl;

    return 0;
}
