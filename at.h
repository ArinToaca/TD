/*
 * Library should implement a parse (FSM with switch) method, a data structure (data[max_line_cnt][str_size+1], bool OK, line_count++)
 */
#include <stdint.h>
#ifndef ARIN_TOACA
#define ARIN_TOACA

#define END_NO_ERR 89
#define END_SYNTAX_ERR 99
#define ERROR -1

#define AT_COMMAND_MAX_LINES 100
#define AT_COMMAND_MAX_LINE_SIZE 128
typedef struct
{
    uint8_t ok;
    uint8_t data[AT_COMMAND_MAX_LINES][AT_COMMAND_MAX_LINE_SIZE + 1];
    uint32_t line_count;
}AT_COMMAND_DATA; 

typedef enum
{
 STATE_MACHINE_NOT_READY,
 STATE_MACHINE_READY_OK,
 STATE_MACHINE_READY_WITH_ERROR
}STATE_MACHINE_RETURN_VALUE;
STATE_MACHINE_RETURN_VALUE at_command_parse(uint8_t current_character); 

#endif
