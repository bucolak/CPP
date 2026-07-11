#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
    private:
        unsigned int maxInt;
        std::vector<int> nums;
    public:
        Span();
        Span(unsigned int maxInt);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();

        void addNumber(int n);
        int shortestSpan();
        int longestSpan();

        template <typename T>
        void addNumbers(T begin, T end)
        {

        }
};

#endif