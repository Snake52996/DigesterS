_Pragma("once");
namespace DigesterS{
    class Utilities final{
        public:
            Utilities() = delete;
            template<typename T>
            static inline T circularLeftShift(const T& val, const unsigned int& n){
                return (val << n) | (val >> ((sizeof(T) << 3) - n));
            }
            template<typename T>
            static inline T circularRightShift(const T& val, const unsigned int& n){
                return (val >> n) | (val << ((sizeof(T) << 3) - n));
            }
    };
}