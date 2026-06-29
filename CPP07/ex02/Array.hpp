#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array
{
    private:
        T *arr;
        unsigned int size_of_arr;
    public:
        Array()
        {
            arr = new T;
        }
        Array(unsigned int n)
        {
            size_of_arr = n;
            arr = new[size_of_arr] T;
        }
        Array(const Array &other)
        {
            T *p = arr;
            other.arr = p;
        }
        Array& operator=(const Array& other)
        {
            T *p = arr;
            other.arr = p;
        }
        ~Array()
        {
            delete[] arr;
        }

        const T& operator[](unsigned int i) const
        {
            return arr[i];
        }
        unsigned int size() const
        {
            return size_of_arr;
        }
};

#endif