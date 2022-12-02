#include <cstddef>
#include <functional>

using std::hash;
using std::size_t;

template <typename T, typename Hash = hash<typename T::value_type>>
class ContainerHash {

private:

    const Hash hash_t = Hash();

public:

    auto operator()(const T& value) const {

        auto result = 0llu;

        for (const auto& x : value) {
            result ^= hash_t(x) + 0x9e3779b97f4a7c55 + (result << 6) + (result >> 2);
        }

        return static_cast<size_t>(result);

    }

};
