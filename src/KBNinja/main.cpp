#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <libKBNinja/Prepare.h>
#include <libKBNinja/Exit.h>
#include <libKBNinja/Comparator.h>
#include <libKBNinja/Pattern_read.h>
#include <libKBNinja/Worlds.h>
#include <libKBNinja/Numbers.h>
#include <libKBNinja/Worlds_and_Numbers.h>
#include <libKBNinja/Duel.h>


int main ()
{
    setlocale(0,"Russian");
    srand(time(NULL));

    int Mode = 0, Difficulty = 0, testing = 0;
    bool Game = true;

    while(Game) // Âñÿ ëîãèêà ïðîãðàììû
    {
        system("cls");                                          //
        printf("\tÏðèâåò, õî÷åøü ïðåèñïîëíèòüñÿ â ïå÷àòè?\n");  //
        Prepare(&Mode, &Difficulty, testing);                            // âûáèðàåì ðåæèì èãðû è óðîâåíü ñëîæíîñòè
        //printf("\n%d %d\n", Mode, Difficulty);                  // âûâîäèì çíà÷åíèÿ, êîòîðûå âûáðàë ïîëüçîâàòåëü
        Duel(Mode, Difficulty, testing);

        system("PAUSE");                                        //
        Game = Exit(testing);                                     // Ïðîâåðÿåì õî÷åò ëè ïîëüçîâàòåëü ïîòðåíèðîâàòüñÿ åùù¸ ðàç èëè íåò
    }
    system("cls");
    printf("Ñïàñèáî çà èãðó, âîçâðàùÿéòåñü\n");

    system("PAUSE");
    return 0;
}
