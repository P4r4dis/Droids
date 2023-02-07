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

    Carrier     carrier2("HellExpress");

    Droid *droid1 = new Droid("Commander");
    Droid *droid2 = new Droid("Sergent");
    Droid *droid3 = new Droid("Troufiont");
    Droid *droid4 = new Droid("Groupie");
    Droid *droid5 = new Droid("BeerHolder");

    std::cout << "Overloading of << operator = ";
    carrier2 << droid1 << droid2 << droid3 << droid4 << droid5;
    std::cout <<carrier2.getSpeed() << droid1 << std::endl;
    std::cout <<carrier2 << std::endl;
    std::cout << "Overloading of >> operator = ";
    carrier2 >> droid1 >> droid2 >> droid3;
    std::cout <<carrier2.getSpeed() << std::endl;
    std::cout <<carrier2 << std::endl;
    std::cout << "Overloading of [] operator = ";
    carrier2[0] = droid1;
    std::cout <<carrier2.getSpeed() << std::endl;
    std::cout <<carrier2 << std::endl;
    std::cout << "Overloading of ~ operator = ";
    std::cout << (~carrier2).getSpeed() << std::endl;
    std::cout <<carrier2 << std::endl;
    std::cout << "Overloading of () operator = ";
    carrier2(4,2);
    std::cout <<carrier2 << std::endl;
    std::cout << "Carriercarrier2 after destruction = ";
    carrier2.~Carrier();
    std::cout <<carrier2 << std::endl;
    std::cout << "REAL MAIN STARTING :--------------------------" << std::endl;

    Carrier     c("HellExpress");

    Droid *d1 = new Droid("Commander");
    Droid *d2 = new Droid("Sergent");
    Droid *d3 = new Droid("Troufiont");
    Droid *d4 = new Droid("Groupie");
    Droid *d5 = new Droid("BeerHolder");

    c << d1 << d2 << d3 << d4 << d5;
    std::cout <<c.getSpeed() << d1 << std::endl;
    c >> d1 >> d2 >> d3;
    std::cout <<c.getSpeed() << std::endl;
    c[0] = d1;
    std::cout << (~c).getSpeed() << std::endl;
    carrier2(4,2);
    std::cout << c << std::endl;
    c(-15, 4);
    std::cout << c << std::endl;
    c[3] = 0;
    c[4] = 0;
    (~c)(-15, 4);
    std::cout << c << std::endl;
    
    return 0;
}