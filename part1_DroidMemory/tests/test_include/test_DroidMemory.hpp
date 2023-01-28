#ifndef     __TEST_DROIDMEMORY__
#   define  __TEST_DROIDMEMORY__

#include <string>
class DroidMemory
{
    private:
        size_t      _FingerPrint;
        size_t      _Exp;
    public:
        DroidMemory(size_t  FingerPrint = random(), size_t Exp = 0);
        ~DroidMemory(void);

        size_t      getFingerPrint(void) const;
        void        setFingerPrint(size_t FingerPrint);

        size_t      getExp(void) const;
        void        setExp(size_t Exp);
};


#endif //   !__TEST_DROIDMEMORY__