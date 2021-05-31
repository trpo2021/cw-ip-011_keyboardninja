#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctest.h>
#include "../src/libKBNinja/Comparator.h"



CTEST(suite1, PUSTOI)
{
}
// Тесты должен проверить, выводит ли функция булевские переменные.
CTEST(suite1, COMPARATOR_TEST1)
{
	char tval1 = '%';
	char tval2 = '%';
	bool qw= true;
	qw = Comparator(&tval1, &tval2);
	ASSERT_TRUE(qw);
}


CTEST(suite1, COMPARATOR_TEST2)
{
	char tval1 = '%';
	char tval2 = '!';
	bool k = true;
	k = Comparator(&tval1, &tval2);
	ASSERT_FALSE(k);
}


