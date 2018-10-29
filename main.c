#include<stdio.h>
#include<stdlib.h>
#include "at.h"
//RUSU ELISEI && TOACA ARIN
int main(int argc, char **argv)
{
if (argc != 2)
{
    printf("Incorrect nr of args\n");
    return -1;
}
STATE_MACHINE_RETURN_VALUE v;
FILE *fp = fopen(argv[1], "rb");
char c;
AT_COMMAND_DATA d;
d.ok = 0;
d.line_count = 0;
uint8_t char_count = 0;
do{
    c = fgetc(fp);
    if (c == EOF)
        continue;
    v = at_command_parse(c);
    if (v == STATE_MACHINE_NOT_READY && d.line_count < AT_COMMAND_MAX_LINES && 
            d.line_count < AT_COMMAND_MAX_LINE_SIZE)
    {
        if (c == '\n')
        {
            char_count = 0;
            d.line_count++;
        }
        d.data[d.line_count][char_count++] = c;
    }
    if (v == STATE_MACHINE_READY_OK)
        d.ok = 1;
    if (v == STATE_MACHINE_READY_WITH_ERROR)
        printf("Error at line %d\n", d.line_count);
    
}while(!feof(fp));

printf("-----FINAL_STATE-------\n");
print_state(v);
fclose(fp);
printf("final datastructure...\n");
int i;
for (i=0;i<=d.line_count;i++)
{
    printf("%s",d.data[i]);

}
}
