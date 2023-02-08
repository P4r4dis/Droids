#ifndef     __SUPPLY__
# define    __SUPPLY__

#include "Droid.hpp"
class                   Supply
{
    public:
        enum            Types{Iron = 1, Silicon = 2, Wreck = 3};

        Supply(Types Types, size_t Amount);
        Supply(Types Types, size_t Amount, Droid **Wrecks);

        Types           getTypes(void) const;
        void            setTypes(Types Types);

        size_t          getAmount(void);
        void            setAmount(size_t Amount);

        Droid           **getWrecks() const;
        Droid           *getWrecks(int index) const;
        void            setWrecks(Droid  **Wrecks);

                        operator size_t() const;
    private:
        Types           _Types;
        size_t          _Amount;
        Droid           **_Wrecks;
};
        std::ostream    &operator<<(std::ostream &os, Supply &supply);

#endif //   !__SUPPLY__