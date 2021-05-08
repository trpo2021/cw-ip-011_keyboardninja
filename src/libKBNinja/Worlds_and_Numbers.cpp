#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <libKBNinja/Pattern_read.h>

void Words_and_Numbers(int testing)
{
    FILE *Res;
    Res = fopen("text/lan.txt","r");

    Pattern_Read(Res, testing);

    fclose(Res);
}
