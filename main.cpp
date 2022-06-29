#include <iostream>
#include "TuringMachine.h"



int main() {
    Transition t1('a','b','D',1);
    Transition t2('b','c','D',0);
    Transition t3('d', 'd', 'D', 1);
    Transition t4('$', '$', 'E', 0);

    std::vector<Transition> vecT1;
    vecT1.push_back(t1);
    vecT1.push_back((t4));
    vecT1.push_back((t3));

    std::vector<Transition> vecT2;
    vecT2.push_back(t2);
    vecT2.push_back(t3);
    vecT2.push_back(t4);

    State q0(vecT1, true);
    State q1(vecT2, true);


    std::vector<State> states;
    states.push_back(q0);
    states.push_back(q1);

    TuringMachine tm(states, "abcdefg$*", 0);
    if(tm.process("abd")) printf("Aceita\n");
    else
        printf("Rejeita\n");
    return 0;
}
