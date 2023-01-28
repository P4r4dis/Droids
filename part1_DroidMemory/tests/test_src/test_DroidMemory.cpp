#include "../test_include/test_DroidMemory.hpp"
#include <iostream>

DroidMemory::DroidMemory(size_t FingerPrint, size_t Exp) :  _FingerPrint(FingerPrint),
                                                            _Exp(Exp)
{
    std::cout << "DroidMemory '" << _FingerPrint << "', " << _Exp << std::endl;
}

DroidMemory::~DroidMemory(void)
{}

size_t      DroidMemory::getFingerPrint(void) const
{
    return _FingerPrint;
}

void        DroidMemory::setFingerPrint(size_t FingerPrint)
{
    _FingerPrint = FingerPrint;
}

size_t      DroidMemory::getExp(void) const
{
    return  _Exp;
}

void        DroidMemory::setExp(size_t Exp)
{
    _Exp = Exp;
}