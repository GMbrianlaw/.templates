#include <iostream>
#include <ostream>

template <typename T>
auto debug(T value) {

    std::clog << value << std::endl;

}

template <typename T, typename... Rest>
auto debug(T value, Rest... rest) {

    std::clog << value << ' ';

    debug(rest...);

}
