template <typename NumericType>
constexpr auto exponentiate(NumericType base, long long power) {

    auto result = NumericType(1);

    while (power) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }

    return result;

}
