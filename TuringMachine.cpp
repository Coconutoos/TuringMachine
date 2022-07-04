#include "TuringMachine.h"
#include <utility>
#include <iostream>


TuringMachine::TuringMachine(std::vector<State> states, std::string alphabet, const int currentState)
                            : States(std::move(states)), Alphabet(std::move(alphabet)), currentState(currentState){}


bool TuringMachine::process(const std::string word){
    char tape[50], auxWrite, auxDir;
    int cursor = 1; // "Ponteiro" auxiliar que anda na fita
    currentState = 0;
    sprintf(tape,"*%s$", word.c_str());
    printTape(tape, cursor);
    while(changeState(tape[cursor], &auxWrite, &auxDir)){
        tape[cursor] = auxWrite; //Escreve na fita de acordo com a transicao encontrada
        if(auxDir == 'D') cursor++;
        else cursor--;
        printTape(tape, cursor);
    }
    return States[currentState].getIsFinal();
}

void TuringMachine::printTape(char* tape, int pos){
    char *p;
    p = tape;
    for(int i = 0; *p; i++, p++){
        if(i == pos){
            std::cout << "[q" << currentState << "]";
        }
        std::cout << *p;
    }
    printf("\n");
}


bool TuringMachine::changeState(char readCharacter, char *writeCharacter, char *direction){
    Transition auxTransition;
    if(States[currentState].checkTransitions(*this, readCharacter, auxTransition)) {
        *writeCharacter = auxTransition.getWCharacter();
        *direction = auxTransition.getDirection();
        return true;
    }
    return false;
}
