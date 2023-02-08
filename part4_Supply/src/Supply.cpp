#include "../include/Supply.hpp"

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