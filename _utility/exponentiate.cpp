template <typename T>
auto exponentiate(T base, long long power) {

    auto result = T(1);

    while (power) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }

    return result;

}
