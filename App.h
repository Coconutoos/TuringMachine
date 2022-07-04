#ifndef TURINGMACHINE_APP_H
#define TURINGMACHINE_APP_H
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include "TuringMachine.h"

class App {
private:
    FILE *file;
    TuringMachine *TM;
    void printMenu();
    void executeOption(int option);
    void montaMaquina();
    void carregaMaquina();
    void processaPalavra();
    void lerTransicoes();
    std::vector<int> lerFinais();
    std::string lerAlfabeto();
public:
    App();
    void startApp();
};


#endif //TURINGMACHINE_APP_H
