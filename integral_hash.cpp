#include <chrono>
#include <cstddef>

using std::chrono::steady_clock;
using std::size_t;

template <typename T>
class IntegralHash {

private:

    const long long ticks = steady_clock::now().time_since_epoch().count();

public:

    auto operator()(T value) const {

        auto result = static_cast<unsigned long long>(value);

        result += ticks + 0x9e3779b97f4a7c15;
        result = (result ^ (result >> 30)) * 0xbf58476d1ce4e5b9;
        result = (result ^ (result >> 27)) * 0x94d049bb133111eb;

        return static_cast<size_t>(result ^ (result >> 31));

    }

};

