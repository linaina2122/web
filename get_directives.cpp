#include "webserv.hpp"

std::string skip_tab(std::string str)
{
    int i = 0;
    std::string res;
    while(str[i])
    {
        if(str[i] == '\t' || str[i] == ' ' || str[i] == ';')
        {
            i++;
            continue;
        }
        else
            res.push_back(str[i]);
        i++; 
    }
    return(res);
}
std::multimap<std::string, std::string> server::get_directives(std::vector<std::string>setvec)
{
    std::multimap<std::string, std::string> s;
    std::string tmp1;
    std::string tmp2;
    std::vector<std::string>::iterator it = setvec.begin();
    while(it != setvec.end())
    {
        int i = it->find(":");
        tmp1 = skip_tab(it->substr(0, i - 1));
        tmp2 = skip_tab(it->substr(i + 1));
        s.insert(std::pair<std::string , std::string>(tmp1, tmp2));
        it++;
    }
    return(s);
}

