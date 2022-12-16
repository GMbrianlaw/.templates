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

// fold 141j
template <int MOD>
class ModularInteger {

private:

    static auto normalize(int value) {

        value %= MODULO;

        if (value < 0) {
            value += MODULO;
        } else if (value >= MODULO) {
            value -= MODULO;
        }

        return value;

    }

    int value = 0;

public:

    constexpr static auto MODULO = MOD;

    ModularInteger() {}

    explicit ModularInteger(long long value) {

        assign(value);

    }

    operator auto() const {

        return static_cast<long long>(value);

    }

    auto assign(long long input) {

        value = normalize(input);

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

    auto operator+=(long long addend) {

        value = normalize(value + addend);

    }

    auto operator-=(long long subtrahend) {

        value = normalize(value - subtrahend);

    }

    auto operator*=(long long factor) {

        value = normalize(value * factor);

    }

    auto operator/=(long long divisor) {

        *this *= exponentiate(ModularInteger(divisor), MODULO - 2);

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

        lhs *= rhs;

        return result;

    }

    friend auto operator/(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result /= rhs;

        return result;

    }

};
