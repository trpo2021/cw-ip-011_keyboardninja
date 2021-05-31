#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctest.h>
#include "../src/libKBNinja/Exit.h"


// Тесты проверяют вывод булевской функции

CTEST(suite2, PUSTOI)
{
}

CTEST(suite2, Exit_test1)
{
	bool texit = true;
	int testing = 'y';
	texit = Exit(testing);
	ASSERT_FALSE(texit);
}
CTEST(suite2, Exit_test1_2)
{
	bool texit = true;
	int testing = 'Y';
	texit = Exit(testing);
	ASSERT_FALSE(texit);
}

CTEST(suite2, Exit_test2)
{
	bool texit = false;
	int testing ='n' ;
	texit = Exit(testing);
	ASSERT_TRUE(texit);
}
CTEST(suite2, Exit_test2_2)
{
	bool texit = false;
	int testing ='N' ;
	texit = Exit(testing);
	ASSERT_TRUE(texit);
}
CTEST(suite2, Exit_test3)
{
	bool texit = false;
	int testing ='е' ;
	texit = Exit(testing);
	ASSERT_TRUE(texit);
}
CTEST(suite2, Exit_test4)
{
	bool texit = false;
	int testing ='1' ;
	texit = Exit(testing);
	ASSERT_TRUE(texit);
}

