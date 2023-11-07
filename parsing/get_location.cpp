#include "../webserv.hpp"

std::multimap<std::string, std::string> find_right_bloc(std::vector<std::multimap<std::string, std::string> > vectorOfloc, std::string s)
{
    std::vector<std::multimap<std::string, std::string> >::iterator it = vectorOfloc.begin();
    while(it != vectorOfloc.end())
    {
        std::multimap<std::string, std::string>::iterator iit = it->begin();
        while(iit != it->end())
        {
            if(iit->first == "pattern")
            {
                if(iit->second == s)
                    return(*it);
            }
            iit++;
        }
        it++;
    }
    return(std::multimap<std::string, std::string>());
}

std::string server::get_loc_dir(std::vector<std::multimap<std::string, std::string> > vectorOfloc, std::string pattern,  std::string s)
{
    std::multimap<std::string, std::string>tmp = find_right_bloc(vectorOfloc, pattern);
    std::multimap<std::string, std::string>::iterator it = tmp.begin();
    while(it != tmp.end())
    {
        if(it->first == s)
            return(it->second);
        it++;
    }
    return(NULL);
}
