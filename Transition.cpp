#include "Transition.h"

Transition::Transition(char rCharacter, char wCharacter, char direction, int nextState) : rCharacter(rCharacter),
                                                                                          wCharacter(wCharacter),
                                                                                          direction(direction),
                                                                                          nextState(nextState) {}

Transition::Transition() {}

char Transition::getRCharacter() const {
    return rCharacter;
}

char Transition::getWCharacter() const {
    return wCharacter;
}

char Transition::getDirection() const {
    return direction;
}

int Transition::getNextState() const {
    return nextState;
}


