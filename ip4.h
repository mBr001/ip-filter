#ifndef _IP4_H_
#define _IP4_H_

#include <vector>
#include <string>

class IPv4 
{
    uint32_t ip;
    
    // The alternatives for move semantic:
    // std::string ip;
    // std::vector<std::string> ip;

public:
    IPv4(const std::string& s);

    // The alternative implementations.
    // IPv4(std::string&& s) : ip(s) {}
    // IPv4(std::vector<std::string>&& v): ip(v) {}
    
    // Meaningless for this implementation.
    // IPv4(IPv4&& ip);

    inline int A() const { return (ip & 0xFF000000) >> 24; }
    inline int B() const { return (ip & 0x00FF0000) >> 16; }
    inline int C() const { return (ip & 0x0000FF00) >> 8;  }
    inline int D() const { return  ip & 0x000000FF; }

    // It's dangerous, so dangerous. I wanna do it again.
    inline int get(int i) const 
    { 
        return (ip & 0xff << 8 * (3 - i)) >> 8 * (3 - i); 
    }

    std::string to_string() const;
    bool operator<(const IPv4& another) const;

    class BadAddrException : public std::exception {};
};

#endif