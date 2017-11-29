#include "state_machine.h"
#include <unistd.h>

void stateMachine::stm()
{
    char input_temp = input.read();
    bool output_temp = false;

    switch (state)
    {
        case Start:
            if (input_temp == 'G')
            {
                state = G;
            }
            break;
        case G:
            if (input_temp == 'A')
            {
                state = GA;
            }
            else if (input_temp == 'G')
            {
                state = G;
            }
            else
            {
                state = Start;
            }
            break;
        case GA:
            if (input_temp == 'A')
            {
                state = GAA;
            }
            else if (input_temp == 'G')
            {
                state = G;
            }
            else
            {
                state = Start;
            }
            break;
        case GAA:
            if (input_temp == 'G')
            {
                state = GAAG;
            }
            else
            {
                state = Start;
            }
            break;
        case GAAG:
            if (input_temp == 'G')
            {
                state = G;
            }
            else
            {
                state = Start;
            }
            std::cout<<"Patern GAAG detected"<<std::endl;
            output_temp = true;
            break;
        default:
            SC_REPORT_FATAL(this->name(), "Invalid state");
            break;
    }
    output.write(output_temp);
}
