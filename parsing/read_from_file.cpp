#include "../webserv.hpp"

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
    std::vector<std::string>::iterator it = str.begin();
    while(it != str.end())
    {
        if(it->find("Server") != std::string::npos)
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
    std::vector<std::string>::iterator it = str.begin();
    while(index < count)
    {
        if(it != str.end() && it->find("Server") != std::string::npos)
        {
            v[index].vec.push_back(*it);
            it++;
        }
        while(it != str.end() && !(it->find("Server") != std::string::npos))
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

server *set_bloc(server *v, int count)
{
    int index = 0;
    while(index < count)
    {
        std::vector<std::string>::iterator it = v[index].vec.begin();
        if(it->find("Server") != std::string::npos)
        {
            it++;
            while(it != v[index].vec.end() && (!(it->find("location") != std::string::npos)))
            {
                v[index].setvec.push_back(*it);
                it++;
            }
        }
        index++;
    }
    return(v);
}

std::multimap<std::string, std::string> get(std::vector<std::string>vec)
{
    std::multimap<std::string, std::string> s;
    std::string tmp1;
    std::string tmp2;
    std::vector<std::string>::iterator it = vec.begin();
    while(it != vec.end())
    {
        if(it->find(":") != std::string::npos)
        {
            int i = it->find(":");
            tmp1 = skip_tab(it->substr(0, i - 1));
            tmp2 = skip_tab(it->substr(i + 1));
            s.insert(std::pair<std::string , std::string>(tmp1, tmp2));
        }
        it++;
    }
    return(s);
}
server *location_bloc(server *v, int count)
{
    int index = 0;

    while(index < count)
    {
        int loc_count = count_location(v[index]);
        std::vector<std::string>loc[loc_count];
        std::multimap<std::string, std::string>l;
        std::vector<std::string>::iterator it = v[index].vec.begin();
        int i = 0;
        while(it != v[index].vec.end())
        {
            if(i == loc_count)
                break;
            if(it->find("location") != std::string::npos)
            {
                loc[i].push_back(*it);
                it++;
                while(it != v[index].vec.end() && (!(it->find("location") != std::string::npos)))
                {
                    loc[i].push_back(*it);
                    it++;
                }
                l = get(loc[i]);
                v[index].vectorOfloc.push_back(l);
                i++;
            }
            else
             it++;
        }
        index++;
    }
    return(v);
}


