#include "../include/Droid.hpp"
#include "../include/DroidMemory.hpp"
#include "../include/Carrier.hpp"
#include "../include/Supply.hpp"
#include "../include/DroidFactory.hpp"

#include <iostream>

int     main(void)
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

    std::cout << "factory.getRatio = ";
    std::cout << factory.getRatio() << std::endl;
    std::cout << "factory.getSilicon = ";
    std::cout << factory.getSilicon() << std::endl;
    std::cout << "factory.getIron = ";
    std::cout << factory.getIron() << std::endl;
    std::cout << "factory.getExp = ";
    std::cout << factory.getExp() << std::endl;

    factory.setRatio(1);
    factory.setSilicon(1);
    factory.setIron(1);
    factory.setExp(1);

    std::cout << "factory.getRatio after setRadio = ";
    std::cout << factory.getRatio() << std::endl;
    std::cout << "factory.getSilicon after setSilicon = ";
    std::cout << factory.getSilicon() << std::endl;
    std::cout << "factory.getIron after setIron = ";
    std::cout << factory.getIron() << std::endl;
    std::cout << "factory.getExp after setExp = ";
    std::cout << factory.getExp() << std::endl;

    std::cout << "Overloading operator= factory = f : " << std::endl;
    factory = f;
    std::cout << "factory after override operator= =";
    std::cout   << "factory.getRatio = " << factory.getRatio() 
                << " f.getRatio = " << f.getRatio() << std::endl;
    std::cout   << " factory.getSilicon = " << factory.getSilicon() 
                << " f.getSilicon = " << f.getSilicon() << std::endl;
    std::cout   << "factory.getIron = " << factory.getIron() 
                << " f.getIron = " << f.getIron() << std::endl;
    std::cout   << "factory.getExp = " << factory.getExp() 
                << " f.getExp = " << f.getExp() << std::endl;

    factory.setRatio(3);
    factory.setSilicon(0);
    factory.setIron(0);
    factory.setExp(0);

    std::cout << "overloading operator>> = ";
    factory >> newbie;
    if (newbie == nullptr)
        std::cout << " newbie = nullptr = ok" << std::endl;
    

    std::cout << "REAL MAIN STARTING :--------------------------" << std::endl;

    return 0;
}