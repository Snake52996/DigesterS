_Pragma("once");
#include<digester.hpp>
#include<utilities.hpp>
namespace DigesterS{
    class SHA12Digester: public Digester{
        protected:
            explicit SHA12Digester() = default;
            template<typename T>
            static inline T Ch(const T& x, const T& y, const T& z)const{
                return (x & y) ^ (~x & z);
            }
            template<typename T>
            static inline T Maj(const T& x, const T& y, const T& z)const{
                return (x & y) ^ (x & z) ^ (y & z);
            }
            template<
                typename T,
                unsigned int p1, unsigned int p2, unsigned int p3
            >
            static inline T Sigma(const T& x)const{
                return
                    Utilities::circularRightShift(x, p1) ^
                    Utilities::circularRightShift(x, p2) ^
                    Utilities::circularRightShift(x, p3);
            }
            template<
                typename T,
                unsigned int p1, unsigned int p2, unsigned int p3
            >
            static inline T sigma(const T& x)const{
                return
                    Utilities::circularRightShift(x, p1) ^
                    Utilities::circularRightShift(x, p2) ^
                    (x >> p3);
            }
        public:
            virtual ~SHA12Digester() = default;
            virtual std::string digest(const char* const, const unsigned long long&)const = 0;
            virtual std::string digest(std::istream&)const = 0;
    };
}