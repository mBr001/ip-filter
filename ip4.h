#ifndef _IP4_H_
#define _IP4_H_

#include <vector>
#include <string>

class IPv4 
{
    long ip;

public:
    IPv4(const std::string& s);

    inline int A() const { return (ip & 0xFF000000) >> 24; }
    inline int B() const { return (ip & 0x00FF0000) >> 16; }
    inline int C() const { return (ip & 0x0000FF00) >> 8;  }
    inline int D() const { return  ip & 0x000000FF; }

    std::string to_string() const;
    bool operator<(const IPv4& another) const;

    class BadAddrException : public std::exception {};
};

#endif