#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>
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
	Exit(texit, testing);
	ASSERT_TRUE(texit);
}

CTEST(suite2, Exit_test2_allwaysfalse)
{
	bool texit = true;
	int testing = 1;
	Exit(texit, testing);
	ASSERT_FALSE(texit);	
}
