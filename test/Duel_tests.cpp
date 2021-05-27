#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctest.h>
#include "../libKBNinja/Duel.h"

//Тесты проверяют, что выдаст Mode и Difficult, если значения больше 3

CTEST(suite3, PUSTOI)
{
}
CTEST(suite3, Duel_test1)
{
	int tmode = 4, tdif = 1, test = 0, n;
	n = Duel(tmode, tdif, test);
	ASSERT_NULL(n);
}
CTEST(suite3, Duel_test2)
{
	int tmode = 1, tdif = 4, test = 0, n;
	n = Duel(tmode, tdif, test);
	ASSERT_NULL(n);
}
// Проверим, что будет, если открыть файл
CTEST(suite3, Duel_test3)
{
	int tmode = 1, tdif = 2, test = 1, n, k = 1;
	n = Duel(tmode, tdif, test);
	ASSERT_EQUAL(k, n);
}
 // Проверим, что будет, если открыть несуществующий  файл
CTEST(suite3, Duel_test4)
{
	int tmode = 1, tdif = 3, test = 1, n, k = 1;
	n = Duel(tmode, tdif, test);
	ASSERT_NOT_EQUAL(k, n);
}
