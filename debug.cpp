#include <iostream>
#include <ostream>

template <typename Type>
auto debug(Type value) {

    std::clog << value << std::endl;

}

template <typename Type, typename... Rest>
auto debug(Type value, Rest... rest) {

    std::clog << value << ' ';

    debug(rest...);

}

template <typename Type>
auto debug_container(const Type& value) {

    std::clog << '[';

    const auto value_sz = static_cast<int>(value.size());

    for (auto i = 0; i < value_sz; ++i) {
        std::clog << value[i];
        if (i < value_sz - 1) {
            std::clog << ", ";
        }
    }

    std::clog << ']' << std::endl;

}
