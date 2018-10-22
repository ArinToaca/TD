#include <stdio.h>
#include "at.h"
/* state =s a state after this char */

STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character)
{

static uint8_t state = 0;
    switch(state)
    {
        case 0:
            switch (current_character)
            {
                case '\r':
                    state = 1;
                break;
                    
            }
        case 1:
            switch(current_character)
            {
                case '\n':
                    state = 2;
                    break;
            }
        case 2:
            switch(current_character)
            {
                case '+':
                    state = 3;
                    break;
                case 'O':
                    state = 4;
                    break;
                case 'E':
                    state = 5;
                    break;
                case '\r':
                    state = 16;
                    break;
            }
        case 3:
            if (current_character != '\r' && current_character != '\n')
            {
                state = 3;
            }
            else if (current_character == '\r')
            {
                state = 14;
            }
            break;
        case 4:
            if (current_character == 'K')
                state = 6;
            break;
        case 5:
            if (current_character == 'R')
                state = 8;
            break;
        case 6:
            if (current_character == '\r')
                state = 7;
            break;
        case 7:
            if (current_character == '\n')
                state = END_NO_ERR;
            break;
        case 8:
            if (current_character == 'R')
                state = 9;
            break;
        case 9:
            if (current_character == 'O')
                state = 10;
            break;
        case 10:
            if (current_character == 'R')
                state = 11;
            break;
        case 11:
            if (current_character == '\r')
                state = 12;
            break;
        case 12:
            if (current_character == '\n')
                state = STATE_MACHINE_READY_WITH_ERROR;
            break;
        case 16:
            if (current_character == '\n')
                state = STATE_MACHINE_READY_OK;
            break;
        case 14:
            if (current_character == '\n')
                state = 20;
            break;
        case 20:
            switch(current_character)
            {
                case '+':
                    state = 3;
                case '\r':
                    state = 21;
            }
            break;
        case 21:
            if (current_character == '\n')
                state = 22;
            break;
        case 22:
            switch (current_character)
            {
                case 'O':
                    state = 4;
                case 'E':
                    state = 5;
            }
            break;

    }
    return STATE_MACHINE_NOT_READY;
}
