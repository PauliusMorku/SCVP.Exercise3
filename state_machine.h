#ifndef FSM_H
#define FSM_H

#include <systemc.h>

SC_MODULE(stateMachine)
{
public:
    sc_in<char> input;
    sc_in<bool> clk;
    sc_out<bool> output;

    SC_CTOR(stateMachine): input("input"), clk("clk"), output("output")
    {
        SC_METHOD(process);
        dont_initialize();
        sensitive << clk.pos();
    }

private:
    void process();
};


#endif // FSM_H


