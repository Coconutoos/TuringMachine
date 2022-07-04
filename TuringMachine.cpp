#include "TuringMachine.h"
#include <utility>
#include <iostream>


TuringMachine::TuringMachine(std::vector<State> states, std::string alphabet, const int currentState)
                            : States(std::move(states)), Alphabet(std::move(alphabet)), currentState(currentState){}


bool TuringMachine::process(const std::string word){
    char tape[50], auxWrite, auxDir;
    int cursor = 1;
    currentState = 0;
    sprintf(tape,"*%s$", word.c_str());
    printTape(tape, cursor);
    std::cout << Alphabet << std::endl;
    while(changeState(tape[cursor], &auxWrite, &auxDir)){
        tape[cursor] = auxWrite;
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
        std::cout << currentState << std::endl;
        *writeCharacter = auxTransition.getWCharacter();
        *direction = auxTransition.getDirection();
        return true;
    }
    return false;
}
