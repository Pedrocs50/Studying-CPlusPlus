#include <iostream>

int main(){
    std::cout << "PRINTER OF FACTORIAL NUMBERS\n";
    std::cout << "Enter with a number: ";
    int n;
    std::cin >> n;

    int factorial = 1;
    for (int i=1; i <= n; i++){
        factorial *= i;
    }
    std::cout << "Factorial of " << n << " is " << factorial << "." << std::endl;
    return 0;
};