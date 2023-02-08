#include "../include/Supply.hpp"

Supply::Supply(Types Type, size_t Amount) :     _Types(Type), _Amount(Amount)
{}

Supply::Supply(Types Types, size_t Amount, Droid **Wrecks) :     _Types(Types),
                                                                _Amount(Amount),
                                                                _Wrecks(Wrecks),
                                                                _Index(0)
{}

Supply::Types           Supply::getTypes() const
{
    return _Types;
}

void                    Supply::setTypes(Types Types)
{
    _Types = Types;
}

size_t                  Supply::getAmount(void)
{
    return _Amount;
}

void                    Supply::setAmount(size_t Amount)
{
    _Amount = Amount;
}

Droid                   **Supply::getWrecks(void) const
{
    return _Wrecks;
}

Droid                   *Supply::getWrecks(int index) const
{
    return _Wrecks[index];
}

int                     Supply::getWrecksIndex(void) const
{
    return _Index;
}

void                    Supply::setWrecks(Droid **Wrecks)
{
    _Wrecks = Wrecks;
}

std::ostream            &operator<<(std::ostream &os, Supply &supply)
{
    os << "Supply : " << supply.getAmount() << ", ";
    if(supply.getTypes() == 1)
        os << "Silicon";
    else if(supply.getTypes() == 2)
        os << "Iron";
    else
        os << "Wreck" << std::endl;
    
    for (size_t i = 0; i < supply.getAmount(); i++)
    {
        if (supply.getWrecks(i))
        {
            os  << "Droid '" << supply.getWrecks(i)->getId() << "', " 
                << supply.getWrecks(i)->getStatus()->data()
                << ", " << supply.getWrecks(i)->getEnergy();
            if (i < 2)
                os << std::endl;
        }
    }
    return os;
}

Supply::operator size_t() const
{
    return _Amount;
}

Droid                   *Supply::operator*(void) const
{
    return _Wrecks[_Index];
}

Droid                   *Supply::operator->(void) const
{
    return _Wrecks[_Index];
}

Supply                  &Supply::operator--(void)
{
    if (_Wrecks)
    {
        _Index = (_Index + _Amount) - 1;
    }
    return *this;
}