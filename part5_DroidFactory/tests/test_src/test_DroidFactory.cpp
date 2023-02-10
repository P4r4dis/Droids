#include "../test_include/test_DroidFactory.hpp"

DroidFactory::DroidFactory(size_t ratio) :  _ratio(ratio), _Silicon(0), _Iron(0), _Exp(0)
{}

DroidFactory::DroidFactory(const DroidFactory &copyDroidFactory) :  _ratio(copyDroidFactory._ratio),
                                                                    _Silicon(copyDroidFactory._Silicon),
                                                                    _Iron(copyDroidFactory._Iron),
                                                                    _Exp(copyDroidFactory._Exp)
{}

DroidFactory::~DroidFactory(void)
{}


size_t                  DroidFactory::getRatio(void) const
{
    return _ratio;
}

size_t                  DroidFactory::getSilicon(void) const
{
    return _Silicon;
}

size_t                  DroidFactory::getIron(void) const
{
    return _Iron;
}

size_t                  DroidFactory::getExp(void) const
{
    return _Exp;
}

void                    DroidFactory::setRatio(const size_t ratio)
{
    _ratio = ratio;
}

void                    DroidFactory::setSilicon(const size_t Silicon)
{
    _Silicon = Silicon;
}

void                    DroidFactory::setIron(const size_t Iron)
{
    _Iron = Iron;
}

void                    DroidFactory::setExp(const size_t Exp)
{
    _Exp = Exp;
}

DroidFactory            &DroidFactory::operator=(const DroidFactory &rhs)
{
    _ratio = rhs._ratio;
    _Silicon = rhs._Silicon;
    _Iron = rhs._Iron;
    _Exp = rhs._Exp;
    
    return *this;
}