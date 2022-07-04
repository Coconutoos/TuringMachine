#include "App.h"

App::App(){
    this->TM = nullptr;
}

void App::startApp() {
    int op;
    do{
        printMenu();
        std::cin >> op;
        if(op >= 1 && op <= 3) executeOption(op);
        else std::cout << "Opcao Invalida!\n";
    }while(op != 3);
}

void App::executeOption(int option){
    switch(option){
        case 1:
            carregaMaquina();
            break;
        case 2:
            processaPalavra();
        default:
            break;
    }
}

void App::carregaMaquina() {
    delete this->TM;
    std::string fileName;
    std::cout << "Digite o nome do arquivo: " << std::endl;
    std::cin >> fileName;
    this->file = fopen(fileName.c_str(), "r");
    if(this->file != NULL) montaMaquina();
    else{
        std::cout << "Arquivo nao encontrado" << std::endl;
    }
};

void App::montaMaquina(){
    int nTran;
    std::vector<int> finais;
    std::vector<State> statesAux;
    std::string alfabetoaux;
    fscanf(this->file,"Q=%d%*c", &nTran);
    finais = lerFinais();
    alfabetoaux = lerAlfabeto();
    for(int i = 0; i < nTran; i++){
        statesAux.emplace_back(State(std::find(finais.begin(), finais.end(),i) != finais.end()));
    }
    alfabetoaux += "$*";
    TM = new TuringMachine(statesAux, alfabetoaux, 0);
    lerTransicoes();
    fclose(this->file);
}

void App::lerTransicoes(){
    int currentState, nextState;
    char readChar, writeChar, dir;
    while(!feof(this->file)){
        fscanf(file, "(q%d,%c)=(q%d,%c,%c)%*c",&currentState, &readChar, &nextState, &writeChar, &dir);
        TM->States[currentState].Transitions.emplace_back(Transition(readChar, writeChar, dir, nextState));
    }
}

std::string App::lerAlfabeto(){
    char letra, buffer;
    std::string final = "";
    std::vector<int> temp;
    fscanf(this->file, "alfabeto={");
    do{
        fscanf(this->file, "%c%c", &letra, &buffer);
        final += letra;
    }while(buffer != '}');
    fscanf(file, "%c", &buffer);
    return final;
}

std::vector<int> App::lerFinais(){
    char buffer;
    int final;
    std::vector<int> temp;
    fscanf(this->file, "F={");
    do{
       fscanf(this->file, "q%d%c", &final, &buffer);
       temp.push_back(final);
    }while(buffer != '}');
    fscanf(file, "%c", &buffer);
    return temp;
}

void App::processaPalavra(){
    std::string teste;
    std::cin >> teste;
    if (TM->process(teste)) std::cout << "ACEITA" << std::endl;
    else std::cout << "REJEITA" << std::endl;
}

void App::printMenu(){
    std::cout << "===========================" << std::endl;
    std::cout << "=   Escolha uma opcao:    =" << std::endl;
    std::cout << "=1. Carregar nova maquina =" << std::endl;
    std::cout << "=2. Testar Palavra        =" << std::endl;
    std::cout << "=3. Sair                  =" << std::endl;
    std::cout << "===========================" << std::endl;
}