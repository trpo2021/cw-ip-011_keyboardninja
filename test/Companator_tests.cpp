#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctest.h>
#include "../libKBNinja/Comparator.h"



CTEST(suite1, PUSTOI)
{
}
// Тесты должен проверить, выводит ли функция булевские переменные.
CTEST(suite1, COMPARATOR_TEST1)
{
	int testing = '1';
	char tval1 = '%';
	char tval2 = '%';
	bool testq = false, qw= true;
	qw = Comparator(&tval1, &tval2, &testq, testing);
	ASSERT_TRUE(qw);
}


CTEST(suite1, COMPARATOR_TEST2)
{
	int testing = '1';
	char tval1 = '%';
	char tval2 = '!';
	bool testq2 = true, k = true;
	k = Comparator(&tval1, &tval2, &testq2, testing);
	ASSERT_FALSE(k);
}


