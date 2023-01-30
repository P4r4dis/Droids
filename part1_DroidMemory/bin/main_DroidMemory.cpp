#include "../include/Droid.hpp"
#include "../include/DroidMemory.hpp"

#include <iostream>

int     main(void)
{
    // Droid   droid;

    // std::cout << "droid.getId = " << droid.getId() << std::endl;
    // std::cout << "droid.getEnergy = " << droid.getEnergy() << std::endl;
    // std::cout << "droid.getAttack = " << droid.getAttack() << std::endl;
    // std::cout << "droid.getToughness = " << droid.getToughness() << std::endl;
    // std::cout << "droid.getStatus = " << droid.getStatus()->data() << std::endl;

    // droid.setId("1");
    // std::cout << "droid.getId after setId = " << droid.getId() << std::endl;
    // droid.setEnergy(100);
    // std::cout << "droid.getEnergy after setEnergy = " << droid.getEnergy() << std::endl;
    // droid.setStatus(new std::string("Pending by"));
    // std::cout << "droid.getStatus after setStatus = " << droid.getStatus()->data() << std::endl;

    // Droid   droid_param("Samurai");
    // std::cout << "droid_param.getId = " << droid_param.getId() << std::endl;

    // Droid   copyDroid(droid);
    // std::cout << "copyDroid.getId = " << copyDroid.getId() << std::endl;

    // Droid   copyDroid_param(droid_param);
    // std::cout << "copyDroid_param.getId = " << copyDroid.getId() << std::endl;


    // std::cout << "droid after assignment operator overloaded = ";
    // droid = droid_param;
    // std::cout << "droid.getId = " << droid.getId() << std::endl;


    // bool result;
    // std::cout << "droid == droid_param -> operator == overloaded = ";
    // result = droid == droid_param;
    // std::cout << std::boolalpha << result << std::endl;

    // std::cout << "droid != droid_param -> operator != overloaded = ";
    // result = droid != droid_param;
    // std::cout << std::boolalpha << result << std::endl;

    // std::cout << "<< operator overloaded = ";
    // size_t durasel = 200;
    // droid << durasel;
    // std::cout << droid << "--" << durasel << std::endl;

    // std::cout << "droid destructor = ";
    // droid.~Droid();
    // std::cout << "copyDroid destructor = ";
    // copyDroid.~Droid();
    // std::cout << "droid_param destructor = ";
    // droid_param.~Droid();
    // std::cout << "copyDroid_param destructor = ";
    // copyDroid_param.~Droid();
    // std::cout << std::endl;

    DroidMemory     droidMemory;

    std::cout << "droidMemory.getFingerPrint = ";
    std::cout << droidMemory.getFingerPrint() << std::endl;
    std::cout << "droidMemory.getExp = ";
    std::cout << droidMemory.getExp() << std::endl;

    droidMemory.setFingerPrint(1);
    std::cout << "droidMemory.getFingerPrint after droidMemory.setFingerPrint = ";
    std::cout << droidMemory.getFingerPrint() << std::endl;
    droidMemory.setExp(1);
    std::cout << "droidMemory.getExp after droidMemory.setExp = ";
    std::cout << droidMemory.getExp() << std::endl;

    droidMemory << droidMemory;
    std::cout << "droidMemory.getExp after stream insetertion operator<< = " << droidMemory.getExp() << std::endl;
    std::cout << droidMemory << std::endl;

    droidMemory >> droidMemory;
    std::cout << "droidMemory.getExp after stream insetertion operator>> = " << droidMemory.getExp() << std::endl;
    std::cout << droidMemory << std::endl;
    std::cout << "REAL DROIDMEMORY MAIN :" << std::endl;
    
    return 0;
}