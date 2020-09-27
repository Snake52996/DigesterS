_Pragma("once");
#include<istream>
#include<string>
namespace DigesterS{
    class Digester{
        protected:
            explicit Digester() = default;
        public:
            virtual ~Digester() = default;
            virtual std::string digest(const char* const, const unsigned long long&)const = 0;
            virtual std::string digest(std::istream&) = 0;
    };
}