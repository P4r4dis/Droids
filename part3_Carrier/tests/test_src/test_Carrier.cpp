#include "../test_include/test_Carrier.hpp"
#include <iostream>

Carrier::Carrier(std::string Id) :  _Id(Id), _Energy(300), _Attack(100),
                                    _Toughness(90), _Speed(0)
{
    for (int i = 0; i < 5; i++) {
        _Droids[i] = nullptr;
    }
}

Carrier::~Carrier(void)
{
    for (int i = 0; i < 5; i++) {
        if (_Droids[i])
            delete _Droids[i];
        _Droids[i] = nullptr;
    }
}

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

Droid                   *Carrier::getDroids(int i) const
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
    _Droids[i] = Droids;
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
            _Droids[i] = rhs;
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
            lhs = _Droids[i];
            _Droids[i] = nullptr;
            for (int j = 0; j < 5; j++)
                if(_Droids[j] != nullptr)
                    nbDroids++;

            _Speed = 100 - (nbDroids * 10);

            return *this;
        }
    }

    return *this;
}

Droid                   *&Carrier::operator[](const size_t index)
{
    return _Droids[index];
}

Carrier                 &Carrier::operator~()
{
    size_t nbDroids = 0;

    for (int i = 0; i < 5; i++)
    {
        if (_Droids[i] != nullptr)
            nbDroids++;
    }
     _Speed = 100 - (nbDroids * 10);

    return *this;
}

bool                    Carrier::operator()(int x, int y)
{
    size_t  NbDroid = 0;
    size_t  EnergyCost = 0;

    for (int i = 0; i < 5; i++)
        if (_Droids[i])
            NbDroid++;
    EnergyCost = (abs(x) + abs(y)) * (10 + NbDroid);
    if (_Energy < EnergyCost || _Speed == 0)
        return false;
    _Energy -= EnergyCost;
    return true;
}