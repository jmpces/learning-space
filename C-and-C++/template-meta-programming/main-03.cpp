#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <array>
#include <iterator>
#include <vector>

#include <Eigen/Core>

namespace Layer {
    template <typename T, size_t InputNodes, size_t OutputNodes = 0>
    struct Dense {
        Eigen::Matrix<T, OutputNodes, InputNodes> weights;
        Eigen::Matrix<T, InputNodes, 1> nodes;

        Dense () : weights(), nodes() {
            static_assert(InputNodes > 0, "Input node needs to be greater than zero");
            nodes.setZero();

            if constexpr (OutputNodes != 0) {
                weights.setZero();
            }
        }

        void setNodes(std::array<T, InputNodes> const& node_values) {
            for (size_t i = 0; i < InputNodes; ++i) {
                nodes << node_values[i];
            }
        }

        void setWeights(std::initializer_list<std::initializer_list<T>> weight_values) {
            for (auto &rows: weight_values) {
                for (auto values: rows) {
                    weights << values;
                }
            }
        }

        template<size_t OutputLayerOutSize>
        void forward(Dense<T, OutputNodes, OutputLayerOutSize> &output_layer) const {
            static_assert(OutputNodes > 0, "forward with invalid dimension : `OutputNodes` is 0, this is an output layer");
            output_layer.nodes.noalias() = weights * nodes;
        }

        inline T &operator[](size_t i) {
            return nodes(i, 0);
        }

        inline const T &operator[](size_t i) const {
            return nodes(i, 0);
        }

        void print() const {
            std::cerr << "--------------------------\n";
            std::cerr << "nodes (bytes : " << sizeof(nodes) << ") = \n" << nodes;

            if constexpr (OutputNodes != 0) {
                std::cerr << "\n\nweights (bytes : " << sizeof(weights) << ") = \n" << weights;
            }

            std::cerr << "\n\n";
        }
    };
}

int main() {
    Layer::Dense<int, 3, 2> input;
    Layer::Dense<int, 2, 1> hidden;
    Layer::Dense<int, 1, 0> output;

    input.setNodes({3, 5, 7});
    input.setWeights({
        {1, 2, 3},
        {4, 5, 6}
    });

    input.forward(hidden);
    hidden.forward(output);

    input.print();
    hidden.print();
    output.print();

    return 0;
}
