#include <iostream>
#include <vector>
#include <algorithm>

#include "ip4.h"
#include "util.h"


void print(const std::vector<IPv4>& ip_pool) 
{
    for(auto cit = ip_pool.cbegin(); cit != ip_pool.cend(); cit++) 
    {
        std::cout << cit->to_string() << std::endl;
    }
}


std::vector<IPv4> read_pool_from_stdin()  
{
    std::vector<IPv4> ip_pool;
    for(std::string line; std::getline(std::cin, line);) 
    {
        auto v = split(line, '\t'); 
        
        // Already rvalue, but without any profit.
        //     IPv4 ip(v.at(0));
        //     ip_pool.push_back(std::move(ip));
        ip_pool.push_back(IPv4(v.at(0)));
    }
    return ip_pool;
}


template<typename... Args> 
std::vector<IPv4> filter(const std::vector<IPv4>& ip_pool, Args... args)
{
    std::vector<IPv4> ret;

    int arr[] = {args...};
    int len = sizeof...(args);

    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ip++)
    {
        for(int i = 0; i < len; i++) 
        {
            if(arr[i] != ip->get(i)) 
            {
                goto skip_push;
            }
        }
        ret.push_back(*ip);
skip_push:
        ;
    }

    return ret;
}


std::vector<IPv4> filter_any(const std::vector<IPv4>& ip_pool, int value) 
{
    std::vector<IPv4> ret;
    for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
    {
        if(ip->A() == value || ip->B() == value || 
           ip->C() == value || ip->D() == value) 
        {
            ret.push_back(*ip);
        }
    }
    return ret;
}


int main() 
{
    try 
    {
        auto ip_pool = read_pool_from_stdin();
        
        // Reverse sort.
        std::sort(
            ip_pool.begin(), 
            ip_pool.end(),
            [](const IPv4& first, const IPv4& second) -> bool {
                return !(first < second);
            }
        );
        print(ip_pool);

        print(filter(ip_pool, 1));
        print(filter(ip_pool, 46, 70));
        print(filter_any(ip_pool, 46));
    } 
    catch(const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
