#include <iostream>

int main()
{
    int x;
    std::cout << "Type a number: ";
    std::cin >> x;
    if (x % 2 == 1){
        std::cout << "Odd number";
    } else {
        std::cout << "Even number";
    }
};