#ifndef     __TEST_SUPPLY__
#   define  __TEST_SUPPLY__

#include "test_Droid.hpp"
#include <ostream>
class                   Supply
{
    public:
        enum            Types{Iron = 1, Silicon = 2, Wreck = 3};

        Supply(Types Types, size_t Amount);
        Supply(Types Types, size_t Amount, Droid **Wrecks);

        Types           getTypes(void) const;
        void            setTypes(Types Types);

        size_t          getAmount(void) const;
        void            setAmount(size_t Amount);

        Droid           **getWrecks(void) const;
        Droid           *getWrecks(size_t index) const;
        size_t          getWrecksIndex(void) const;
        void            setWrecks(Droid  **Wrecks);

                        operator size_t(void) const;
        Droid           *&operator*(void) const;
        Droid           *operator->(void) const;
        Supply          &operator--(void);
        Supply          &operator++(void);
        Supply          &operator=(const size_t rhs);
        bool            operator==(const Types Types);
        bool            operator!=(const Types Types);
        Supply          &operator!(void);

    private:
        Types           _Types;
        size_t          _Amount;
        Droid           **_Wrecks;
        size_t          _Index;
};
        std::ostream    &operator<<(std::ostream &os, const Supply &supply);

#endif //   !__TEST_SUPPLY__