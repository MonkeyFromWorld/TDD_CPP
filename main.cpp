#include <iostream>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include "range.h"
using namespace std;

static int main_ret = 0;
static int test_count = 0;
static int test_pass = 0;

#define EXPECT_EQ_BASE(equality, expect, actual, formal)\
    do {\
        test_count++;\
        if(equality)\
            test_pass++;\
        else {\
            fprintf(stderr, "%s:%d: expect: " formal "  actual: " formal "\n", __FILE__, __LINE__, expect, actual);\
            main_ret = 1;\
        }\
    } while(0)

#define EXPECT_EQ_STR(expect, actual) EXPECT_EQ_BASE((expect) == (actual) , expect, actual, "%s")

static void test_str_null() {
    EXPECT_EQ_STR(LEPT_EQUAL, strcmp("aa", "aa") == 0);
    EXPECT_EQ_STR(LEPT_UNEQUAL, strcmp("aa", "a") == 0);
}

static void test() {
        test_str_null();
    }

int main() {
    test();
    cout.setf(ios::fixed);
    cout << test_pass << "/" << test_count << ", ";
    cout << setprecision(2) << test_pass*100/test_count << "% are passed!" <<endl;
    cout.unsetf(ios::fixed);
    return main_ret;
}