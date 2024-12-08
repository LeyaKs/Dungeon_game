#include <iostream>
#include "headers/matrix.h"


int main() {
    Vector<int> a = {};
    a.push_back(17);
    a.push_back(127);
    a.print_vector();
    a.pop_back();
    a.print_vector();
    static_assert(std::bidirectional_iterator<VectorIter<int, false>>);
    static_assert(std::bidirectional_iterator<VectorIter<int, true>>);
    std::cout<<"hi"<<std::endl;
}