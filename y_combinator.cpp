#include <utility>

template <typename Callable>
class YCombinator {

private:

    const Callable lambda = nullptr;

public:

    template <typename Lambda>
    explicit YCombinator(Lambda&& lambda) : lambda(lambda) {}

    template<typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return lambda(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename Lambda>
YCombinator(Lambda) -> YCombinator<Lambda>;
