#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Pattern_read.h>

void Words_and_Numbers(char *Name,int testing)
{
    FILE *Res;
    Res = fopen(Name,"r");

    Pattern_Read(Res, testing);

    fclose(Res);
}
