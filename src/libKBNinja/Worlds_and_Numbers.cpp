#include <libKBNinja/Pattern_read.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void Words_and_Numbers()
{
    FILE* Res;
    Res = fopen("text/lan.txt", "r");

    Pattern_Read(Res);

    fclose(Res);
}
