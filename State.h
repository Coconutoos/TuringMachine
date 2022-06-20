#ifndef TURINGMACHINE_STATE_H
#define TURINGMACHINE_STATE_H
#include <vector>
#include "Transition.h"
#include "TuringMachine.h"

class State {
private:
    std::vector<Transition> Transitions;
    bool isFinal;

public:
    State(const std::vector<Transition> &transitions, bool isFinal);
    bool checkTransitions(TuringMachine &tm, char readCharacter, Transition *transition);
    bool getIsFinal();
};


#endif //TURINGMACHINE_STATE_H


