#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H
#include <string>
#include <vector>
#include "State.h"

class State;

class TuringMachine {
private:
    int currentState;
    std::string Alphabet;
    friend class State;

public:
    std::vector<State> States; // Conjunto de estados da Maquina
    TuringMachine(std::vector<State> states, std::string alphabet, const int currentState);

    // Processo principal da maquina, recebe umpalavra e retorna verdadeiro ou falso para o resultado
    // Pre-Condicao: Uma maquina criada e uma palavra de entrada
    // Pos-Condicao: Retorna se a palavra e aceita ou rejeitada
    bool process(const std::string word);

    // Muda o estado da maquina
    // Pre-Condicao: Uma maquina criada, um caractere lido, uma variavel para guardar o caractere de escrita e direcao
    // Pos-Condicao: O estado da maquina e a fita sao atualizados de acordo com as transicoes possiveis
    bool changeState(char readCharacter, char *writeCharacter, char *direction);

    // Imprime a fita da maquina
    // Pre-Condicao: Uma maquina processando uma palavra
    // Pos-Condicao: Imprime a fita com o estado atual
    void printTape(char *tape, int pos);
};


#endif //TURINGMACHINE_H
