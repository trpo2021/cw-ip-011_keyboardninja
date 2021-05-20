#include <libKBNinja/Pattern_read.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Words_and_Numbers(char* Name, int testing)
{
    FILE* Res;
    Res = fopen(Name, "r");

    Pattern_Read(Res, testing);

    fclose(Res);
}
