#include "../test_include/test_Supply.hpp"
#include <iostream>

Supply::Supply(Types Type, size_t Amount) :     _Types(Type), _Amount(Amount)
{}

Supply::Supply(Types Types, size_t Amount, Droid **Wrecks) :     _Types(Types),
                                                                _Amount(Amount),
                                                                _Wrecks(Wrecks)
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

Droid                   **Supply::getWrecks(void)
{
    return _Wrecks;
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
        os << "Wreck";
    return os;
}