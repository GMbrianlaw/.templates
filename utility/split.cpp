#include <string>
#include <vector>

template <typename CharT>
auto split(const std::basic_string<CharT>& str, const CharT* delimiters) {

    auto reached = 0;
    const auto str_sz = static_cast<int>(str.size());
    auto tokens = std::vector<std::basic_string<CharT>>();

    while (reached < str_sz) {
        const auto position = static_cast<int>(str.find_first_of(delimiters, reached));
        if (position == static_cast<int>(std::string::npos)) {
            break;
        }
        tokens.push_back(str.substr(reached, position - reached));
        reached = position + 1;
    }

    tokens.push_back(str.substr(reached));

    return tokens;

}
