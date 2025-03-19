#include <iostream>

int main()
{
    float total, x;
    int many_n;
    
    std::cout << "How many numbers do you want to average the grades? ";
    std::cin >> many_n;

    while(many_n < 0)
    {
        std::cout << "Please, enter with a valid number.\n";
        std::cout << "How many numbers do you want to average the grades? Try again: ";
        std::cin >> many_n;
    }
        for(int i = 0; i < many_n; i++){
            std::cout << "Grade " << i+1 << ": ";
            std::cin >> x;
            total += x;
        }

        if(total > 7){
           std::cout << "Congratulations! You are approved!\n";
           std::cout << "Average grade is: " << total/many_n;

        } else {
            std::cout << "Unfortunately... You aren't approved.\n";
            std::cout << "Average grade is: " << total/many_n;
        }
   
        return 0;
};