#ifndef MATRIX_H
#define MATRIX_H
#include "cell.h"
#include <vector>

// template <typename T>
class Matrix {
    private:
        std::vector<std::vector<Cell>> matrix;
    public:
        Matrix() = default;

        void set_matrix(const std::vector<std::vector<Cell>>&);
        std::vector<std::vector<Cell>> get_matrix() const;
        ~Matrix() = default;
};

#endif