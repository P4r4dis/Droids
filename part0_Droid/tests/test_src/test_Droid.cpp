#include "../test_include/test_Droid.hpp"
#include <iostream>

Droid::Droid(std::string Id) :  _Id(Id),
                                _Energy(50),
                                _Attack(25),
                                _Toughness(15),
                                _Status(std::make_unique<std::string>("Standing by"))//_Status(new std::string("Standing by"))
{
    std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copyDroid) :  _Id(copyDroid._Id),
                                        _Energy(copyDroid._Energy),
                                        _Attack(copyDroid._Attack),
                                        _Toughness(copyDroid._Toughness),
                                        _Status(std::make_unique<std::string>(*copyDroid._Status))//_Status(new std::string(*copyDroid._Status))
{
    std::cout << "Droid '" << copyDroid._Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void)
{
    if (_Status)
        std::cout << "Droid '" << _Id << "' Destroyed" << std::endl;
}

std::string     Droid::getId(void)
{
    return _Id;
}

void            Droid::setId(std::string Id)
{
    _Id = Id;
}

size_t          Droid::getEnergy(void)
{
    return _Energy;
}

void            Droid::setEnergy(size_t Energy)
{
    _Energy = Energy;
}

size_t          Droid::getAttack(void) const
{
    return _Attack;
}

size_t          Droid::getToughness(void) const
{
    return _Toughness;
}

std::string     *Droid::getStatus(void)
{
    // return _Status;
        return _Status.get();

}

void            Droid::setStatus(std::string *Status)
{
    // _Status = Status;
    _Status = std::make_unique<std::string>(*Status);
}
