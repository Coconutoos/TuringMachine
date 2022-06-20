#ifndef TURINGMACHINE_TRANSITION_H
#define TURINGMACHINE_TRANSITION_H

class Transition {
private:
    char rCharacter;
    char wCharacter;
    char direction;
    int nextState;
public:
    Transition(char rCharacter, char wCharacter, char direction, int nextState);

    Transition();

    char getRCharacter() const;

    char getWCharacter() const;

    char getDirection() const;

    int getNextState() const;
};


#endif //TURINGMACHINE_TRANSITION_H
