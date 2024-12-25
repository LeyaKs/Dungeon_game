/**
    * \file
    * \brief Header file with description of functions of template class matrix, vector and iterator
*/
#ifndef MATRIX_H
#define MATRIX_H
#include "cell.h"
#include <vector>
#include <iostream>
#include <iterator>
#include <concepts>
#include <cassert>
#include <limits>
#include "cell.h"
#include "point.h"


template </*std::default_initializable*/ typename T1>
class Vector;


/**
    * \class VectorIter
    * \brief template class VectorIter
    * 
    * Contains pointer and reference to the stored type, constructors and functions
*/
template <typename T, bool is_const>
class VectorIter {
    private:
        typedef std::conditional_t<is_const, const T, T>* node_ptr_t;
        node_ptr_t node;
  
        friend Vector<T>;
        friend VectorIter<T, !is_const>;

        VectorIter(node_ptr_t node): node(node) {};
    public:
        typedef ptrdiff_t difference_type;
        typedef T value_type;

        typedef std::conditional_t<is_const, const value_type, value_type>* pointer;
        typedef std::conditional_t<is_const, const T, T>& reference;
        // typedef std::bidirectional_iterator_tag iterator_category;
        typedef std::random_access_iterator_tag iterator_category;

        VectorIter() noexcept: node(nullptr) {};
        


        template<bool other_const>
        VectorIter(VectorIter<T, other_const>& o) noexcept
            requires (is_const >= other_const): node(o.node) {};

        /**
            * \brief template operator = 
            * \param other iterator
            * \return reference to iterator
        */        
        template<bool other_const>
        VectorIter& operator = (const VectorIter<T, other_const>& o) noexcept
            requires (is_const >= other_const) {
                node = o.node;
                return *this;
            }


        /**
            * \brief prefix operator ++ for increasing by 1
            * \return reference to iterator
        */      
        VectorIter& operator ++ () noexcept {
            node++;
            return *this;
        }

        /**
            * \brief postfix operator ++ for increasing by 1
            * \return cope of iterator
        */      
        VectorIter operator ++ (int) noexcept {
            VectorIter res(node);
            node++;
            return res;
        }


        /**
            * \brief operator * for dereferencing
            * \return reference to iterator
        */      
        reference operator * () const noexcept {
            return *node;
        }


        /**
            * \brief operator -> for getting access
            * \return pointer to iterator
        */      
        pointer operator -> () const noexcept {
            return node;
        }


        /**
            * \brief template operator == for comparing 
            * \param other iterator
            * \return bool value
        */    
        template <bool other_const>
        bool operator == (const VectorIter<T, other_const>& o) const noexcept {
            return node == o.node;
        }


        /**
            * \brief prefix operator -- for decreasing by 1
            * \return reference to iterator
        */   
        VectorIter& operator -- () noexcept {
            node--;
            return *this;
        }

        /**
            * \brief postfix operator -- for decreasing by 1
            * \return cope of iterator
        */      
        VectorIter operator -- (int) noexcept {
            VectorIter res(node);
            node--;
            return res;
        }

        

        reference operator [] (unsigned int index) const {
            return *(node + index);
        }

        
        VectorIter& operator -= (difference_type n) {
            node -= n;
            return *this;
        }

        VectorIter operator - (difference_type n) const{
            return VectorIter(node - n);
        }

   
        difference_type operator - (const VectorIter& other) const {
            return node - other.node;
        }

        VectorIter operator + (difference_type n) const {
        return VectorIter(node + n);
        }

        friend VectorIter operator + (difference_type n, const VectorIter<T, is_const>& other) {
            return VectorIter(other + n);
        }

        VectorIter& operator += (difference_type n) {
            node += n;
            return *this;
        }

        bool operator < (const VectorIter& other) const {
            return node < other.node;
        }

        bool operator > (const VectorIter& other) const {
            return node > other.node;
        }

        bool operator <= (const VectorIter& other) const {
            return node <= *other.node;
        }

        bool operator >= (const VectorIter& other) const {
            return node >= other.node;
        }

};



/**
    * \class Vector
    * \brief template class Vector
    * 
    * Contains pointer to dynamic array, size and capacity fields, constructors and functions
*/
template <typename T1>
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

    
        pointer val;
        size_t vector_size;
        size_t capacity;

        /**
            * \brief increasing capacity
        */                
        void increase() { 
            capacity = capacity > 0 ? capacity * 2: 1; 
            pointer temp = new value_type[capacity]; 
            for (size_t i = 0; i < vector_size; ++i) { 
                temp[i] = val[i]; 
            } 
            delete[] val; 
            val = temp; 
        }


        /**
            * \brief decreasing capacity
        */ 
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
            // std::cout <<"CONSTRUCTOR 1" << std::endl;
            val = nullptr;
            vector_size = 0;
            capacity = 0;
        };

        Vector(unsigned _size) {
            // std::cout <<"CONSTRUCTOR 2" << "size" << _size << std::endl;
            val = new value_type[_size];
            vector_size = _size;
            capacity = _size;
        };


        Vector(const Vector& other) : vector_size(other.vector_size), capacity(other.vector_size) {
            val = new T1[capacity];
            for (unsigned i = 0; i < vector_size; ++i) {
                val[i] = other.val[i];
            }
        }


        /**
            * \brief Getting size of vector
            * \return dsize
        */
        size_type size() const noexcept {
            return vector_size;
        }



        /**
            * \brief Getting max size of vector
            * \return maximum
        */
        size_type max_size() const noexcept {
            return std::numeric_limits<size_type>::max();
        }


        /**
            * \brief checking if the vector is empty
            * \return bool value
        */
        bool empty() const noexcept {
            return vector_size == 0;
        }


        /**
            * \brief swapping vectors
            * \param other vector
        */
        void swap(Vector& other) noexcept {
            std::swap(val, other.val);
            std::swap(vector_size, other.vector_size);
            std::swap(capacity, other.capacity);
        }


        /**
            * \brief getting begin of the vector 
            * \param iterator
        */
        iterator begin() noexcept {
            return iterator(val);
        }



        /**
            * \brief getting end of the vector 
            * \param iterator
        */
        iterator end() noexcept {
            if (vector_size != 0)
                return iterator(val + vector_size);
            return iterator(val);
        }

        /**
            * \brief getting begin of the vector for const iterator
            * \param iterator
        */
        const_iterator begin() const noexcept {
            return const_iterator(val);
        }



        /**
            * \brief getting end of the vector for const iterator
            * \param iterator
        */
        const_iterator end() const noexcept {
            if (vector_size != 0)
                return iterator(val + vector_size);
            return const_iterator(val);
        }

        /**
            * \brief adding element to the vector
            * \param value
        */
        void push_back(reference value) {
            if (vector_size == capacity) {
                increase();
            }
            val[vector_size++] = value;
        }

        /**
            * \brief adding element to the vector
            * \param value
        */
        void push_back(value_type&& value) {
            if (vector_size == capacity) {
                increase();
            }
            val[vector_size++] = std::move(value);
        }

        /**
            * \brief removing element from the vector
        */
        void remove() {
            if (empty())
                return;
            if (vector_size * 2 < capacity)
                decrease();
            vector_size--;
            return;
        }



        /**
            * \brief printing vector
        */
        void print_vector() {
            for (int i = 0; i < size(); ++i) {
                std::cout << val[i] << std::endl;
            }
            // std::for_each(this->begin(), this->end(), [](value_type value) {
            //     std::cout << value << std::endl;
            // });
        }


        /**
            * \brief operator [] for getting access by index
            * \param index
            * \return value
        */    
        T1 operator [] (unsigned x) const{
            // std::cout << "[] VECTOR " << &val << " " << x << std::endl;
            return val[x];
        }
        T1& operator [] (unsigned x) {
            // std::cout << "[] VECTOR " << &val << " " << x << std::endl;
            return val[x];
        }

        // const T1& operator[](unsigned index) const {
       
        //     return val[index];
        // }

        Vector& operator=(const Vector& other) {
            if (this != &other) {
                vector_size = other.vector_size;
                capacity = other.capacity;
                val = new T1[capacity];
                for (size_t i = 0; i < vector_size; ++i) {
                    val[i] = other.val[i];
                }
            }
            return *this;
        }
        
        ~Vector() {
            delete[] val;
        }
};


/**
    * \class Matrix
    * \brief template class Matrix
    * 
    * Contains matrix, constructors and functions
*/
template <typename T1>
class Matrix {
    public:
        Vector<Vector<T1>> matrix;


        Matrix() {};
        Matrix(unsigned int width, unsigned int lenght) {

            matrix.capacity = width;
            matrix.vector_size = width;

            matrix = Vector<Vector<T1>>(width);
            
            for (unsigned int i = 0; i < width; ++i) {
                matrix[i] = Vector<T1>(lenght);
            }

        }
        
        Matrix(const Matrix& other) : matrix(other.matrix) {}

        Matrix& operator=(const Matrix& other) {
            matrix = other.matrix;
            return *this;
        }
        
        Vector<T1>& operator [](int x) {
            return matrix[x];
        }


        ~Matrix() {
        };
};


#endif