#include <iostream>

int main()
{
    int n;
    std::cout << "Type one number for a make a multiplication table: ";
    std::cin >> n;
    std::cout << "MULTIPLICATION TABLE\n";
    for (int i=0; i < 11; i++){
        std::cout << n << " x " << i << " = " << n*i << "\n";
    }
    return 0;
};