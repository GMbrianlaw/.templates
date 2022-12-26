#include <string>
#include <vector>

template <typename CharT>
auto prefixFunction(std::basic_string<CharT> str) {

    const auto n = static_cast<int>(str.size());

    auto prefixes = std::vector<int>(n);

    for (auto i = 1; i < n; ++i) {
        auto previous = prefixes[i - 1];
        while (previous && str[previous] != str[i]) {
            previous = prefixes[previous - 1];
        }
        previous += str[previous] == str[i];
        prefixes[i] = previous;
    }

    return prefixes;

}
