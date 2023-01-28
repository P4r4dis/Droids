#include "../part0_Droid/include/Droid.hpp"
#include <iostream>

int     main(void)
{
    std::cout << "PART 0 - Droid MAIN - START :" << std::endl;
    Droid   d;
    Droid   d1("Avenger");
    size_t  Durasel = 200;

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
    std::cout << "PART 0 - Droid MAIN - END :" << std::endl;


    return 0;
}