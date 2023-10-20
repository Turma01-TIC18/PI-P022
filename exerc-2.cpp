#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Tarefa {
public:
    Tarefa(const string& descricao, bool concluida = false)
        : descricao(descricao), concluida(concluida) {}

    string getDescricao() const {
        return descricao;
    }

    bool estaConcluida() const {
        return concluida;
    }

    void marcarConcluida() {
        concluida = true;
    }

private:
    string descricao;
    bool concluida;
};

class GerenciadorTarefas {
public:

    //Adicionar tarefa

    //Marcar tarefa concluida

    //Listar tarefas pendentes

    // salvar tarefas

    // carregar tarefas

private:
    static vector<Tarefa> tarefas;
};

vector<Tarefa> GerenciadorTarefas::tarefas;

int main() {
    // código da função main

    return 0;
}

