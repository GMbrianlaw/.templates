#include <chrono>
#include <cstddef>

using std::chrono::steady_clock;
using std::size_t;

template <typename T>
class IntegralHash {

public:

    auto operator()(T value) const {

        static const unsigned long long constant = steady_clock::now().time_since_epoch().count();

        auto result = static_cast<unsigned long long>(value);

        result += constant + 0x9e3779b97f4a7c15;
        result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
        result = (result ^ (result >> 27)) * 0x94d049bb133111eb;
        result = result ^ (result >> 31);

        return static_cast<size_t>(result);

    }

};
