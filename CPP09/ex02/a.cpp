#include <iostream>

void say(int n)
{
    if (n == 0)
        return;

    say(n - 1);
    std::cout << n << std::endl;
}

int main()
{
    say(3);
}