#include "../src/libKBNinja/Comparator.h"
#include <ctest.h>
#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

CTEST(suite1, PUSTOI)
{
}
// Òåñòû äîëæåí ïðîâåðèòü, âûâîäèò ëè ôóíêöèÿ áóëåâñêèå ïåðåìåííûå.
CTEST(suite1, COMPARATOR_TEST1)
{
    char tval1 = '%';
    char tval2 = '%';
    bool qw = true;
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
