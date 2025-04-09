#include <iostream>
#include <string>
#include <vector>

class Arquivo {
private:
    std::string conteudo;

public:
    Arquivo(const std::string& c) : conteudo(c) {}

    std::string getConteudo() const {
        return conteudo;
    }

    void setConteudo(const std::string& c) {
        conteudo = c;
    }
};

class ServidorImpressao {
private:
    static ServidorImpressao* servidor;
    std::vector<Arquivo> arquivos;

    ServidorImpressao() {
        std::cout << "Servidor de Impressão iniciado.\n";
        arquivos.push_back(Arquivo("Arquivo 1"));
        arquivos.push_back(Arquivo("Arquivo 2"));
        arquivos.push_back(Arquivo("Arquivo 3"));
    }

    ~ServidorImpressao() {
        std::cout << "Servidor de Impressão finalizado.\n";
    }

public:
    static ServidorImpressao* obtemServidor() {
        if (servidor == nullptr) {
            servidor = new ServidorImpressao();
        }
        return servidor;
    }

    static void removeServidor() {
        if (servidor != nullptr) {
            delete servidor;
            servidor = nullptr;
        }
    }

    void imprimeArquivo(int indice) {
        if (indice >= 0 && indice < arquivos.size()) {
            std::cout << "Imprimindo: " << arquivos[indice].getConteudo() << std::endl;
        } else {
            std::cout << "Índice inválido para impressão.\n";
        }
    }
};

ServidorImpressao* ServidorImpressao::servidor = nullptr;

int main() {
    ServidorImpressao* s = ServidorImpressao::obtemServidor();
    s->imprimeArquivo(0);
    s->imprimeArquivo(2);
    s->imprimeArquivo(5); // índice inválido
    ServidorImpressao::removeServidor();
    return 0;
}
