#ifndef     __TEST_DROIDFACTORY__
# define    __TEST_DROIDFACTORY__
#include <iostream>

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
};
#endif //   !__TEST_DROIDFACTORY__