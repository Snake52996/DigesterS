_Pragma("once");
#include<sha264_digester.hpp>
#include<cstdint>
namespace DigesterS{
    class SHA512Digester final: public SHA264Digester{
        private:
            constexpr std::uint64_t H[8] = {
                0x6a09e667f3bcc908ull, 0xbb67ae8584caa73bull, 0x3c6ef372fe94f82bull,
                0xa54ff53a5f1d36f1ull, 0x510e527fade682d1ull, 0x9b05688c2b3e6c1full,
                0x1f83d9abfb41bd6bull, 0x5be0cd19137e2179ull
            };
        protected:
            void initH(std::array<std::uint64_t, 8>&)const override;
            std::string finalize(std::array<std::uint64_t, 8>&)const override;
        public:
            explicit SHA512Digester() = default;
            ~SHA264Digester() = default;
    };
}