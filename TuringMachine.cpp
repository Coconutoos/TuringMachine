#include "TuringMachine.h"
#include <utility>
#include <cstring>
#include <iostream>


TuringMachine::TuringMachine(std::vector<State> states, const std::string &alphabet, const int currentState)
                            : States(std::move(states)), Alphabet(alphabet), currentState(currentState){}


bool TuringMachine::process(const std::string& word) {
    char *tape, auxWrite, auxDir;
    int cursor = 1;
    sprintf(tape,"*%s$", word.c_str());

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
    for(int i; *p; i++){
        if(i == pos){
            std::cout << "q[" << currentState << "]";
        }
        std::cout << *p;
    }
}


bool TuringMachine::changeState(char readCharacter, char *writeCharacter, char *direction){
    Transition auxTransition;
    if(Alphabet.find(readCharacter) == std::string::npos)
        return false;

    if(States[currentState].checkTransitions(this, readCharacter, auxTransition)) {
        *writeCharacter = auxTransition.getWCharacter();
        *direction = auxTransition.getDirection();
        return true;
    }
    return false;
}
