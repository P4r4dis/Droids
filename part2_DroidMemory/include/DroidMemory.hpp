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

        DroidMemory     &operator<<(const DroidMemory &rhs);
        DroidMemory     &operator>>(DroidMemory &lhs) const;
        DroidMemory     &operator+=(const DroidMemory &droidMemory);
        DroidMemory     &operator+=(const size_t rhs);
        DroidMemory     &operator+(const DroidMemory &rhs) const;
        DroidMemory     &operator+(const size_t &rhs) const;
        bool            operator==(const DroidMemory &rhs) const;
        bool            operator!=(const DroidMemory &rhs);
        bool            operator<(const DroidMemory &rhs);


};


        std::ostream    &operator<<(std::ostream& os, const DroidMemory& rhs);


#endif //   !__DROIDMEMORY__