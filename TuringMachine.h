#ifndef TURINGMACHINE_H
#define TURINGMACHINE_H
#include <string>
#include <vector>
#include "State.h"

class TuringMachine {
private:
    std::vector<State> States;
    std::string Alphabet;
    int currentState;

    friend class State;
public:
    TuringMachine(std::vector<State> states, const std::string &alphabet, const int currentState);
    bool process(const std::string& word);
    bool changeState(char readCharacter, char *writeCharacter, char *direction);

    void printTape(char *tape, int pos);
};


#endif //TURINGMACHINE_H
