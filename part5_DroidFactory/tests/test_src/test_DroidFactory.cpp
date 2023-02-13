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

Droid                   *DroidFactory::operator>>(Droid *&rhs)
{
    if (_Iron >= 100 && _Silicon >= 50)
    {
        _Iron -= 100;
        _Silicon -= 50;
        rhs = new Droid("");
        rhs->getBattleData()->setExp((_Exp - _Exp) / _ratio);
    }
    else
        rhs = nullptr;

    return rhs;
}

DroidFactory                  &operator>>(const Supply &lhs, DroidFactory &rhs)
{
    Droid   *droid = nullptr;

    for (size_t i = 0; i < lhs.getAmount(); i++)
    {
        droid = lhs.getWrecks(i);
        rhs.setExp(rhs.getExp() + (droid->getBattleData()->getExp() - rhs.getExp()) / rhs.getRatio());
        rhs.setIron(rhs.getIron() + 80);
        rhs.setSilicon(rhs.getSilicon() + 30);
    }
    return rhs;
}
DroidFactory            &DroidFactory::operator<<(const Supply &rhs)
{
    if (rhs.getTypes())
    {
        if (rhs.getTypes() == Supply::Silicon)
            _Silicon += rhs.getAmount();
        else if (rhs.getTypes() == Supply::Iron)
            _Iron += rhs.getAmount();
        else
        {
            for (size_t i = 0; i < rhs.getAmount(); i++)
            {
                Droid   *droid = rhs.getWrecks(i);
                _Exp += (droid->getBattleData()->getExp() - _Exp) / _ratio;
                _Iron += 80;
                _Silicon += 30;
                droid = nullptr;

                delete droid;
            }
        }
    }

    return *this;
}

std::ostream            &operator<<(std::ostream &os, const DroidFactory &rhs)
{
    os << "DroidFactory status report :" << std::endl;
    os << "Iron : " << rhs.getIron() << std::endl;
    os << "Silicon : " << rhs.getSilicon() << std::endl;
    os << "Exp : " << rhs.getExp() << std::endl;
    os << "End of status report.";

    return os;
}