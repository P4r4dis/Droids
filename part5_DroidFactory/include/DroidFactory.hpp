#ifndef     __DROIDFACTORY__
# define    __DROIDFACTORY__

#include <iostream>
#include "Droid.hpp"
class                   DroidFactory
{
    private:
        size_t          _ratio;
        size_t          _Silicon;
        size_t          _Iron;
        size_t          _Exp;

    public:
        explicit DroidFactory(size_t ratio = 2);
        DroidFactory(const DroidFactory &copyDroidFactory);
        ~DroidFactory(void);

        size_t          getRatio(void) const;
        size_t          getSilicon(void) const;
        size_t          getIron(void) const;
        size_t          getExp(void) const;

        void            setRatio(size_t ratio);
        void            setSilicon(size_t Silicon);
        void            setIron(size_t Iron);
        void            setExp(size_t Exp);

        DroidFactory    &operator=(const DroidFactory &rhs);
        Droid           *operator>>(Droid *&rhs);

};
#endif //   !__DROIDFACTORY__