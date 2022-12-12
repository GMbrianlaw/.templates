#include <utility>

template <typename FunctionObject>
class YCombinator {

private:

    const FunctionObject function = nullptr;

public:

    template <typename Lambda>
    explicit YCombinator(Lambda&& lambda) : function(lambda) {}

    template <typename... Arguments>
    decltype(auto) operator()(Arguments&&... arguments) const {

        return function(*this, std::forward<Arguments>(arguments)...);

    }

};

template <typename Lambda>
YCombinator(Lambda) -> YCombinator<Lambda>;
