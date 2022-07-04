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
    std::vector<Transition> Transitions;
    State(std::vector<Transition> transitions, bool isFinal);
    State(bool isFinal);
    bool checkTransitions(TuringMachine &tm, char readCharacter, Transition &transition);
    bool getIsFinal();
};


#endif //TURINGMACHINE_STATE_H


