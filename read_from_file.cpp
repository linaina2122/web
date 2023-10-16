#include "webserv.hpp"

std::vector<std::string> read_from_file(const char *argv)
{
    std::vector<std::string> str;
    std::string tmp;
    std::ifstream file(argv);
    while (getline(file, tmp))
        str.push_back(tmp);
    return (str);
}

int num_of_server(std::vector<std::string> str)
{
    int index = 0;
    std::string find = "server {";
    std::vector<std::string>::iterator it = str.begin();
    while(it != str.end())
    {
        if(*it == find)
            index++;
        it++;
    }
    return (index);
}

server *fill_vect(std::vector<std::string>str)
{
    int index = 0;
    int count = num_of_server(str);
    server *v = new server[count];
    std::string s = "server {";
    std::vector<std::string>::iterator it = str.begin();
    while(index < count)
    {
        if(it != str.end() && *it == s)
        {
            v[index].vec.push_back(*it);
            it++;
        }
        while(it != str.end() && *it != s)
        {
            v[index].vec.push_back(*it);
            it++;
        }
        index++;
    }
    return(v);
}

int count_location(server v)
{
    int count = 0;
    std::vector<std::string>::iterator it;
    it = v.vec.begin();
    while(it != v.vec.end())
    {
        if(it->find("location") != std::string::npos)
		    count++;
		it++;
    }
	return(count);
}

server *location_bloc(server *v, int count)
{
    int index = 0;
    std::vector<std::string>::iterator it;
    while(index < count)
    {
        int i = count_location(v[index]);
        it = v[index].vec.begin();
        v[index].loc = new std::vector<std::string>[i];
        std::cout << "HERE\n";
        while(it != v[index].vec.end())
        {
            if(it->find("location") !=std::string::npos)
            {
                int j = 0;
                while(j < i)
                {
                    while(it->find("}") ==std::string::npos)
                    {
                        v[index].loc[j].push_back(*it);
                        it++;
                    }
                    v[index].loc[j].push_back(*it);
                    it++;
                    j++;
                }
            }
            it++;
        }
        index++;
    }
    return(v);
}

