// fold 15j
template <typename NumericType>
auto exponentiate(NumericType base, long long power) {

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

// fold 145j
template <int MOD>
class ModularInteger {

private:

    int value = 0;

public:

    constexpr static auto MODULO = MOD;

    ModularInteger() = default;

    explicit ModularInteger(long long initial) {

        value = initial % MODULO;

        if (value < 0) {
            value += MODULO;
        }

    }

    explicit operator auto() const {

        return static_cast<int>(value);

    }

    auto operator+() const {

        return ModularInteger(value);

    }

    auto operator-() const {

        return ModularInteger(-value);

    }

    auto operator++() {

        ++value;

        if (value == MODULO) {
            value = 0;
        }

    }

    auto operator--() {

        if (value == 0) {
            value = MODULO;
        }

        --value;

    }

    auto operator+=(const ModularInteger& other) {

        value += other.value;

        if (value >= MODULO) {
            value -= MODULO;
        }

    }

    auto operator-=(const ModularInteger& other) {

        value -= other.value;

        if (value < 0) {
            value += MODULO;
        }

    }

    auto operator*=(const ModularInteger& other) {

        value = static_cast<long long>(value) * other.value % MODULO;

    }

    auto operator/=(const ModularInteger& other) {

        *this *= exponentiate(other, MODULO - 2);

    }

    friend auto operator+(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result += rhs;

        return result;

    }

    friend auto operator-(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result -= rhs;

        return result;

    }

    friend auto operator*(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result *= rhs;

        return result;

    }

    friend auto operator/(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result /= rhs;

        return result;

    }

    friend auto operator==(const ModularInteger& lhs, const ModularInteger& rhs) {

        return lhs.value == rhs.value;

    }

    friend auto operator!=(const ModularInteger& lhs, const ModularInteger& rhs) {

        return lhs.value != rhs.value;

    }

};

// constexpr auto MODULO = 998'244'353;
// constexpr auto MODULO = 1'000'000'007;

// using Integer = ModularInteger<MODULO>;
