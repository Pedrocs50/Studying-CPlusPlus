#include <iostream>

int main()
{
    int x, y, z;
    std::cout << "Enter with a 1° number: ";
    std::cin >> x;
    std::cout << "Enter with a 1° number: ";
    std::cin >> y;
    std::cout << "Enter with a 1° number: ";
    std::cin >> z;

    if (x >= y && x >= z) {
        std::cout << "The first number is the largest number.";
    } else if (y >= x && y >= z) {
        std::cout << "The second number is the largest number.";
    } else {
        std::cout << "The third number is the largest number.";
    }

    return 0;

};