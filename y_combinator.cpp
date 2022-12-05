#include <utility>

template <typename T>
class YCombinator {

private:

    const T lambda = nullptr;

public:

    template <typename U>
    explicit YCombinator(U&& lambda) : lambda(lambda) {}

    template<typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return lambda(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename T>
YCombinator(T) -> YCombinator<T>;
