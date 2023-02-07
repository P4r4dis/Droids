#include "../test_include/test_Carrier.hpp"
#include <iostream>

// Carrier::Carrier(void) :    _Id(""), _Energy(300), _Attack(100),
//                             _Toughness(90), _Speed(0)
// {
//     for (int i = 0; i <= 5; i++)
//         _Droids[i] = nullptr;
// }

Carrier::Carrier(std::string Id) :  _Id(Id), _Energy(300), _Attack(100),
                                    _Toughness(90), _Speed(0)
{
    for (int i = 0; i < 5; i++) {
        _Droids[i] = nullptr;
    }
}

Carrier::~Carrier(void)
{}

std::string             Carrier::getId(void) const
{
    return _Id;
}

size_t                  Carrier::getEnergy(void) const
{
    return _Energy;
}

size_t                  Carrier::getAttack(void) const
{
    return _Attack;
}

size_t                  Carrier::getToughness(void) const
{
    return _Toughness;
}

size_t                  Carrier::getSpeed(void) const
{
    return _Speed;
}

std::shared_ptr<Droid>  Carrier::getDroids(int i) const
{
    return _Droids[i];
}

void                    Carrier::setId(std::string Id)
{
    _Id = Id;
}

void                    Carrier::setEnergy(size_t Energy)
{
    _Energy = Energy;
}

void                    Carrier::setSpeed(size_t Speed)
{
    _Speed = Speed;
}

void                    Carrier::setDroids(int i, Droid *Droids)
{
    size_t nbDroid;

    nbDroid = 0;
    _Droids[i] = std::shared_ptr<Droid>(Droids);
    if (Droids)
    {
        for(int j = 0; j < 5; j++)
        {
            if (_Droids[j])
                nbDroid++;
        }
        _Speed = 100 - (nbDroid * 10);
    }
    else
        _Speed = 0;
}

Carrier                 &Carrier::operator<<(Droid *&rhs)
{
    size_t nbDroids = 0;

    for (int i = 0; i < 5; i++)
    {
        if (_Droids[i] == nullptr)
        {
            _Droids[i] = std::shared_ptr<Droid>(rhs);
            for (int j = 0; j < 5; j++)
                if(_Droids[j] != nullptr)
                    nbDroids++;

            _Speed = 100 - (nbDroids * 10);
            rhs = nullptr;

             return *this;
        }
    }

    return *this;
}

std::ostream             &operator<<(std::ostream &os, const Carrier &rhs)
{
    std::cout   << "Carrier '" << rhs.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << "[" << i << "] : ";
        if (rhs.getDroids(i))
        {
            std::cout   << "Droid '" << rhs.getDroids(i)->getId() << "', "
                        << rhs.getDroids(i)->getStatus()->data() << ", "
                        << rhs.getDroids(i)->getEnergy();
        }
        else
        {
            std::cout << "Free";
        }
        std::cout << std::endl;
    }
    std::cout   << "Speed : " << rhs.getSpeed() << ", Energy " << rhs.getEnergy();

    return os;
}

Carrier                 &Carrier::operator>>(Droid  *&lhs)
{
    size_t nbDroids = 0;

    for (int i = 0; i < 5; i++)
    {
        if (_Droids[i] != nullptr)
        {
            _Droids[i] = nullptr;//std::shared_ptr<Droid>(lhs);
            for (int j = 0; j < 5; j++)
                if(_Droids[j] != nullptr)
                    nbDroids++;

            _Speed = 100 - (nbDroids * 10);
            lhs = nullptr;

             return *this;
        }
    }
    
    return *this;
}