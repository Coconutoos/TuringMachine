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

    std::vector<State> States;
    TuringMachine(std::vector<State> states, std::string alphabet, const int currentState);
    bool process(const std::string word);
    bool changeState(char readCharacter, char *writeCharacter, char *direction);

    void printTape(char *tape, int pos);
};


#endif //TURINGMACHINE_H
