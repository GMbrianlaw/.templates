#include <iostream>

using std::cin;

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

    explicit ModularInteger(long long value) : value(normalize(value)) {}

    operator auto() const {

        return value;

    }

    auto read() {

        auto input = 0ll;

        cin >> input;

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

        *this *= exponentiate(divisor, MODULO - 2);

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
