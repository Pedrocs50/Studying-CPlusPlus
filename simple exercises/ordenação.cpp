#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Ordenavel {
public:
    virtual bool comparar(const class Pessoa& p1, const class Pessoa& p2) const = 0;  // Método virtual puro
    virtual ~Ordenavel() = default;  // Destruidor virtual
};

class Pessoa {
private:
    string nome;
    int idade;
public:
    Pessoa(const string& n, int i) : nome(n), idade(i) {}

    string getNome() const { return nome; }
    int getIdade() const { return idade; }

    
    void imprimir() const {
        cout << "Nome: " << nome << ", Idade: " << idade << endl;
    }
};

// Classe que implementa a ordenação por Nome
class OrdenarPorNome : public Ordenavel {
public:
    bool comparar(const Pessoa& p1, const Pessoa& p2) const override {
        return p1.getNome() < p2.getNome();  
    }
};

// Classe que implementa a ordenação por Idade
class OrdenarPorIdade : public Ordenavel {
public:
    bool comparar(const Pessoa& p1, const Pessoa& p2) const override {
        return p1.getIdade() < p2.getIdade();  
    }
};

// Função de ordenação genérica usando ponteiro para a classe de ordenação
void ordenar(vector<Pessoa>& pessoas, Ordenavel* estrategia) {
    sort(pessoas.begin(), pessoas.end(), [&](const Pessoa& p1, const Pessoa& p2) {
        return estrategia->comparar(p1, p2);  // Chama o método comparar da classe de ordenação
    });
}

int main() {
    // Criando uma lista de pessoas
    vector<Pessoa> pessoas = {
        Pessoa("Maria", 30),
        Pessoa("João", 25),
        Pessoa("Ana", 35),
        Pessoa("Carlos", 28)
    };


    cout << "Lista Original:" << endl;
    for (const auto& p : pessoas) {
        p.imprimir();
    }

    Ordenavel* ordenacaoNome = new OrdenarPorNome(); 
    ordenar(pessoas, ordenacaoNome);  

    cout << "\nLista Ordenada por Nome:" << endl;
    for (const auto& p : pessoas) {
        p.imprimir();
    }

    Ordenavel* ordenacaoIdade = new OrdenarPorIdade();  
    ordenar(pessoas, ordenacaoIdade); 

    cout << "\nLista Ordenada por Idade:" << endl;
    for (const auto& p : pessoas) {
        p.imprimir();
    }

    delete ordenacaoNome;
    delete ordenacaoIdade;

    return 0;
}
