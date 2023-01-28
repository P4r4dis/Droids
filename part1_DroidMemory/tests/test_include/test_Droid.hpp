#ifndef     __TEST_DROID__
#   define  __TEST_DROID__

#include <string>
#include <memory>
#include <ostream>

void    redirect_all_stdout(void);

class   Droid
{
    private:
        std::string         _Id;
        size_t              _Energy;
        const size_t        _Attack;
        const size_t        _Toughness;
        // std::string         *_Status;
        std::unique_ptr<std::string> _Status;
    public:
        Droid(std::string Id); //CUSTOM CTOR
        Droid(const Droid &copyDroid); //COPY CTOR
        ~Droid(void);

        std::string         getId(void) const;
        void                setId(std::string Id);

        size_t              getEnergy(void) const;
        void                setEnergy(size_t Energy);

        size_t              getAttack(void) const;

        size_t              getToughness(void) const;

        std::string         *getStatus(void) const;
        void                setStatus(std::string *Status);

        Droid               &operator=(const Droid &rhs);
        bool                operator==(const Droid &rhs);
        bool                operator!=(const Droid &rhs);
        Droid               &operator<<(size_t &Energy);

};

std::ostream                &operator<<(std::ostream& os, const Droid& rhs);


#endif //   !__TEST_DROID__
