#include <string>
#include <vector>

using std::string;
using std::vector;

auto split(const string& str, const char* delimiters) {

    auto reached = 0;
    const auto str_sz = static_cast<int>(str.size());
    auto tokens = vector<string>();

    while (reached < str_sz) {
        const auto position = static_cast<int>(str.find_first_of(delimiters, reached));
        if (position == static_cast<int>(string::npos)) {
            break;
        }
        tokens.push_back(str.substr(reached, position - reached));
        reached = position + 1;
    }

    tokens.push_back(str.substr(reached));

    return tokens;

}
