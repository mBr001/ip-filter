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
        std::vector<std::string> v = split(line, '\t'); 
        ip_pool.push_back(IPv4(v.at(0)));
    }
    return ip_pool;
}


int main() 
{
    try 
    {
        std::vector<IPv4> ip_pool = read_pool_from_stdin();
        
        // Reverse sort.
        std::sort(
            ip_pool.begin(), 
            ip_pool.end(),
            [](const IPv4& first, const IPv4& second) -> bool {
                return !(first < second);
            }
        );
        print(ip_pool);

        // Filter 1.*.*.*
        decltype(ip_pool) pool_1;
        for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            if(ip->A() == 1) 
            {
                pool_1.push_back(*ip);
            }
        }
        print(pool_1);

        // Filter 47.70.*.*
        decltype(ip_pool) pool_46_70;
        for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            if(ip->A() == 46 && ip->B() == 70) 
            {
                pool_46_70.push_back(*ip);
            }
        }
        print(pool_46_70);

        // Filter 46.
        decltype(ip_pool) pool_any;
        for(auto ip = ip_pool.cbegin(); ip != ip_pool.cend(); ++ip)
        {
            if(ip->A() == 46 || ip->B() == 46 || ip->C() == 46 || ip->D() == 46) 
            {
                pool_any.push_back(*ip);
            }
        }
        print(pool_any);
    } 
    catch(const std::exception &e) 
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
