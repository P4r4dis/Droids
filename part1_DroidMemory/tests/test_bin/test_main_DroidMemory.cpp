#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Droid.hpp"
#include "../test_include/test_DroidMemory.hpp"

#include <iostream>

Test(Droid, test_construction_whith_parameter, .init = redirect_all_stdout)
{
    Droid       droid("Avenger");

    cr_assert(droid.getId() == "Avenger");
    cr_assert(droid.getEnergy() == 50);
    cr_assert(droid.getAttack() == 25);
    cr_assert(droid.getToughness() == 15);
    cr_assert_str_eq(droid.getStatus()->c_str(), "Standing by");

    droid.setId("1");
    cr_assert(droid.getId() == "1");

    droid.setEnergy(100);
    cr_assert(droid.getEnergy() == 100);

    droid.setStatus(new std::string("Pending by"));
    cr_assert_str_eq(droid.getStatus()->c_str(), "Pending by");

    cr_assert_stdout_eq_str("Droid 'Avenger' Activated\n");
}

Test(Droid, test_construction_copyConstructor, .init = redirect_all_stdout)
{
    Droid       droid("");
    Droid       copyDroid(droid);

    cr_assert_neq(&droid, &copyDroid);

    cr_assert(droid.getId() == ""); //stdstring
    cr_assert(copyDroid.getId() == "");
    cr_assert(droid.getEnergy() == 50); //size_t
    cr_assert(copyDroid.getEnergy() == 50);
    cr_assert(droid.getAttack() == 25); //const size_t
    cr_assert(copyDroid.getAttack() == 25);
    cr_assert(droid.getToughness() == 15); //const size_t
    cr_assert(copyDroid.getToughness() == 15);

    cr_assert_str_eq(droid.getStatus()->c_str(), "Standing by"); //std::string *
    cr_assert_str_eq(copyDroid.getStatus()->c_str(), "Standing by");

    droid.setId("1");
    copyDroid.setId("1");
    cr_assert(droid.getId() == "1"); //stdstring
    cr_assert(copyDroid.getId() == "1");

    droid.setEnergy(100);
    copyDroid.setEnergy(100);
    cr_assert(droid.getEnergy() == 100); //size_t
    cr_assert(copyDroid.getEnergy() == 100);

    droid.setStatus(new std::string("Pending by"));
    copyDroid.setStatus(new std::string("Pending by"));
    cr_assert_str_eq(droid.getStatus()->c_str(), "Pending by"); //std::string *
    cr_assert_str_eq(copyDroid.getStatus()->c_str(), "Pending by");

    cr_assert_stdout_eq_str("Droid '' Activated\nDroid '' Activated, Memory Dumped\n");
}

Test(Droid, test_destruction, .init = redirect_all_stdout)
{
    Droid       droid("");

    droid.~Droid();
    cr_assert(droid.getStatus() == nullptr);
    cr_assert_stdout_eq_str("Droid '' Activated\nDroid '' Destroyed\n");
}

Test(Droid, test_overload_assigment_operator, .init = redirect_all_stdout)
{
    Droid       droid("");
    Droid       droid2("Avenger");

    droid = droid2;
    cr_assert(droid.getId() == droid2.getId());
    cr_assert(droid.getEnergy() == droid2.getEnergy());
    cr_assert(droid.getAttack() == droid2.getAttack());
    cr_assert(droid.getToughness() == droid2.getToughness());
    cr_assert_str_eq(droid.getStatus()->c_str(), droid2.getStatus()->c_str());
}

Test(Droid, test_overload_equal_operator, .init = redirect_all_stdout)
{
    Droid       droid("");
    Droid       droid2("");

    cr_assert(droid == droid2);
}

Test(Droid, test_overload_different_operator, .init = redirect_all_stdout)
{
    Droid       droid("");
    Droid       droid2("Avenger");

    cr_assert(droid != droid2);
}

Test(Droid, test_overload_stream_insertion_operator, .init = redirect_all_stdout)
{
    Droid       droid("");

    std::cout << droid << std::endl;
    cr_assert_stdout_eq_str("Droid '' Activated\nDroid '', Standing by, 50\n");
}

Test(Droid, test_overload_stream_insertion_operator_reload_Energy, .init = redirect_all_stdout)
{
    Droid d("");
    Droid d1("Avenger");
    size_t Durasel = 200;
    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1;
    d.setStatus(new std::string("Kill Kill Kill!"));
    d << Durasel;
    std::cout << d << "--" << Durasel << std::endl;
}

Test(Droid, test_main, .init = redirect_all_stdout)
{
    Droid d("");
    Droid d1("Avenger");
    size_t Durasel = 200;
    std::cout << d << std::endl;
    std::cout << d1 << std::endl;
    d = d1;
    d.setStatus(new std::string("Kill Kill Kill!"));
    d << Durasel;
    std::cout << d << "--" << Durasel << std::endl;
    Droid d2 = d;
    d.setId("Rex");
    std::cout << (d2 != d) << std::endl;

    d2.~Droid();
    d1.~Droid();
    d.~Droid();
    cr_assert_stdout_eq_str("Droid '' Activated\n\
Droid 'Avenger' Activated\n\
Droid '', Standing by, 50\n\
Droid 'Avenger', Standing by, 50\n\
Droid 'Avenger', Kill Kill Kill!, 100--150\n\
Droid 'Avenger' Activated, Memory Dumped\n\
1\n\
Droid 'Avenger' Destroyed\n\
Droid 'Avenger' Destroyed\n\
Droid 'Rex' Destroyed\n");
}

Test(DroidMemory, test_DroidMemory_Construction, .init = redirect_all_stdout)
{
    DroidMemory     droidMemory;

    cr_assert(droidMemory.getFingerPrint() >= 1 && droidMemory.getFingerPrint() <= SIZE_MAX);
    cr_assert(droidMemory.getExp() == 0);
    droidMemory.setFingerPrint(2);
    cr_assert(droidMemory.getFingerPrint() == 2);
    droidMemory.setExp(1);
    cr_assert(droidMemory.getExp() == 1);
    cr_assert_stdout_eq_str("DroidMemory '1804289383', 0\n");
}