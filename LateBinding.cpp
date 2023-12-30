// LateBinding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>

int add(int x, int y)
{
    return x + y;
}

int substract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
    return x * y;
}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    int op{};
    do
    {
        std::cout << "Enter an operation (0=add,1=substract and 2=multiply): ";
        std::cin >> op;
    } while (op < 0 || op>2);

    int (*pFuncptr)(int, int) { nullptr };
    switch (op)
    {
    case 0:
        pFuncptr = add;
        break;
    case 1:
        pFuncptr = substract;
        break;
    case 2:
        pFuncptr = multiply;
        break;
    }

    std::cout << "The answer is: " << pFuncptr(x,y) << '\n';
 
    return 0;
}


