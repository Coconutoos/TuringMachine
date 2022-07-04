#ifndef STATE_H
#define STATE_H
#include <vector>
#include "Transition.h"
#include "TuringMachine.h"

class TuringMachine;

class State{
private:
    bool isFinal;
public:
C    // Vetor contendo as transicoes do estado
    std::vector<Transition> Transitions;

    // Construtores
    State(std::vector<Transition> transitions, bool isFinal);
    State(bool isFinal);

    // Checa se uma transicao e possivel e atualiza o estado atual da maquina
    // Pre-Condicao: Uma maquina criada e especificada e uma letra de entrada
    // Pos-Condicao: Retorna verdadeiro ou falso caso haja uma transicao compativel, atualiza o estado atual de tm
    bool checkTransitions(TuringMachine &tm, char readCharacter, Transition &transition);
    bool getIsFinal(); //Retorna se esse estado e final
};


#endif //TURINGMACHINE_STATE_H


