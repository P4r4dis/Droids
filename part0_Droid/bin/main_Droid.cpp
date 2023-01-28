#include "../include/Droid.hpp"
#include <iostream>

int     main(void)
{
    Droid   droid;

    std::cout << "droid.getId = " << droid.getId() << std::endl;
    std::cout << "droid.getEnergy = " << droid.getEnergy() << std::endl;
    std::cout << "droid.getAttack = " << droid.getAttack() << std::endl;
    std::cout << "droid.getToughness = " << droid.getToughness() << std::endl;
    std::cout << "droid.getStatus = " << droid.getStatus()->data() << std::endl;

    droid.setId("1");
    std::cout << "droid.getId after setId = " << droid.getId() << std::endl;
    droid.setEnergy(100);
    std::cout << "droid.getEnergy after setEnergy = " << droid.getEnergy() << std::endl;
    droid.setStatus(new std::string("Pending by"));
    std::cout << "droid.getStatus after setStatus = " << droid.getStatus()->data() << std::endl;

    Droid   droid_param("Samurai");
    std::cout << "droid_param.getId = " << droid_param.getId() << std::endl;

    Droid   copyDroid(droid);
    std::cout << "copyDroid.getId = " << copyDroid.getId() << std::endl;

    Droid   copyDroid_param(droid_param);
    std::cout << "copyDroid_param.getId = " << copyDroid.getId() << std::endl;


    std::cout << "droid after assignment operator overloaded = ";
    droid = droid_param;
    std::cout << "droid.getId = " << droid.getId() << std::endl;


    bool result;
    std::cout << "droid == droid_param -> operator == overloaded = ";
    result = droid == droid_param;
    std::cout << std::boolalpha << result << std::endl;

    std::cout << "droid != droid_param -> operator != overloaded = ";
    result = droid != droid_param;
    std::cout << std::boolalpha << result << std::endl;

    std::cout << "<< operator overloaded = ";
    size_t durasel = 200;
    droid << durasel;
    std::cout << droid << "--" << durasel << std::endl;

    std::cout << "droid destructor = ";
    droid.~Droid();
    std::cout << "copyDroid destructor = ";
    copyDroid.~Droid();
    std::cout << "droid_param destructor = ";
    droid_param.~Droid();
    std::cout << "copyDroid_param destructor = ";
    copyDroid_param.~Droid();
    std::cout << std::endl;

    std::cout << "REAL DROID MAIN :" << std::endl;
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
    
    return 0;
}