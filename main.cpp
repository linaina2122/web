#include "webserv.hpp"

int main(int argc, char **argv)
{
    int index = 0;
    int count;
    (void)argc;
    std::vector<std::string> str;
    server *s;
    str = read_from_file(argv[1]);
    count = num_of_server(str);
    s = fill_vect(str);
    s = pars_config(s, count);
    s = location_bloc(s, count);
    s = set_bloc(s, count);
    while(index < count)
    {
        std::vector< std::string>::iterator it = s[index].setvec.begin();
        std::vector<std::vector < std::string> >::iterator itt = s[index].vectorOfloc.begin();

        while(it != s[index].setvec.end())
        {
            std::cout << *it << std::endl;
            it++;
        }
        while(itt != s[index].vectorOfloc.end())
        {
            std::vector< std::string>::iterator it = itt->begin();
            while(it != itt->end())
            {
                std::cout << *it << std::endl;
                it++;
            }
            itt++;
        }
        std::cout << "*****************************\n";
    index++;
    }
    delete[]s;
    
}