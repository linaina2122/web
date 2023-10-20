#include "webserv.hpp"

int check_host_directive(std::string str)
{
     int i = 0;
    while(str[i])
    {
        if(str[i] == '.')
        {
            i++;
            continue;
        }
        if(std::isdigit(str[i]) == 0)
            return(1);
        i++;
    }
    return(0);
}

int check_listen_directive(std::string str)
{
    int i = 0;
    while(str[i])
    {
        if(std::isdigit(str[i]) == 0)
            return(1);
        i++;
    }
    return(0);
}

int check_server_name_directive(std::string str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == '.')
        {
            i++;
            continue;
        }
        if(std::isalpha(str[i]) == 0)
            return(1);
        i++;
    }
    return(0);
}