#include <systemc.h>
#include <iostream>
#include <state_machine.h>
#include <stimuli.h>

using namespace std;

int sc_main(int argc, char* argv[])
{
    stateMachine genomeParser("genomeParser");
    stimuli genomeInput("genomeInput");
    sc_clock clk("clk", sc_time(1,SC_NS));

    sc_signal<char> h1;
    sc_signal<bool> output;

    genomeParser.input.bind(h1);
    genomeInput.output.bind(h1);
    genomeParser.clk.bind(clk);
    genomeInput.clk.bind(clk);
    genomeParser.output.bind(output);

    sc_trace_file* Tf;
    Tf = sc_create_vcd_trace_file("traces");
    sc_trace(Tf, clk, "clk");
    sc_trace(Tf, h1, "h1" );
    sc_trace(Tf, output, "output" );
    sc_trace(Tf, genomeParser.state, "state" );

    sc_start();
    sc_close_vcd_trace_file(Tf);

    /* Why do we use dont_initialize() in state machine constructor?
     * /

    return 0;
}
