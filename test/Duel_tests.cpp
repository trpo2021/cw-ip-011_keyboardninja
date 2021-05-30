#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define SCREEN_WIGHT 1280
#define SCREEN_HIGH 720
#include <ctest.h>
#include "../libKBNinja/Duel.h"

//Тесты проверяют, что выдаст Mode и Difficult, если значения больше 3

CTEST(suite3, PUSTOI)
{
}
//Следующие два теста проверяют, что будет, если ввести mode и difficulty вне их значений. Делаю через equal, так как не работает null. ПОэттому ввел константу k =1
CTEST(suite3, Duel_test1)
{
	int tmode = 4, tdif = 1, test = 0, n, k = 1, screen = 0;
	n = Duel(&tmode, &tdif, &screen, test);
	ASSERT_NOT_EQUAL(k, n);
}
CTEST(suite3, Duel_test2)
{
	int tmode = 1, tdif = 4, test = 0, n, k =1, screen = 0;
	n = Duel(&tmode, &tdif, &screen, test);
	ASSERT_NOT_EQUAL(k, n);
}

