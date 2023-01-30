#include "../test_include/test_DroidMemory.hpp"
#include <iostream>

DroidMemory::DroidMemory(size_t FingerPrint, size_t Exp) :  _FingerPrint(FingerPrint),
                                                            _Exp(Exp)
{}

DroidMemory::~DroidMemory(void)
{}

size_t          DroidMemory::getFingerPrint(void) const
{
    return _FingerPrint;
}

void            DroidMemory::setFingerPrint(size_t FingerPrint)
{
    _FingerPrint = FingerPrint;
}

size_t          DroidMemory::getExp(void) const
{
    return  _Exp;
}

void            DroidMemory::setExp(size_t Exp)
{
    _Exp = Exp;
}

DroidMemory     &DroidMemory::operator<<(const DroidMemory &rhs)
{
    _Exp += rhs._Exp;
    _FingerPrint ^= rhs._FingerPrint;
    return *this;
}

std::ostream    &operator<<(std::ostream& os, const DroidMemory& rhs)
{
    std::cout   << "DroidMemory '" << rhs.getFingerPrint() 
                << "', " << rhs.getExp();
    return os;
}

DroidMemory     &DroidMemory::operator>>(DroidMemory &lhs) const
{
    lhs._Exp = lhs._Exp + _Exp;
    lhs._FingerPrint ^= _FingerPrint;
    return lhs;
}
