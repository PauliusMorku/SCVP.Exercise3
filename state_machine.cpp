#include "state_machine.h"
#include <unistd.h>

void stateMachine::process()
{
    enum base {Start,G,GA,GAA,GAAG};
    base sate;

    output.write(false);
    switch (sate){
    case Start:
        if (input == 'G')
        {
            sate = G;
        }
        break;
    case G:
        if (input == 'A')
        {
            sate = GA;
        }
        else if (input == 'G')
        {
            sate = G;
        }
        else
        {
            sate = Start;
        }
        break;
    case GA:
        if (input == 'A')
        {
            sate = GAA;
        }
        else if (input == 'G')
        {
            sate = G;
        }
        else
        {
            sate = Start;
        }
        break;
    case GAA:
        if (input == 'G')
        {
            sate = GAAG;
        }
        else
        {
            sate = Start;
        }
        break;
    case GAAG:
        if (input == 'G')
        {
            sate = G;
        }
        else
        {
            sate = Start;
        }
        output.write(true);
        break;
    }
}
