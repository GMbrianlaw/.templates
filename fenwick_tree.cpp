#include <vector>

// fold 61j
template <typename T, typename BinaryOperation>
class FenwickTree {

private:

    const BinaryOperation combine = nullptr;
    std::vector<T> data = std::vector<T>();
    const T identity = T();
    const int size = 0;

public:

    FenwickTree(
        int size, const T& identity, BinaryOperation combine = BinaryOperation()
    ) : combine(combine), identity(identity), size(size) {

        data.assign(size, identity);

    }

    FenwickTree(
        const std::vector<T>& information, const T& identity,
        BinaryOperation combine = BinaryOperation()
    ) : FenwickTree(information.size(), identity, combine) {

        for (auto i = 0; i < static_cast<int>(information.size()); ++i) {
            update(i, information[i]);
        }

    }

    auto query(int index) {

        --index;

        auto result = identity;

        while (index >= 0) {
            result = combine(result, data[index]);
            index = (index & (index + 1)) - 1;
        }

        return result;

    }

    auto query(int left_index, int right_index) {

        return query(right_index) - query(left_index);

    }

    auto update(int index, const T& delta) {

        while (index < size) {
            data[index] = combine(data[index], delta);
            index |= index + 1;
        }

    }

};
