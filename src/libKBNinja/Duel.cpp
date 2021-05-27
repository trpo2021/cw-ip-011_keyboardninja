#include "Numbers.h"
#include "Worlds.h"
#include "Worlds_and_Numbers.h"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int Duel(
        int Mode,
        int Difficulty,
        int testing) // запуск текстов на основе выбранного уровня сложности
{
    if ( Difficulty > 3 || Difficulty < 1){
        return NULL;
        }
    if(Mode == 1) {
        if (Difficulty == 1) {
            Words_One(testing);
        } else if (Difficulty == 2) {
            if (!testing){
            char Name[] = {"text/l2.txt"};
            }
            else{
            char Name[] = {"test.txt"};
            return 1
            }
            Words_and_Numbers(Name, testing);
        } else if (Difficulty == 3) {
            if(!testing){
            char Name[] = {"text/l3.txt"};
            }
            else{
            char Name[] = {"test/qw.txt"};
            return NULL;
            }
            Words_and_Numbers(Name, testing);
        }
    } else if (Mode == 2) {
        if (Difficulty == 1) {
            Numbers_One(testing);
        } else if (Difficulty == 2) {
            char Name[] = {"text/n2.txt"};
            Words_and_Numbers(Name, testing);
        } else if (Difficulty == 3) {
            char Name[] = {"text/n3.txt"};
            Words_and_Numbers(Name, testing);
        }
    } else if (Mode == 3) {
        char Name[] = {"text/lan.txt"};
        Words_and_Numbers(Name, testing);
    }
    else {
        return NULL;
        }
}
