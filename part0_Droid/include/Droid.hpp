#ifndef     __DROID__
#   define  __DROID__
#include <string>
#include <memory>

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
        Droid(std::string Id = ""); //CUSTOM CTOR
        Droid(const Droid &copyDroid); //COPY CTOR
        ~Droid(void);

        std::string         getId(void);
        void                setId(std::string Id);

        size_t              getEnergy(void);
        void                setEnergy(size_t Energy);

        size_t              getAttack(void) const;

        size_t              getToughness(void) const;

        std::string         *getStatus(void);
        void                setStatus(std::string *Status);

        Droid               &operator=(const Droid &rhs);


};

#endif //   !__DROID__