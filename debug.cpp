#include <iostream>
#include <ostream>

using std::cout;
using std::flush;

template <typename T>
auto debug(T value) {

    cout << value << '\n' << flush;

}

template <typename T, typename... Rest>
auto debug(T value, Rest... rest) {

    cout << value << ' ' << flush;

    debug(rest...);

}
