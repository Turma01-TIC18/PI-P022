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

    GerenciadorTarefas::CarregarTarefas("tarefas.txt");

    while (true) {

        cout << "Escolha uma opção:\n";
        cout << "1. Adicionar nova tarefa\n";
        cout << "2. Marcar tarefa como concluída\n";
        cout << "3. Listar tarefas pendentes\n";
        cout << "4. Sair e salvar\n";

        int opcao;
        cin >> opcao;

        if (opcao == 1) {

            cin.ignore();  
            cout << "Digite a descrição da tarefa: ";
            string descricao;
            getline(cin, descricao);
            GerenciadorTarefas::AdicionarTarefa(descricao);

        } else if (opcao == 2) {
            cout << "Digite o índice da tarefa a ser marcada como concluída: ";
            int indice;
            cin >> indice;
            GerenciadorTarefas::MarcarTarefaConcluida(indice);

        } else if (opcao == 3) {
            cout << "Tarefas pendentes:\n";
            GerenciadorTarefas::ListarTarefasPendentes();

        } else if (opcao == 4) {
            GerenciadorTarefas::SalvarTarefas("tarefas.txt");
            break;

        }
    }

return 0;
}