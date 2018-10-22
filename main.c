#include<stdio.h>
#include<stdlib.h>
#include "at.h"
int main(int argc, char **argv)
{
if (argc != 2)
{
    printf("Incorrect nr of args\n");
    return -1;
}

FILE *fp = fopen(argv[1], "rb");
while(!feof(fp))
{
    char c;
    c = fgetc(fp);
    at_command_parse(c);
    
}
fclose(fp);
}
