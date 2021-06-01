#include "../src/libKBNinja/Prepare.h"
#include <ctest.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// Тесты будут проверять, что будет, если ввести mode и difficult > 3 или < 0
CTEST(suite5, PUSTOI)
{
}
CTEST(suite5, Prepare1)
{
    int tmode = 4, tdif = 1, test = 1, n, k = 1;
    n = Prepare(&tmode, &tdif, test);
    ASSERT_EQUAL(k, n);
}
CTEST(suite5, Prepare2)
{
    int tmode = 1, tdif = 4, test = 1, n, k = 1;
    n = Prepare(&tmode, &tdif, test);
    ASSERT_EQUAL(k, n);
}
