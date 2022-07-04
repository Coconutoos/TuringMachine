#ifndef TRANSITION_H
#define TRANSITION_H

class Transition {
private:
    char rCharacter;    //Caractere lido
    char wCharacter;    //Caractere a ser escrito
    char direction;     //Direcao em que o curosr anda
    int nextState;      //Proximo estado da maquina
public:
    Transition(char rCharacter, char wCharacter, char direction, int nextState);
    Transition();
    char getRCharacter() const;
    char getWCharacter() const;
    char getDirection() const;
    int getNextState() const;
};


#endif //TURINGMACHINE_TRANSITION_H
