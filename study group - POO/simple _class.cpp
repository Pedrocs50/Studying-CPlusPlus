#include <iostream>

class Base
{
    public:
    void method()
    {
        std::cout << "I am a Base method.";
    }
};


class Derivative: public Base
{
    public:
    void method()
    {
        std::cout << "I am a Derivative method.";
    }
};


int main()
{
    Base *baseObject = new Base();

    baseObject->method();

    return 0;
};