#include "../test_include/test_Carrier.hpp"

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

std::string             Carrier::getId(void)
{
    return _Id;
}

size_t                  Carrier::getEnergy(void)
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

size_t                  Carrier::getSpeed(void)
{
    return _Speed;
}

std::shared_ptr<Droid>  Carrier::getDroids(int i)
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