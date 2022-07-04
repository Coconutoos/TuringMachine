#ifndef TURINGMACHINE_APP_H
#define TURINGMACHINE_APP_H
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "TuringMachine.h"

class App {
private:
    //
    // Pre-Condicao:
    // Pos-Condicao:
    FILE *file;
    TuringMachine *TM;

    // Printa o menu do programa
    // Pre-Condicao: Nenhuma
    // Pos-Condicao: Nenhuma
    void printMenu();

    // Chama o metodo para executar a opcao do usuario
    // Pre-Condicao: Nenhuma
    // Pos-Condicao: A funcao escolhida e executada
    void executeOption(int option);

    // Carrega um arquivo com a descricao de uma maquina
    // Pre-Condicao: Um arquivo existente contendo a descricao conforme as especificacoes de uma maquina
    // Pos-Condicao: O arquivo eh carregado e a maquina eh criada
    void montaMaquina();

    // Cria a maquina de acordo com as especificacoes do arquivo
    // Pre-Condicao: Um ponteiro para arquivo aberto com as especificacoes da maquina
    // Pos-Condicao: A maquina de acordo e criada
    void carregaMaquina();

    // Testa uma palavra entrada pelo usuario
    // Pre-Condicao: Uma maquina de Turing criada e especificada
    // Pos-Condicao: Printa ACEITA ou REJEITA dependendo do resultado
    void processaPalavra();

    // Le as transicoes do arquivo
    // Pre-Condicao: Um arquivo com as especificacoes corretas
    // Pos-Condicao: As transicoes sao adicionadas ao estado
    void lerTransicoes();

    // Le do arquivos quais estados sao finais
    // Pre-Condicao: Um arquivo aberto com especificacao da maquina
    // Pos-Condicao: Retorna um vetor contendo os estados finais
    std::vector<int> lerFinais();

    // Le o alfabeto do arquivo
    // Pre-Condicao: Um arquivo aberto com especificacao da maquina
    // Pos-Condicao: Retorna uma string com todos os caracteres do alfabeto da maquina
    std::string lerAlfabeto();
public:
    App();

    // Inicia a aplicacao
    // Pre-Condicao: Nenhuma
    // Pos-Condicao: Nenhuma
    void startApp();
};


#endif //TURINGMACHINE_APP_H