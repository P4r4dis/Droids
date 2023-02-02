#ifndef     __TEST_CARRIER__
#   define  __TEST_CARRIER__

#include <string>
#include <memory>
#include "test_Droid.hpp"
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

        std::string             getId(void);
        size_t                  getEnergy(void);
        size_t                  getAttack(void) const;
        size_t                  getToughness(void) const;
        size_t                  getSpeed(void);
        std::shared_ptr<Droid>  getDroids(int i);

        void                    setId(std::string Id);
        void                    setEnergy(size_t Energy);
        void                    setSpeed(size_t Speed);
        void                    setDroids(int i, Droid *droid);
};

#endif //   !__TEST_CARRIER__