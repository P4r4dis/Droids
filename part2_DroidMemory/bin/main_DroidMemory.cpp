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

    droidMemory += droidMemory;
    std::cout << "droidMemory.getExp after operator+= = " << droidMemory.getExp() << std::endl;
    droidMemory += 1;
    std::cout << "droidMemory.getExp after operator+= size_t = " << droidMemory.getExp() << std::endl;


    droidMemory = droidMemory + droidMemory;
    std::cout << "droidMemory.getExp after operator+   = " << droidMemory.getExp() << std::endl;
    droidMemory = droidMemory + 1;
    std::cout << "droidMemory.getExp after operator+ size_t = " << droidMemory.getExp() << std::endl;

    std::cout << "DroidMemory BattleData created during Droid construction :";
    Droid           droid("Avenger");
    std::cout   << "droid.getBattleData()->getExp() Exp = " 
                << droid.getBattleData()->getExp() 
                << " And droid.getBattleData()->getFingerPrint() FingerPrint = " 
                << droid.getBattleData()->getFingerPrint()
                << std::endl;
    droid.~Droid();

    DroidMemory     droidMemory2;
    droidMemory2 = droidMemory;
    if (droidMemory2 == droidMemory)
        std::cout << "droidMemory2 == droidMemory = true" << std::endl;
    else
        std::cout << "droidMemory2 == droidMemory = false" << std::endl;
    droidMemory2.setExp(0);

    if (droidMemory2 != droidMemory)
        std::cout << "droidMemory2 != droidMemory = true" << std::endl;
    else
        std::cout << "droidMemory2 != droidMemory = false" << std::endl;

    if (droidMemory2 < droidMemory)
        std::cout << "droidMemory2 < droidMemory = true" << std::endl;
    else
        std::cout << "droidMemory2 < droidMemory = false" << std::endl;

    if (droidMemory > droidMemory2)
        std::cout << "droidMemory > droidMemory2 = true" << std::endl;
    else
        std::cout << "droidMemory > droidMemory2 = false" << std::endl;

    if (droidMemory2 < droidMemory)
        std::cout << "droidMemory2 <= droidMemory = true" << std::endl;
    else
        std::cout << "droidMemory2 <= droidMemory = false" << std::endl;

    if (droidMemory >= droidMemory2)
        std::cout << "droidMemory >= droidMemory2 = true" << std::endl;
    else
        std::cout << "droidMemory >= droidMemory2 = false" << std::endl;

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
    std::cout << "REAL DROIDMEMORY MAIN :" << std::endl;
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
    
    return 0;
}