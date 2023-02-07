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

    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    std::cout << "Overloading of << operator = ";
    c << d1 << d2 << d3 << d4 << d5;
    std::cout << c.getSpeed() << d1 << std::endl;
    std::cout << c << std::endl;
    std::cout << "Overloading of >> operator = ";
    c >> d1 >> d2 >> d3;
    std::cout << c.getSpeed() << std::endl;
    std::cout << c << std::endl;
    std::cout << "Overloading of [] operator = ";
    c[0] = d1;
    std::cout << c.getSpeed() << std::endl;
    std::cout << c << std::endl;
    std::cout << "Overloading of ~ operator = ";
    std::cout << (~c).getSpeed() << std::endl;
    std::cout << c << std::endl;
    std::cout << "Overloading of () operator = ";
    c(4,2);
    std::cout << c << std::endl;
    std::cout << "Carrier c after destruction = ";
    c.~Carrier();
    std::cout << c << std::endl;
    return 0;
}