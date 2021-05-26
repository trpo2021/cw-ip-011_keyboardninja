#include "Pattern_read.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

FILE* Words_and_Numbers(char* Name, int testing)
{
    FILE* Res;
    Res = fopen(Name, "r");
    if(!testing){
        Pattern_Read(Res, testing);
        }
     else{
        return Res;
     }
    fclose(Res);
}
