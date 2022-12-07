#include <iostream>

template <typename Base>
auto exponentiate(Base base, long long power) {

    auto result = Base(1);

    while (power) {
        if (power & 1) {
            result *= base;
        }
        base *= base;
        power >>= 1;
    }

    return result;

}

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

    auto assign() {

        auto input = 0ll;

        std::cin >> input;

        assign(input);

    }

    auto assign(long long input) {

        value = normalize(input);

    }

    constexpr auto operator+() const {

        return ModularInteger(value);

    }

    constexpr auto operator-() const {

        return ModularInteger(-value);

    }

    constexpr auto operator++() {

        ++value;

        if (value == MODULO) {
            value = 0;
        }

    }

    constexpr auto operator--() {

        if (value == 0) {
            value = MODULO;
        }

        --value;

    }

    constexpr auto operator+=(long long addend) {

        value = normalize(value + addend);

    }

    constexpr auto operator-=(long long subtrahend) {

        value = normalize(value - subtrahend);

    }

    constexpr auto operator*=(long long factor) {

        value = normalize(value * factor);

    }

    constexpr auto operator/=(long long divisor) {

        *this *= exponentiate(ModularInteger(divisor), MODULO - 2);

    }

    friend constexpr auto operator+(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result += rhs;

        return result;

    }

    friend constexpr auto operator-(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result -= rhs;

        return result;

    }

    friend constexpr auto operator*(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        lhs *= rhs;

        return result;

    }

    friend constexpr auto operator/(const ModularInteger& lhs, const ModularInteger& rhs) {

        auto result = lhs;

        result /= rhs;

        return result;

    }

};
