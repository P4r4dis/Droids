#include <criterion/criterion.h>
#include <criterion/new/assert.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <criterion/parameterized.h>
#include <signal.h>

#include "../test_include/test_Droid.hpp"
#include "../test_include/test_DroidMemory.hpp"
#include "../test_include/test_Carrier.hpp"
#include "../test_include/test_Supply.hpp"
#include "../test_include/test_DroidFactory.hpp"

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

    // std::cout   << "Exp = " << droid.getBattleData()->getExp() 
    //             << " And FingerPrint = " << droid.getBattleData()->getFingerPrint()
    //             << std::endl;
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


    // std::cout   << "Exp = " << copyDroid.getBattleData()->getExp() 
    //             << " And FingerPrint = " << copyDroid.getBattleData()->getFingerPrint()
    //             << std::endl;
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

Test(Droid, test_overload_operator_parenthesis, .init = redirect_all_stdout)
{
    Droid d("rudolf");
    Droid d2("gaston");
    size_t DuraSell = 40;

    d << DuraSell ;
    d.setStatus(new std::string("having some reset"));
    d2.setStatus( new std::string("having some reset"));

    if (d2 != d && !(d == d2))
        std::cout << "a droid is a droid, all its matter is what it 's doing" << std::endl;
    d(new std::string( "take a coffee"), 20);
    std::cout << d << std::endl;
    cr_assert(d.getEnergy() == 80);
    cr_assert_str_eq(d.getStatus()->c_str(), "take a coffee - Failed!");
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

Test(Droid, test_main_part2, .init = redirect_all_stdout)
{
    Droid d("rudolf");
    Droid d2("gaston");
    size_t DuraSell = 40;

    d << DuraSell;
    d.setStatus(new std::string("having some reset"));
    d2.setStatus( new std::string("having some reset"));

    if (d2 != d && !(d == d2))
    {
        std::cout << "a droid is a droid, all its matter is what it 's doing" << std::endl;
    }
    d(new std::string("take a coffee"), 20);
    std::cout << d << std::endl;
    while (d(new std::string("Patrol around"), 20))
    {
        if (!d(new std::string("Shoot some ennemies"), 50))
        {
            d(new std::string("Run Away"), 20);
        }
        std::cout << d << std::endl;
    }
    std::cout << d << std::endl;

    d2.~Droid();
    d.~Droid();
    cr_assert_stdout_eq_str("Droid 'rudolf' Activated\n\
Droid 'gaston' Activated\n\
Droid 'rudolf', take a coffee - Failed!, 80\n\
Droid 'rudolf', Run Away - Completed!, 50\n\
Droid 'rudolf', Shoot some ennemies - Completed!, 30\n\
Droid 'rudolf', Shoot some ennemies - Completed!, 10\n\
Droid 'rudolf', Battery Low, 0\n\
Droid 'gaston' Destroyed\n\
Droid 'rudolf' Destroyed\n");
}

Test(DroidMemory, test_DroidMemory_Construction)
{
    DroidMemory     droidMemory;

    cr_assert(droidMemory.getFingerPrint() >= 1 && droidMemory.getFingerPrint() <= SIZE_MAX);
    cr_assert(droidMemory.getExp() == 0);
    droidMemory.setFingerPrint(2);
    cr_assert(droidMemory.getFingerPrint() == 2);
    droidMemory.setExp(1);
    cr_assert(droidMemory.getExp() == 1);
}

Test(DroidMemory, test_DroidMemory_stream_insertion_rhs_operator, .init = redirect_all_stdout)
{

    DroidMemory     droidMemory;
    droidMemory.setExp(10);

    DroidMemory     droidMemory2;
    droidMemory2.setExp(10);

    droidMemory << droidMemory2 << droidMemory;
    cr_assert(droidMemory.getExp() == 40);
    cr_assert(droidMemory2.getExp() == 10);
    cr_assert(droidMemory.getFingerPrint() == 0);
    cr_assert(droidMemory2.getFingerPrint() == 846930886);
    std::cout << droidMemory << std::endl;
    cr_assert_stdout_eq_str("DroidMemory '0', 40\n");
}

Test(DroidMemory, test_DroidMemory_stream_insertion_lhs_operator, .init = redirect_all_stdout)
{

    DroidMemory     droidMemory;
    droidMemory.setExp(10);

    DroidMemory     droidMemory2;
    droidMemory2.setExp(10);

    droidMemory >> droidMemory2 >> droidMemory;
    cr_assert(droidMemory.getExp() == 30);
    cr_assert(droidMemory2.getExp() == 20);
    cr_assert(droidMemory.getFingerPrint() == 846930886);
    cr_assert(droidMemory2.getFingerPrint() == 1508927137);
    std::cout << droidMemory << std::endl;
    cr_assert_stdout_eq_str("DroidMemory '846930886', 30\n");
}

Test(DroidMemory, test_DroidMemory_operator_plusEqual)
{

    DroidMemory     droidMemory;
    droidMemory.setExp(10);

    DroidMemory     droidMemory2;
    droidMemory2.setExp(10);

    droidMemory += droidMemory2;
    cr_assert(droidMemory.getExp() == 20);
    cr_assert(droidMemory2.getExp() == 10);
    cr_assert(droidMemory.getFingerPrint() == 1508927137);
    cr_assert(droidMemory2.getFingerPrint() == 846930886);
    // std::cout << droidMemory << std::endl;

    droidMemory += 42;
    cr_assert(droidMemory.getExp() == 62);
    cr_assert(droidMemory.getFingerPrint() == 1508927115);
}

Test(DroidMemory, test_DroidMemory_operator_plus)
{

    DroidMemory     droidMemory;
    droidMemory.setExp(10);
    cr_assert(droidMemory.getExp() == 10);

    DroidMemory     droidMemory2;
    droidMemory2.setExp(10);
    cr_assert(droidMemory2.getExp() == 10);

    DroidMemory     droidMemory3;
    cr_assert(droidMemory3.getExp() == 0);
    droidMemory3 = droidMemory + droidMemory2;
    cr_assert(droidMemory3.getExp() == 20);
    droidMemory3 = droidMemory3 + 10;
    cr_assert(droidMemory3.getExp() == 30);
}

Test(DroidMemory, test_DroidMemory_operator_EqualEqual)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2 = mem1;
    cr_assert(mem1 == mem2);
}

Test(DroidMemory, test_DroidMemory_operator_Different)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2;
    cr_assert(mem1 != mem2);
}

Test(DroidMemory, test_DroidMemory_operator_lower)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2;
    cr_assert(mem2 < mem1);
    cr_assert(mem1 < 100);
}


Test(DroidMemory, test_DroidMemory_operator_higher)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2;
    cr_assert(mem1 > mem2);
    cr_assert(mem1 > 0);
}

Test(DroidMemory, test_DroidMemory_operator_lowerOrEqual)
{
    DroidMemory     mem1;
    mem1 += 42;

    size_t test = 0;
    DroidMemory mem2;
    cr_assert(mem2 <= mem1);
    cr_assert(mem2 <= test);
}

Test(DroidMemory, test_DroidMemory_operator_higherOrEqual)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2;
    cr_assert(mem1 >= mem2);
    cr_assert(mem1 >= 42);
}


Test(DroidMemory, test_DroidMemory_main, .init = redirect_all_stdout)
{
    DroidMemory     mem1;
    mem1 += 42;

    DroidMemory mem2 = mem1;
    std::cout << mem1 << std::endl;

    DroidMemory mem3;
    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;
    std::cout << mem3 << std::endl;
    std::cout << mem1 << std::endl;
    cr_assert_stdout_eq_str("DroidMemory '1804289357', 42\n\
DroidMemory '1804289357', 126\n\
DroidMemory '846930886', 84\n");
}

Test(DroidMemory, test_DroidMemory_main2, .init = redirect_all_stdout)
{
    DroidMemory mem1;
    mem1 += 42;
    std::cout << mem1 << std::endl;
    DroidMemory mem2;
    mem2 << mem1;
    mem2 >> mem1;
    mem2 << mem1;
    std::cout << mem2 << std::endl;
    std::cout << mem1 << std::endl;

    DroidMemory mem3 = mem1;
    DroidMemory mem4;
    mem4 = mem1 + mem3;
    cr_assert_stdout_eq_str("DroidMemory '1804289357', 42\n\
DroidMemory '1804289357', 126\n\
DroidMemory '846930886', 84\n");
}

Test(Carrier, test_Carrier_construction, .init = redirect_all_stdout)
{
    Carrier     carrier("HellExpress");

    cr_assert(carrier.getId() == "HellExpress");
    carrier.setId("H");
    cr_assert(carrier.getId() == "H");

    cr_assert(carrier.getEnergy() == 300);
    carrier.setEnergy(0);
    cr_assert(carrier.getEnergy() == 0);

    cr_assert(carrier.getAttack() == 100);
    cr_assert(carrier.getToughness() == 90);
    cr_assert(carrier.getSpeed() == 0);
    carrier.setSpeed(100);
    cr_assert(carrier.getSpeed() == 100);

    cr_assert_eq(carrier.getDroids(0), nullptr);
    cr_assert(carrier.getDroids(1) == nullptr);
    cr_assert(carrier.getDroids(2) == nullptr);
    cr_assert(carrier.getDroids(3) == nullptr);
    Droid *droid = new Droid("TEST");
    carrier.setDroids(4, droid);
    cr_assert(carrier.getDroids(4) != nullptr);
    cr_assert(carrier.getDroids(4)->getId() == "TEST");
    std::cout << carrier.getSpeed() << std::endl;

    Carrier     carrier2;

    cr_assert(carrier2.getId() == "");
    cr_assert(carrier2.getEnergy() == 300);
    cr_assert(carrier2.getAttack() == 100);
    cr_assert(carrier2.getToughness() == 90);
    cr_assert(carrier2.getSpeed() == 0);
    cr_assert(carrier2.getDroids(0) == nullptr);
    cr_assert(carrier2.getDroids(1) == nullptr);
    cr_assert(carrier2.getDroids(2) == nullptr);
    cr_assert(carrier2.getDroids(3) == nullptr);
    cr_assert(carrier2.getDroids(4) == nullptr);
}

Test(Carrier, test_Carrier_stream_insertion_rhs, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    cr_assert(c.getSpeed() == 0);

    cr_assert(c.getDroids(0) == nullptr);
    cr_assert(c.getDroids(1) == nullptr);
    cr_assert(c.getDroids(2) == nullptr);
    cr_assert(c.getDroids(3) == nullptr);
    cr_assert(c.getDroids(4) == nullptr);

    // c << d1 << d4 << d5;
    c << d1 << d2 << d3 << d4 << d5;

    cr_assert(c.getDroids(0) != nullptr);
    cr_assert(c.getDroids(1) != nullptr);
    cr_assert(c.getDroids(2) != nullptr);
    cr_assert(c.getDroids(3) != nullptr);
    cr_assert(c.getDroids(4) != nullptr);

    cr_assert(c.getDroids(0)->getId() == "Commander");
    cr_assert(c.getDroids(1)->getId() == "Sergent");
    cr_assert(c.getDroids(2)->getId() == "Troufiont");
    cr_assert(c.getDroids(3)->getId() == "Groupie");
    cr_assert(c.getDroids(4)->getId() == "BeerHolder");

    cr_assert(c.getSpeed() == 50);
    std::cout << c.getSpeed() << d1 << std::endl;
    std::cout << c << std::endl;
}

Test(Carrier, test_Carrier_stream_insertion_lhs, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;

    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
}


Test(Carrier, test_Carrier_destruction, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;

    c.~Carrier();
    std::cout << c << std::endl;
}

Test(Carrier, test_Carrier_subscript_operator, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << c << std::endl;
}

Test(Carrier, test_Carrier_bitwise_operator, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    std::cout << c << std::endl;
}

Test(Carrier, test_Carrier_parenthesis_operator, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    cr_assert(c(4, 2) == true);
    cr_assert(c(4, 2) == true);
    cr_assert(c(4, 2) == true);
    cr_assert(c(4, 2) == false);
    std::cout << c << std::endl;
}

Test(Carrier, test_Carrier_main, .init = redirect_all_stdout)
{
    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    c(4, 2);
    std::cout << c << std::endl;
    c(-15, 4);
    std::cout << c << std::endl;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std::cout << c << std::endl;
    c.~Carrier();
}

Test(Supply, test_Supply_Construction, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);

    cr_assert(s1.getTypes() == Supply::Silicon);
    cr_assert(s2.getTypes() == Supply::Iron);
    cr_assert(s3.getTypes() == Supply::Wreck);
    s1.setTypes(Supply::Iron);
    cr_assert(s1.getTypes() == Supply::Iron);

    cr_assert(s1.getAmount() == 42);
    s1.setAmount(5);
    cr_assert(s1.getAmount() == 5);

    cr_assert(s2.getAmount() == 70);
    cr_assert(s3.getAmount() == 3);

    cr_assert(s3.getWrecks() == w);

    s1.setWrecks(w);
    cr_assert(s1.getWrecks() == w);

}

Test(Supply, test_Supply_stream_insertion_rhs_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);

    std::cout << s3 << std::endl;
//     cr_assert_stdout_eq_str("Droid 'wreck: 0' Activated\n
// Droid 'wreck: 1' Activated\n
// Droid 'wreck: 2' Activated\n
// Supply : 3, Wreck\n");

    cr_assert_stdout_eq_str("Droid 'wreck: 0' Activated\n\
Droid 'wreck: 1' Activated\n\
Droid 'wreck: 2' Activated\n\
Supply : 3, Wreck\n\
Droid 'wreck: 0', Standing by, 50\n\
Droid 'wreck: 1', Standing by, 50\n\
Droid 'wreck: 2', Standing by, 50\n");
}

Test(Supply, test_Supply_size_t_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);

    std::cout << s3 << std::endl;
    size_t s = s2;
    std::cout << s << std::endl;
    cr_assert_stdout_eq_str("Droid 'wreck: 0' Activated\n\
Droid 'wreck: 1' Activated\n\
Droid 'wreck: 2' Activated\n\
Supply : 3, Wreck\n\
Droid 'wreck: 0', Standing by, 50\n\
Droid 'wreck: 1', Standing by, 50\n\
Droid 'wreck: 2', Standing by, 50\n\
70\n");
}

Test(Supply, test_Supply_indirection_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(*(s3)) << std::endl;
    // cr_assert((*(*(s3))).getId() == )
}

Test(Supply, test_Supply_arrow_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(s3)->getStatus() << std::endl;
    // cr_assert((*(*(s3))).getId() == )
}

Test(Supply, test_Supply_Decrement_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(*(--s3)) << std::endl;
    // cr_assert((*(*(s3))).getId() == )
}

Test(Supply, test_Supply_increment_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
}

Test(Supply, test_Supply_equalEqual_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    cr_assert(s3 == s3);
}

Test(Supply, test_Supply_different_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    cr_assert(s3 != s2);
}

Test(Supply, test_Supply_not_operator, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << !s3 << std::endl;

    cr_assert(s3.getAmount() == 0);
    for (size_t i = 0; i < s3.getAmount(); i++)
    {
        cr_assert(s3.getWrecks(i) == nullptr);
    }
}

Test(Supply, test_Supply_destruction, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);
    cr_assert(s3.getWrecksIndex() == 0);
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << !s3 << std::endl;

    // cr_assert(s3.getAmount() == 0);

    // s1.~Supply();
    // s2.~Supply();
    s3.~Supply();
    for (size_t i = 0; i < s3.getAmount(); i++)
    {
        cr_assert(s3.getWrecks(i) == nullptr);
    }
}


Test(Supply, test_Supply_main, .init = redirect_all_stdout)
{
    Droid** w = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply s1(Supply::Silicon, 42);
    Supply s2(Supply::Iron, 70);
    Supply s3(Supply::Wreck, 3, w);

    std::cout << s3 << std::endl;
    size_t s = s2;
    std::cout << s << std::endl;
    std::cout << *(*(--s3)) << std::endl;
    std::cout << *(++s3)->getStatus() << std::endl;
    ++s3;
    *s3 = 0;
    std::cout << *s3 << std::endl;
    std::cout << s2 << std::endl;
    std::cout << !s3 << std::endl;

    cr_assert_stdout_eq_str("Droid 'wreck: 0' Activated\n\
Droid 'wreck: 1' Activated\n\
Droid 'wreck: 2' Activated\n\
Supply : 3, Wreck\n\
Droid 'wreck: 0', Standing by, 50\n\
Droid 'wreck: 1', Standing by, 50\n\
Droid 'wreck: 2', Standing by, 50\n\
70\n\
Droid 'wreck: 2', Standing by, 50\n\
Standing by\n\
0\n\
Supply : 70, Iron\n\
Droid 'wreck: 0' Destroyed\n\
Droid 'wreck: 2' Destroyed\n\
Supply : 0, Wreck\n");
}

Test(DroidFactory, test_DroidFactory_Construction, .init = redirect_all_stdout)
{
    DroidFactory    factory(3);
    DroidFactory    f;
    Droid           **w = new Droid*[10];
    // Droid           *newbie;
    char            c = '0';

    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
        *(w[i]->getBattleData()) += (i * 100);
    }

    Supply          s1(Supply::Silicon, 42);
    Supply          s2(Supply::Iron, 70);
    Supply          s3(Supply::Wreck, 3, w);

    cr_assert(factory.getRatio() == 3);
    cr_assert(factory.getSilicon() == 0);
    cr_assert(factory.getIron() == 0);
    cr_assert(factory.getExp() == 0);

    factory.setRatio(1);
    factory.setSilicon(1);
    factory.setIron(1);
    factory.setExp(1);

    cr_assert(factory.getRatio() == 1);
    cr_assert(factory.getSilicon() == 1);
    cr_assert(factory.getIron() == 1);
    cr_assert(factory.getExp() == 1);

    factory = f;

    cr_assert(factory.getRatio() == 2);
    cr_assert(factory.getSilicon() == 0);
    cr_assert(factory.getIron() == 0);
    cr_assert(factory.getExp() == 0);
}

Test(DroidFactory, test_DroidFactory_stream_extraction_operator)//, .init = redirect_all_stdout)
{
    DroidFactory    factory(3);
    DroidFactory    f;
    Droid           **w = new Droid*[10];
    Droid           *newbie;
    char            c = '0';

    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
        *(w[i]->getBattleData()) += (i * 100);
    }

    Supply          s1(Supply::Silicon, 42);
    Supply          s2(Supply::Iron, 70);
    Supply          s3(Supply::Wreck, 3, w);

    factory >> newbie;
    cr_assert(newbie == nullptr);
    std::cout << newbie << std::endl;
    factory << s1 << s2;
    std::cout << factory << std::endl;
}

Test(DroidFactory, test_DroidFactory_stream_insertion_operator, .init = redirect_all_stdout)
{
    DroidFactory    factory(3);
    DroidFactory    f;
    Droid           **w = new Droid*[10];
    Droid           *newbie;
    char            c = '0';

    for (int i = 0; i < 3; ++i) {
        w[i] = new Droid(std::string("wreck: ") + (char)(c + i));
        *(w[i]->getBattleData()) += (i * 100);
    }

    Supply          s1(Supply::Silicon, 42);
    Supply          s2(Supply::Iron, 70);
    Supply          s3(Supply::Wreck, 3, w);

    factory >> newbie;
    std::cout << newbie << std::endl;

    factory << s1 << s2;
    std::cout << factory << std::endl;
    s3 >> factory >> newbie;
    std::cout << factory << std::endl;
}
