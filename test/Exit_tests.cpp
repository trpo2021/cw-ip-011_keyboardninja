#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctest.h>
#include <libKBNinja/Exit.h>


// Тесты проверяют вывод булевской функции

CTEST(suite2, PUSTOI)
{
}

CTEST(suite2, Exit_test1)
{
	bool texit = true;
	int testing = 1;
	texit = Exit(testing);
	ASSERT_TRUE(texit);
}

CTEST(suite2, Exit_test2_allwaysfalse)
{
	bool texit = false;
	int testing = 1;
	texit = Exit(testing);
	ASSERT_FALSE(texit);	
}
