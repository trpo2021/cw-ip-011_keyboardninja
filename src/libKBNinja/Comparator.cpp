#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>


bool Comparator(char* Val_One, char* Val_Two, bool* Quit, int testing) { // СЃСЂР°РІРЅРёРІР°РµС‚ Р·РЅР°С‡РµРЅРёСЏ
    if (*Val_One == *Val_Two) {
        return true;
    }
    return false;
}
