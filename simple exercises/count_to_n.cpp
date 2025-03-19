#include <iostream>

int main()
{
    int n;
    std::cout << "Type one a number for a counting: ";
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::cout << i + 1 << "\n";
    }
};