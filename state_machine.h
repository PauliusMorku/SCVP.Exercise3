#ifndef FSM_H
#define FSM_H

#include <systemc.h>

enum base {Start,G,GA,GAA,GAAG};

SC_MODULE(stateMachine)
{
public:
    sc_in<char> input;
    sc_in<bool> clk;
    sc_out<bool> output;

    int state; //did not use enum because GTKwave could not recognize it

    SC_CTOR(stateMachine): input("input"), clk("clk"), output("output")
    {
        state = Start;
        SC_METHOD(stm);
        dont_initialize();
        sensitive << clk.pos();
    }

private:
    void stm();
};


#endif // FSM_H


