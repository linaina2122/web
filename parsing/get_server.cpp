#include "../webserv.hpp"

int server::get(std::multimap<std::string, std::string>s_content, std::string s)
{
    int res;
    std::multimap<std::string, std::string>::iterator it = s_content.begin();
    while(it !=  s_content.end())
    {
        if(it->first == s)
        {
            const char *str = it->second.c_str();
            res = std::atoi(str);
            return(res);
        }
        it++;
    }
    return(-1);
}

std::string server::ft_get(std::multimap<std::string, std::string>s_content, std::string s)
{
     std::multimap<std::string, std::string>::iterator it = s_content.begin();
    while(it !=  s_content.end())
    {
        if(it->first == s)
            return(it->second);
        it++;
    }
    return(NULL);
}
