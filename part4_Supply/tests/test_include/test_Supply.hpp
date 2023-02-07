#ifndef     __TEST_SUPPLY__
#   define  __TEST_SUPPLY__

#include "test_Droid.hpp"
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

        Droid           **getWrecks(void);
        void            setWrecks(Droid  **Wrecks);
    private:
        Types           _Types;
        size_t          _Amount;
        Droid           **_Wrecks;
};
#endif //   !__TEST_SUPPLY__