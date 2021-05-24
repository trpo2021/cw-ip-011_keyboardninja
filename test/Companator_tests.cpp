#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctest.h>
#include "../libKBNinja/Comparator.h"



CTEST(suite1, PUSTOI)
{
}
// Тесты должен проверить, выводит ли функция булевские переменные.
CTEST(suite1, COMPARATOR_TEST1)
{
	int testing = 1;
	char tval1 = '%';
	bool testq = false;
	Comparator(&tval1, &testq, testing);
	ASSERT_TRUE(testq);
}

//Данный тест проверяет что выдаст сама функци на выводе
CTEST(suite1, COMPARATOR_TEST2)
{
	int testing = 1;
	char tval2 = '!';
	bool testq2 = true, k;
	k = Comparator(&tval2, &testq2, testing);
	ASSERT_TRUE(k);
}
