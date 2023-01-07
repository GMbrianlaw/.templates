// fold 15j
template <typename IntegralType>
constexpr auto exponentiate(IntegralType base, long long power) {

    auto result = IntegralType(1);

    while (power) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }

    return result;

}
