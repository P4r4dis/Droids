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

        size_t          getAmount(void);
        void            setAmount(size_t Amount);

        Droid           **getWrecks() const;
        Droid           *getWrecks(size_t index) const;
    size_t              getWrecksIndex(void) const;
        void            setWrecks(Droid  **Wrecks);

                        operator size_t() const;
        Droid           *&operator*();
        // Droid           &operator*();

        Droid           *operator->() const;
        Supply          &operator--();
        Supply          &operator++();
        Supply          &operator=(const size_t rhs);
        Supply     &operator=(const Supply &rhs);
    private:
        Types           _Types;
        size_t          _Amount;
        Droid           **_Wrecks;
        size_t          _Index;
};
        std::ostream    &operator<<(std::ostream &os, Supply &supply);

#endif //   !__TEST_SUPPLY__