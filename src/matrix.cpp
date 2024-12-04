#include "headers/matrix.h"

void Matrix::set_matrix(std::vector<std::vector<Cell>> _matrix) {
    matrix = _matrix;
}
std::vector<std::vector<Cell>> Matrix::get_matrix() const {
    return matrix;
}