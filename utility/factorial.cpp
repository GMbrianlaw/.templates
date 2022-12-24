// fold 11j
template <typename IntegralType>
auto factorial(int n) {

    auto result = IntegralType(1);

    for (auto i = 2; i <= n; ++i) {
        result *= IntegralType(i);
    }

    return result;

}
