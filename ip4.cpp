#include "ip4.h"
#include "util.h"


IPv4::IPv4(const std::string& s) 
{
    auto strvec = split(s, '.');
    if(strvec.size() != 4) 
    {
        throw BadAddrException();
    }

    auto to_byte = [](const std::string& s) -> decltype(this->ip) {
        int b = std::stoi(s);
        if(b < 0 || b > 255) 
        {
            throw BadAddrException();
        }
        return b;
    };

    try 
    {
        this->ip  = to_byte(strvec[0]) << 24;
        this->ip += to_byte(strvec[1]) << 16;
        this->ip += to_byte(strvec[2]) << 8;
        this->ip += to_byte(strvec[3]);
    }
    catch(const std::exception& e) 
    {
        throw BadAddrException();
    }
}


std::string IPv4::to_string() const 
{
    return std::to_string(this->A()) + "." + std::to_string(this->B()) + "." + 
           std::to_string(this->C()) + "." + std::to_string(this->D());
}


bool IPv4::operator<(const IPv4& another) const 
{
    return this->ip < another.ip;
}