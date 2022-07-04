#include "State.h"
#include <iostream>
#include <utility>

State::State(std::vector<Transition> transitions, bool isFinal) : Transitions(std::move(transitions)), isFinal(isFinal) {}

State::State(bool isFinal) : isFinal(isFinal){
}

bool State::checkTransitions(TuringMachine &tm, char readCharacter, Transition &transition) {
    unsigned long int size;
    size = Transitions.size();
    for(int i = 0; size > i; i++) {
        if (readCharacter == Transitions[i].getRCharacter()) {
            transition = Transitions[i];
            tm.currentState = Transitions[i].getNextState();
            return true;
        }
    }
    return false;
}

bool State::getIsFinal() {
    return isFinal;
}
