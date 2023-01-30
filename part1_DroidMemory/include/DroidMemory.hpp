#ifndef     __DROIDMEMORY__
#   define  __DROIDMEMORY__


#include <string>
#include <ostream>
class DroidMemory
{
    private:
        size_t          _FingerPrint;
        size_t          _Exp;
    public:
        DroidMemory(size_t  FingerPrint = random(), size_t Exp = 0);
        ~DroidMemory(void);

        size_t          getFingerPrint(void) const;
        void            setFingerPrint(size_t FingerPrint);

        size_t          getExp(void) const;
        void            setExp(size_t Exp);

        DroidMemory     &operator<<(DroidMemory &droidMemory);
};

        std::ostream    &operator<<(std::ostream& os, const DroidMemory& rhs);


#endif //   !__DROIDMEMORY__