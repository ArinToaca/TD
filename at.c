#include <stdio.h>
#include "at.h"
// RUSU ELISEI && TOACA ARIN
/* state =s a state after this char */
STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character)
{
static uint8_t current_state = 0;
if (current_character == '\0')
    return current_state;

switch(current_state)
{
    case 0:
    {
        switch (current_character)
        {
            case '\r':
                {
                current_state = 1;
                printf("<CR>");
                break;
                }
            default:
            {
             current_state = 0;
             return STATE_MACHINE_READY_WITH_ERROR;
            }
                
        }
        break;
    }
    case 1:
    {
        switch(current_character)
        {
            case '\n':
                current_state = 2;
                printf("<LF>");
                break;
            default:
                {
                current_state = 0;
                return STATE_MACHINE_READY_WITH_ERROR;
                }
        }
        break;
    }
    case 2:
    {    switch(current_character)
        {
            case '+':
                current_state = 3;
                break;
            case 'O':
                current_state = 4;
                break;
            case 'E':
                current_state = 5;
                break;
            case '\r':
                current_state = 16;
                break;
            default:
                current_state = 0;
                return STATE_MACHINE_READY_WITH_ERROR;
                break;
        }
        break;
    }
    case 3:
    {
        if (current_character != '\r' && current_character != '\n')
        {
            current_state = 3;
            break;
        }
        else if (current_character == '\r')
        {
            current_state = 14;
            break;
        }
        else
        {
            current_state = 0;
            return STATE_MACHINE_READY_WITH_ERROR;
        }
        break;
    }
    case 4:
    {
        if (current_character == 'K')
        {
            current_state = 6;
            break;
        }
    }
    case 5:
    {
        if (current_character == 'R')
            current_state = 8;
        break;
    }
    case 6:
    {
        if (current_character == '\r')
            current_state = 7;
        break;
    }
    case 7:
    {    if (current_character == '\n')
            {
            current_state = 0;
            return STATE_MACHINE_READY_OK;
            }
        break;
    }
    case 8:
    {
        if (current_character == 'R')
            current_state = 9;
        break;
    }
    case 9:
    {
        if (current_character == 'O')
            current_state = 10;
        break;
    }
    case 10:
    {
        if (current_character == 'R')
            current_state = 11;
        break;
    }
    case 11:
    {
        if (current_character == '\r')
            current_state = 12;
        break;
    }
    case 12:
    {
        if (current_character == '\n')
            {
            return STATE_MACHINE_READY_WITH_ERROR;
            }
        break;
    }
    case 16:
    {
        if (current_character == '\n')
        {
            current_state = 0;
            return STATE_MACHINE_READY_OK;
        }
        break;
    }
    case 14:
    {
        if (current_character == '\n')
            current_state = 20;
        break;
    }
    case 20:
    {
        switch(current_character)
        {
            case '+':
                {
                current_state = 3;
                break;
                }
            case '\r':
                {
                current_state = 21;
                break;
                }
        }
        break;
    }
    case 21:
    {
        if (current_character == '\n')
            current_state = 22;
        break;
    }
    case 22:
    {
        switch (current_character)
        {
            case 'O':
                {
                current_state = 4;
                break;
                }
            case 'E':
                {
                current_state = 5;
                break;
                }
        }
        break;
    }

    }
/*if (current_character != '\r'  && current_character !='\n')
    printf("at char \"%c\" in parse, state=%d\n", current_character, current_state);
else if (current_character == '\r')
    printf("at char \"<CR>\" in parse, state=%d\n", current_state);
else if (current_character == '\n')
    printf("at char \"<LF>\" in parse, state=%d\n", current_state);
*/

return STATE_MACHINE_NOT_READY;
}
void print_state(STATE_MACHINE_RETURN_VALUE val)
{
    switch(val)
    {
        case STATE_MACHINE_NOT_READY:
        {
            printf("NOT READY\n");
            break;
        }
        case STATE_MACHINE_READY_OK:
        {
            printf("READY_OK\n");
            break;
        }
        case STATE_MACHINE_READY_WITH_ERROR:
        {
            printf("READY WITH ERROR\n");
            break;
        }
    }

}
