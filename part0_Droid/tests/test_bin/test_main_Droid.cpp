#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>

#include "../test_include/test_Droid.hpp"
#include <iostream>

Test(test, tests)
{
    cr_assert(1 == 1);
}