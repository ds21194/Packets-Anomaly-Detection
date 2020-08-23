#include "../InfoRetrival.h"

int main(){
    InfoRetrival ir = InfoRetrival();
    std::string ip = "45.101.33.45";
    std::cout << "calculating geographical location of ip: " << ip << std::endl;
    std::string result = ir.getCountry(ip);
    std::cout << "In the end, got " << result;
}
