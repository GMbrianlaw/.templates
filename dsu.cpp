#include <numeric>
#include <utility>
#include <vector>

// fold 48j
class DisjointSetUnion {

private:

    std::vector<int> parents = std::vector<int>();
    std::vector<int> sizes = std::vector<int>();

public:

    explicit DisjointSetUnion(int size) {

        parents.resize(size);

        std::iota(parents.begin(), parents.end(), 0);

        sizes.assign(size, 1);

    }

    auto find(int node) {

        auto& parent = parents[node];

        if (parent == node) {
            return node;
        }

        parent = find(parent);

        return parent;

    }

    auto merge(int node_1, int node_2) {

        node_1 = find(node_1);
        node_2 = find(node_2);

        if (node_1 != node_2) {
            if (sizes[node_1] < sizes[node_2]) {
                std::swap(node_1, node_2);
            }
            parents[node_2] = node_1;
            sizes[node_1] += sizes[node_2];
        }

    }

};
