#ifndef     __CARRIER__
#   define  __CARRIER__
#include <string>
#include <memory>
#include "Droid.hpp"
class   Carrier
{
    private:
        std::string             _Id;
        size_t                  _Energy;
        const size_t            _Attack;
        const size_t            _Toughness;
        size_t                  _Speed;
        std::shared_ptr<Droid>  _Droids[5];
    public:
        // Carrier();
        Carrier(std::string Id = "");
        ~Carrier(void);

        std::string             getId(void) const;
        size_t                  getEnergy(void) const;
        size_t                  getAttack(void) const;
        size_t                  getToughness(void) const;
        size_t                  getSpeed(void) const;
        std::shared_ptr<Droid>  getDroids(int i) const;

        void                    setId(std::string Id);
        void                    setEnergy(size_t Energy);
        void                    setSpeed(size_t Speed);
        void                    setDroids(int i, Droid *droid);

        Carrier                 &operator<<(Droid *&rhs);
        Carrier                 &operator>>(Droid  *&lhs);
};

        std::ostream            &operator<<(std::ostream &os, const Carrier &rhs);
#endif //   !__CARRIER__