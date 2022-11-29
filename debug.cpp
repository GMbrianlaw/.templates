#include <iostream>
#include <ostream>

using std::clog;
using std::endl;

template <typename T>
auto debug(T value) {

    clog << value << endl;

}

template <typename T, typename... Rest>
auto debug(T value, Rest... rest) {

    clog << value << ' ';

    debug(rest...);

}
