#include <iostream>

int main()
{
    int x, y;
    std::cout << "Type a number: ";
    std::cin >> x;
    std::cout << "Type a second number: ";
    std::cin >> y;
    int soma = x + y;
    std::cout << "Sum is: "; std::cout << soma;
};