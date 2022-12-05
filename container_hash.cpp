#include <cstddef>
#include <functional>

template <typename T, typename Hash = std::hash<typename T::value_type>>
class ContainerHash {

private:

    static const auto hash_t = Hash();

public:

    auto operator()(const T& value) const {

        auto result = 0llu;

        for (const auto& x : value) {
            result ^= hash_t(x) + 0x9e3779b97f4a7c15 + (result << 6) + (result >> 2);
        }

        return static_cast<std::size_t>(result);

    }

};
