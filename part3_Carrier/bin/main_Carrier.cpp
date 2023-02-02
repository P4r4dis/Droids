#include "../include/Droid.hpp"
#include "../include/DroidMemory.hpp"
#include "../include/Carrier.hpp"

#include <iostream>

int     main(void)
{
    Carrier     carrier("HellExpress");

    std::cout << "Carrier.getId = ";
    std::cout << carrier.getId() << std::endl;
    carrier.setId("New HellExpress");
    std::cout << "Carrier.getId After setId = ";
    std::cout << carrier.getId() << std::endl;


    std::cout << "Carrier.getEnergy = ";
    std::cout << carrier.getEnergy() << std::endl;
    carrier.setEnergy(200);
    std::cout << "Carrier.getEnergy After setEnergy = ";
    std::cout << carrier.getEnergy() << std::endl;
    carrier.setEnergy(300);

    std::cout << "Carrier.getAttack = ";
    std::cout << carrier.getAttack() << std::endl;

    std::cout << "Carrier.getToughness = ";
    std::cout << carrier.getToughness() << std::endl;

    std::cout << "Carrier.getSpeed = ";
    std::cout << carrier.getSpeed() << std::endl;
    carrier.setSpeed(200);
    std::cout << "Carrier.getSpeed After setSpeed = ";
    std::cout << carrier.getSpeed() << std::endl;
    carrier.setSpeed(100);

    for (int i = 0; i < 5; i++)
    {
        if (carrier.getDroids(i) == nullptr)
        {
            std::cout   << "carrier.getDroids(" << i 
                        << ") = NULLPTR -> GOOD" << std::endl;
        }
    }

    Droid *droid = new Droid("Commander");

    carrier.setDroids(0, droid);
    for (int i = 0; i < 5; i++)
    {
        if (carrier.getDroids(i) == nullptr)
        {
            std::cout   << "carrier.getDroids(" << i 
                        << ") = NULLPTR -> GOOD" << std::endl;
        }
        else
        {
            std::cout   << "carrier.getDroids(" << i 
                        << ") = carrier.getDroids()->getId = " 
                        << carrier.getDroids(i)->getId() << std::endl;           
        }
    }

    std::cout   << "carrier.getSpeed after Droids in  at board = "
                << carrier.getSpeed() << std::endl;   
    return 0;
}