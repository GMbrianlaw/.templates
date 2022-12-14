#include <array>
#include <vector>

using std::array;
using std::vector;

constexpr auto SIEVE_MAX = 0;

// fold 20j
auto precompute() {

    auto factors = array<int, SIEVE_MAX + 1>();
    auto primes = vector<int>();

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
