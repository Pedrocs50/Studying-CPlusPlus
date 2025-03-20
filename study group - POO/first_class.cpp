#include <iostream>

struct Base
{
    Base() { std::cout<<"contrutor Base\n"; }
    virtual void teste() { std::cout<<"teste Base\n"; }
    ~Base() { std::cout<<"destruidor Base\n"; }
};

struct Derivada_1: public Base
{
    Derivada_1() { std::cout<<"contrutor Derivada 1\n"; }
    void teste() { std::cout<<"teste Derivada 1\n"; }
    ~Derivada_1() { std::cout<<"destruidor Derivada 1\n"; }
};

struct Derivada_2: public Base
{
    Derivada_2() { std::cout<<"contrutor Derivada 2\n"; }
    void teste() { std::cout<<"teste Derivada 2\n"; }
    ~Derivada_2() { std::cout<<"destruidor Derivada 2\n"; }
};

struct Componente
{
    Base* criaObjeto(int escolha)
    {
        if(escolha == 1)
        { return new Derivada_1(); }
        else if(escolha == 2)
        { return new Derivada_2(); }
        else
        { return NULL; }
    }
};

int main()
{
    Componente comp;
    int opcao;
    std::cout<<"Ecolha uma opcao\n";
    std::cout<<"1: Botao 1\n2: Botao 2\n0: Sair\n";
    std::cin>>opcao;
    while(opcao != 0)
    {
        Base* b = comp.criaObjeto(opcao);
        std::cout<<"b->teste(): ";
        b->teste();
        std::cout<<"Ecolha uma opcao\n";
        std::cout<<"1: Botao 1\n2: Botao 2\n0: Sair\n";
        std::cin>>opcao;
    }
    
    return 0;
}
