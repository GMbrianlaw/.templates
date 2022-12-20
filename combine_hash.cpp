#include <cstddef>
#include <functional>

template <typename T, typename Hash = std::hash<T>>
auto combine_hash(const T& value, std::size_t seed) {

    seed ^= Hash()(value) + 0x9e3779b9 + (seed << 6) + (seed >> 2);

    return seed;

}
