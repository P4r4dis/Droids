#ifndef     __TEST_CARRIER__
#   define  __TEST_CARRIER__

#include <string>
#include <memory>
#include <ostream>

#include "test_Droid.hpp"
class   Carrier
{
    public:
        Carrier(std::string Id = "");
        ~Carrier(void);

        std::string             getId(void) const;
        size_t                  getEnergy(void) const;
        size_t                  getAttack(void) const;
        size_t                  getToughness(void) const;
        size_t                  getSpeed(void) const;
        Droid                   *getDroids(int i) const;

        void                    setId(std::string Id);
        void                    setEnergy(size_t Energy);
        void                    setSpeed(size_t Speed);
        void                    setDroids(int i, Droid *droid);

        Carrier                 &operator<<(Droid *&rhs);
        Carrier                 &operator>>(Droid *&rhs);
        Droid                   *&operator[](const size_t index);
    private:
        std::string             _Id;
        size_t                  _Energy;
        const size_t            _Attack;
        const size_t            _Toughness;
        size_t                  _Speed;
        Droid                   *_Droids[5];
};
        std::ostream            &operator<<(std::ostream &os, const Carrier &rhs);
#endif //   !__TEST_CARRIER__