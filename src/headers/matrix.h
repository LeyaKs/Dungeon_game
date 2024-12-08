#ifndef MATRIX_H
#define MATRIX_H
#include "cell.h"
#include <vector>
#include <iterator>
#include <concepts>
#include <cassert>
#include <limits>


template </*std::default_initializable*/ typename T1>
class Vector;



template <typename T, bool is_const>
class VectorIter {
    private:
        typedef std::conditional_t<is_const, const T, T>* node_ptr_t;
        node_ptr_t node;
        VectorIter(node_ptr_t node): node(node) {};

        friend Vector<T>;
        friend VectorIter<T, !is_const>;
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;

        typedef std::conditional_t<is_const, const T, T>* pointer;
        typedef std::conditional_t<is_const, const T, T>& reference;
        // typedef std::bidirectional_iterator_tag iterator_category;

        VectorIter() noexcept: node(nullptr) {};

        template<bool other_const>
        VectorIter(VectorIter<T, other_const>& o) noexcept
            requires (is_const >= other_const): node(o.node) {};

        template<bool other_const>
        VectorIter& operator = (const VectorIter<T, other_const>& o) noexcept
            requires (is_const >= other_const) {
                node = o.node;
                return *this;
            }

        VectorIter& operator ++ () noexcept {
            node++;
            return *this;
        }

        VectorIter operator ++ (int) noexcept {
            VectorIter res(node);
            node++;
            return res;
        }
        reference operator * () const noexcept {
            return *node;
        }

        pointer operator -> () const noexcept {
            return node;
        }

        template <bool other_const>
        bool operator == (const VectorIter<T, other_const>& o) const noexcept {
            return node == o.node;
        }

        VectorIter& operator -- () noexcept {
            node--;
            return *this;
        }

        VectorIter operator -- (int) noexcept {
            VectorIter res(node);
            node--;
            return res;
        }
};





template </*std::default_initializable*/ typename T1>
class Vector {
    public:
        typedef T1 value_type;
        typedef T1& reference;
        typedef const T1& const_reference;
        typedef T1* pointer;
        typedef VectorIter<T1, false> iterator;
        typedef VectorIter<T1, true> const_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;

    private:
        pointer val;
        size_t vector_size;
        size_t capacity;

        void increase() { 
            capacity = capacity > 0 ? capacity * 2: 1; 
            pointer temp = new value_type[capacity]; 
            for (size_t i = 0; i < vector_size; ++i) { 
                temp[i] = val[i]; 
            } 
            delete[] val; 
            val = temp; 
        }

        void decrease() {
            capacity /= 2;
            pointer temp = new value_type[capacity];
            for (size_t i = 0; i < vector_size; ++i) {
                temp[i] = val[i];
            }
            delete[] val;
            val = temp;
        }
    public:

        Vector() {
            val = nullptr;
            vector_size = 0;
            capacity = 0;
        };

        size_type size() const noexcept {
            return vector_size;
        }

        size_type max_size() const noexcept {
            return std::numeric_limits<size_type>::max();
        }

        bool empty() const noexcept {
            return vector_size == 0;
        }

        void swap(Vector& o) noexcept {
            pointer temp = val;
            val = o;
            o = temp;
            std::swap(vector_size, o.vector_size);
        }


        iterator begin() noexcept {
            return iterator(val);
        }

        iterator end() noexcept {
            if (vector_size != 0)
                return iterator(val + vector_size);
            return iterator(val);
        }


        const_iterator begin() const noexcept {
            return iterator(val);
        }

        const_iterator end() const noexcept {
            if (vector_size != 0)
                return iterator(val + vector_size);
            return iterator(val);
        }

        const_iterator cbegin() const noexcept {
            return iterator(val);
        }

        const_iterator cend() const noexcept {
            if (vector_size != 0)
                return iterator(val + vector_size);
            return iterator(val);
        }


        void push_back(value_type value) {
            if (!val) {
                val = new value_type[++vector_size];
                capacity++;
                val[0] = value;
                return;
            }
            if (vector_size == capacity) {
                increase();    
            }
            val[vector_size++] = value;
        }


        void pop_back() {
            if (empty())
                return;
            if (vector_size * 2 < capacity)
                decrease();
            vector_size--;
            return;
        }

        void print_vector() {
            std::for_each(this->begin(), this->end(), [](value_type value) {
                std::cout << value << std::endl;
            });
            return;
        }


        value_type operator [] (int x) noexcept {
            if (vector_size != 0) {
                return val[x];
            }
        }
        
        ~Vector() {
            delete[] val;
        }
};



template <typename T1>
class Matrix {
    private:
        Vector<Vector<T1>> matrix;
    public:
        Matrix() = default;

        void set_matrix(const Matrix<T1>&);
        Vector<Vector<T1>> get_matrix() const;
        ~Matrix() = default;
};

template <typename T1>
void Matrix<T1>::set_matrix(const Matrix<T1>& _matrix) {
    matrix = _matrix;
}

template <typename T1>
Vector<Vector<T1>> Matrix<T1>::get_matrix() const {
    return matrix;
}
#endif