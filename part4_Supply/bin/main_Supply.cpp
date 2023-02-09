#include "../include/Droid.hpp"
#include "../include/DroidMemory.hpp"
#include "../include/Carrier.hpp"
#include "../include/Supply.hpp"

#include <iostream>

int     main(void)
{
    Droid** wreck = new Droid*[10];
    char c = '0';
    for (int i = 0; i < 3; ++i) {
        wreck[i] = new Droid(std::string("wreck: ") + (char)(c + i));
    }
    Supply supp1(Supply::Silicon, 42);
    Supply supp2(Supply::Iron, 70);
    Supply supp3(Supply::Wreck, 3, wreck);
    std::cout << "s1.getTypes =";
    std::cout << supp1.getTypes() << std::endl;
    supp1.setTypes(Supply::Iron);
    std::cout << "s1.getTypes after setTypes =";
    std::cout << supp1.getTypes() << std::endl;
    supp1.setTypes(Supply::Silicon);

    std::cout << "s1.getAmount =";
    std::cout << supp1.getAmount() << std::endl;
    supp1.setAmount(5);
    std::cout << "s1.getAmount after setAmount =";
    std::cout << supp1.getAmount() << std::endl;
    supp1.setAmount(42);

    std::cout << "s3.getWrecks =";
    std::cout << supp3.getWrecks() << std::endl;

    std::cout << "overloading operator << =";
    std::cout << supp3 << std::endl;

    std::cout << "overloading operator size_t =";
    size_t supp = supp2;
    std::cout << supp << std::endl;  

    std::cout << "overloading operator * and -- =";
    std::cout << *(*(--supp3)) << std::endl;

    std::cout << "overloading operator -> =";
    std::cout << *(supp3)->getStatus() << std::endl;

    std::cout << "overloading operator ++ and =     :";
    ++supp3;
    *supp3 = 0;
    std::cout << *supp3 << std::endl;

    std::cout << supp2 << std::endl;


    std::cout << "overloading operator ==    =";
    if ((supp3 == supp3) == true)
    {
        std::cout << std::boolalpha << "supp3 == supp3 = " << (supp3 == supp3) << std::endl; 
    }
    std::cout << "overloading operator !=    =";
    if ((supp3 != supp2) == true)
    {
        std::cout << std::boolalpha << "supp3 != supp2 = " << (supp3 != supp2) << std::endl; 
    }
    std::cout << "REAL MAIN STARTING :--------------------------" << std::endl;    
    return 0;
}