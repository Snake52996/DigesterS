#include<sha264_digester.hpp>
#include<algorithm>
using DigesterS::SHA264Digester;
using std::string;
using std::uint64_t;
using std::istream;
using std::array;
using std::min;
void setW(
    std::array<std::uint64_t, 80>& W,
    const char* const data, const unsigned int& size
)const{
    
}
void setWorkingVariables(
    std::array<std::uint64_t, 8>&,
    const std::array<std::uint64_t, 8>&
)const;
void calculationIteration(
    std::array<std::uint64_t, 8>&,
    const std::array<std::uint64_t, 64>&
)const;
void calculateNextH(
    std::array<std::uint64_t, 8>&,
    const std::array<std::uint64_t, 8>&
)const;
string SHA264Digester::digest(const char* const data, const unsigned long long& size)const{
    array<uint64_t, 8> H;
    this->initH(H);
    array<uint64_t, 64> W;
    array<uint64_t, 8> working_var;
    unsigned long long current_start = 0;
    while(current_start != size){
        this->setW(W, data + current_start, min(this->BLOCK_SIZE, size - current_start));
        current_start += min(this->BLOCK_SIZE, size - current_start);
        this->setWorkingVariables(working_var, H);
        this->calculationIteration(working_var, W);
        this->calculateNextH(H, working_var);
    }
    return this->finalize(H);
}
string SHA264Digester::digest(istream& data)const{

}