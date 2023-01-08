auto square_root(long long radicand) {

    auto decreased = false;
    auto root = 1ll;

    while (true) {
        const auto approximation = (root + radicand / root) >> 1;
        if (approximation == root || (approximation > root && decreased)) {
            break;
        }
        decreased = approximation < root;
        root = approximation;
    }

    return root;

}
