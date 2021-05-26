#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <ctest.h>
#include "../libKBNinja/Words_and_Numbers.h"
// Тесты будут проверять, как открывается файл
CTEST(suite4, PUSTOI)
{
}
 CTEST(suite4, Words_and_Numbers1)
{
   FILE* real;
   int test = 1;
    real=Words_and_Numbers("test/test.txt", test);
    ASSERT_NOT_NULL(real;
}
 CTEST(suite4, Words_and_Numbers2)
{
   FILE* real;
   int test = 1;
    real=Words_and_Numbers("rb.txt", test);
    ASSERT_NULL(real);
}
