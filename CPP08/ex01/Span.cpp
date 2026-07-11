#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int maxInt)
{
    this->maxInt = maxInt;
}

Span::Span(const Span& other)
{
    this->maxInt = other.maxInt;
    this->nums = other.nums;
}

Span& Span::operator=(const Span& other)
{
    if(this != &other)
    {
        this->maxInt = other.maxInt;
        this->nums = other.nums;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
    if(nums.size() > maxInt)
        throw "Capacity is full!";
    nums.push_back(n);
}

int Span::shortestSpan()
{
    if(nums.size() < 2)
        throw "No enough number!";
    std::vector<int> tmp = nums;
    std::sort(tmp.begin(), tmp.end());
    int min = nums[1] - nums[0];
    for(int i = 0; i < tmp.size() - 1; i++)
    {
        if(tmp[i+1] && (tmp[i+1] - tmp[i])<min)
        {
            min = tmp[i+1] - tmp[i];
        }
    }
    return min;
}