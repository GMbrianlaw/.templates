#include <vector>

// fold 17j
auto factorize(int number) {

    const auto bits = __builtin_ctz(number);

    auto factors = std::vector<int>(bits, 2);

    number >>= bits;

    for (auto i = 3; i * i <= number; ++i) {
        while (number % i == 0) {
            factors.push_back(i);
            number /= i;
        }
    }

    if (number > 1) {
        factors.push_back(number);
    }

    return factors;

}
