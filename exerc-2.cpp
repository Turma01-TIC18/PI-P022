#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Tarefa {
    private:
        string descricao;
        bool concluida;

    public:
        Tarefa(string _descricao, bool _concluida = false){
            descricao = _descricao;
            concluida = _concluida;
        }
            
        string getDescricao() {
            return descricao;
        }

        bool estaConcluida() {
            return concluida;
        }

        void marcarConcluida() {
            concluida = true;
        }
    
};

class GerenciadorTarefas {
    private:
    static vector<Tarefa> tarefas;

    public:
        static void adicionarTarefa(string descricao) {
            tarefas.push_back(Tarefa(descricao));
        }

        static void marcarTarefaConcluida(int indice) {
            if (indice >= 0 && indice < tarefas.size()) {
                tarefas[indice].marcarConcluida();
            }
        }
        
        static void listarTarefasPendentes() {
            for (int i = 0; i < tarefas.size(); i++) {
                if (!tarefas[i].estaConcluida()) {
                    cout << i << ". " << tarefas[i].getDescricao() << endl;
                }
            }
        }

        static void salvarTarefas(string nomeArquivo) {
            ofstream arquivo(nomeArquivo);
            if (arquivo.is_open()) {
                for (Tarefa& tarefa : tarefas) {
                    arquivo << tarefa.getDescricao() << "," << tarefa.estaConcluida() <<endl;
                }
                arquivo.close();
            }
        }

        static void carregarTarefas(string nomeArquivo) {
            ifstream arquivo(nomeArquivo);
            if (arquivo.is_open()) {
                tarefas.clear();
                string linha;
                while (getline(arquivo, linha)) {
                    size_t pos = linha.find(',');
                    if (pos != string::npos) {
                        string descricao = linha.substr(0, pos);
                        bool concluida = (linha.substr(pos + 1) == "1");
                        Tarefa tarefa(descricao);
                        if (concluida) {
                            tarefa.marcarConcluida();
                        }
                        tarefas.push_back(tarefa);
                    }
                }
                arquivo.close();
            }
        }
};

vector<Tarefa> GerenciadorTarefas::tarefas;

int main() {

    GerenciadorTarefas::carregarTarefas("tarefas.txt");

    while (true) {

        cout << "Escolha uma opção:" << endl;;
        cout << "1. Adicionar nova tarefa" << endl;;
        cout << "2. Marcar tarefa como concluída" << endl;;
        cout << "3. Listar tarefas pendentes" << endl;;
        cout << "4. Sair e salvar" << endl;

        int opcao;
        cin >> opcao;

        if (opcao == 1) {

            cin.ignore();  
            cout << "Digite a descrição da tarefa: ";
            string descricao;
            getline(cin, descricao);
            GerenciadorTarefas::adicionarTarefa(descricao);

        } else if (opcao == 2) {
            cout << "Digite o índice da tarefa a ser marcada como concluída: ";
            int indice;
            cin >> indice;
            GerenciadorTarefas::marcarTarefaConcluida(indice);

        } else if (opcao == 3) {
            cout << "Tarefas pendentes:\n";
            GerenciadorTarefas::listarTarefasPendentes();

        } else if (opcao == 4) {
            GerenciadorTarefas::salvarTarefas("tarefas.txt");
            break;
        }
    }

    return 0;
}