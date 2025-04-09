#include <iostream>
#include <string>
#include <vector>

// Interface base
class Relatorio {
public:
    virtual void exibir() = 0;
    virtual ~Relatorio() {}
};

// Objeto real (custoso e sensível)
class RelatorioConfidencial : public Relatorio {
    std::string conteudo;

public:
    RelatorioConfidencial(std::string nome) {
        std::cout << "Carregando relatório confidencial: " << nome << " (demorado...)\n";
        this->conteudo = "Dados secretos do relatório " + nome;
    }

    void exibir() override {
        std::cout << "Conteúdo: " << conteudo << "\n";
    }
};

// Proxy com controle de acesso
class ProxyRelatorio : public Relatorio {
    RelatorioConfidencial* relatorioReal;
    std::string nomeArquivo;
    std::string usuario;

public:
    ProxyRelatorio(std::string nome, std::string usuario)
        : nomeArquivo(nome), usuario(usuario), relatorioReal(nullptr) {
        std::cout << "Proxy de relatório criado para o usuário " << usuario << "\n";
    }

    void exibir() override {
        if (usuario != "admin") {
            std::cout << "Acesso negado: usuário sem permissão para ver o relatório.\n";
            return;
        }

        if (relatorioReal == nullptr) {
            std::cout << "Relatório real sendo carregado agora (sob demanda)...\n";
            relatorioReal = new RelatorioConfidencial(nomeArquivo);
        }

        std::cout << "Acesso concedido. Exibindo relatório:\n";
        relatorioReal->exibir();
    }

    ~ProxyRelatorio() {
        if (relatorioReal != nullptr) {
            delete relatorioReal;
        }
    }
};

// Cliente
class SistemaSeguranca {
    std::vector<Relatorio*> relatorios;

public:
    void adicionaRelatorio(std::string nomeArquivo, std::string usuario) {
        relatorios.push_back(new ProxyRelatorio(nomeArquivo, usuario));
    }

    void exibeRelatorio(int id) {
        if (id >= 0 && id < relatorios.size()) {
            relatorios.at(id)->exibir();
        }
    }

    ~SistemaSeguranca() {
        for (Relatorio* r : relatorios) {
            delete r;
        }
    }
};

int main() {
    SistemaSeguranca sistema;
    sistema.adicionaRelatorio("relatorio_secreto_01.pdf", "user123");
    sistema.adicionaRelatorio("relatorio_secreto_02.pdf", "admin");

    int opcao;
    std::cout << "Digite 1 para ver relatório 1, 2 para ver relatório 2, 0 para sair:\n";
    std::cin >> opcao;
    while (opcao != 0) {
        sistema.exibeRelatorio(opcao - 1);
        std::cin >> opcao;
    }

    return 0;
}
