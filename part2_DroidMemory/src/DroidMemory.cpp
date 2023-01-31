#include "../include/DroidMemory.hpp"

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

DroidMemory     &DroidMemory::operator+=(const DroidMemory &rhs)
{
    _Exp += rhs._Exp;
    _FingerPrint ^= rhs._FingerPrint;

    return *this;
}

DroidMemory     &DroidMemory::operator+=(const size_t rhs)
{
    _Exp += rhs;
    _FingerPrint ^= rhs;

    return *this;
}

DroidMemory     &DroidMemory::operator+(const DroidMemory &rhs) const
{
    DroidMemory     *droidMemory = new DroidMemory;

    droidMemory->_Exp = _Exp + rhs._Exp;
    droidMemory->_FingerPrint = _FingerPrint ^ rhs._FingerPrint;

    return *droidMemory; 
}

DroidMemory     &DroidMemory::operator+(const size_t &rhs) const
{
    DroidMemory     *droidMemory = new DroidMemory;

    droidMemory->_Exp = _Exp + rhs;
    droidMemory->_FingerPrint = _FingerPrint ^ rhs;

    return *droidMemory; 
}


bool            DroidMemory::operator==(const DroidMemory &rhs) const
{
    if (_Exp == rhs.getExp() && _FingerPrint == rhs.getFingerPrint())
        return true;
    else
        return false;
}

bool            DroidMemory::operator!=(const DroidMemory &rhs)
{
    if (_Exp != rhs._Exp || _FingerPrint != rhs._FingerPrint)
        return true;
    else
        return false;
}
