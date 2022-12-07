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
