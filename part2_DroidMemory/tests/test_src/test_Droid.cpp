#include "../test_include/test_Droid.hpp"
#include <iostream>

Droid::Droid(std::string Id) :  _Id(Id),
                                _Energy(50),
                                _Attack(25),
                                _Toughness(15),
                                _Status(std::make_unique<std::string>("Standing by")),//_Status(new std::string("Standing by"))
                                BattleData(std::make_unique<DroidMemory>())
{
    std::cout << "Droid '" << _Id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &copyDroid) :  _Id(copyDroid._Id),
                                        _Energy(50),
                                        _Attack(copyDroid._Attack),
                                        _Toughness(copyDroid._Toughness),
                                        _Status(std::make_unique<std::string>(*copyDroid._Status)),
                                        BattleData(std::make_unique<DroidMemory>())//_Status(new std::string(*copyDroid._Status))
{
    std::cout << "Droid '" << copyDroid._Id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid(void)
{
    if (_Status)
        std::cout << "Droid '" << _Id << "' Destroyed" << std::endl;
}

std::string     Droid::getId(void) const
{
    return _Id;
}

void            Droid::setId(std::string Id)
{
    _Id = Id;
}

size_t          Droid::getEnergy(void) const
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

std::string     *Droid::getStatus(void) const
{
    // return _Status;
        return _Status.get();

}

void            Droid::setStatus(std::string *Status)
{
    // _Status = Status;
    _Status = std::make_unique<std::string>(*Status);
}

Droid           &Droid::operator=(const Droid &rhs)
{
    if(this != &rhs)
    {
        _Id = rhs._Id;
        _Energy = rhs._Energy;
        _Status = std::make_unique<std::string>(*rhs._Status);
        BattleData = std::make_unique<DroidMemory>(*rhs.BattleData);
    }
    return *this;
}

bool            Droid::operator==(const Droid &rhs)
{
    if (*_Status == *rhs._Status)
        return true;
    else
        return false;
}

bool            Droid::operator!=(const Droid &rhs)
{
    // return !(*this == rhs);
    if ((_Id != rhs._Id) || (_Energy != rhs._Energy) || (*_Status != *rhs._Status))
        return true;
    else
        return false;
}

Droid           &Droid::operator<<(size_t &Energy)
{	
    size_t      diff;
    size_t      max;
    size_t      min;

    max = 100;
    min = 0;

	if (_Energy < 100) {
		diff = std::min(max - _Energy, Energy);
		_Energy += diff;
		Energy -= diff;
	}

    if (_Energy > max)
        _Energy = max;
    else if (_Energy < min)
        _Energy = min;

    return *this;
}

std::ostream    &operator<<(std::ostream &os, const Droid& rhs)
{
    os  << "Droid '" << rhs.getId() << "', " << rhs.getStatus()->data()
        << ", " << rhs.getEnergy();
    return os;
}

bool            Droid::operator()(const std::string *Status, size_t Exp)
{
    if(_Energy < 10 || _Energy == 0)
    {
        _Energy = 0;
        _Status = std::make_unique<std::string>("Battery Low");
        BattleData->setExp(Exp);
        return false;
    }
    else if (_Energy >= 10 && BattleData->getExp() >= Exp)
    {
        _Energy -= 10;
        _Status = std::make_unique<std::string>(*Status + " - Completed!");
        BattleData->setExp(Exp / 2);
        return true;
    }
    else
    {
        _Energy -= 10;
        _Status = std::make_unique<std::string>(*Status + " - Failed!");
        BattleData->setExp(Exp);
        return false;
    }
    return true;
}

DroidMemory     *Droid::getBattleData(void) const
{
    return BattleData.get();
}

void            Droid::setBattleData(DroidMemory *droidMemory)
{
    BattleData = std::make_unique<DroidMemory>(*droidMemory);
}