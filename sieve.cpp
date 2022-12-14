#include <array>
#include <vector>

using std::array;
using std::vector;

constexpr auto SIEVE_MAX = 0;

auto factors = array<int, SIEVE_MAX + 1>();
auto primes = vector<int>();

// fold 20j
auto precompute() {

    primes.reserve(SIEVE_MAX / 3 + 2);

    for (auto i = 2; i <= SIEVE_MAX; ++i) {
        if (factors[i] == 0) {
            factors[i] = i;
            primes.push_back(i);
        }
        for (auto x : primes) {
            if (static_cast<long long>(i) * x > SIEVE_MAX) {
                break;
            }
            factors[i * x] = x;
            if (x == factors[i]) {
                break;
            }
        }
    }

}

// fold 4j
auto isPrime(int number) {

    return factors[number] == number;

}
