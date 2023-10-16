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
    std::vector<std::vector< std::string> >::iterator it;
    s = location_bloc(s, count);

    // while(index < count)
    // {
    //     it = s[index].vectorOfloc.begin();
    //     while(it != s[index].vectorOfloc.end())
    //     {
    //         std::vector< std::string>::iterator itt;
    //         itt = it->begin();
    //         while(itt != it->end())
    //         {
    //             std::cout << *itt << std::endl;
    //             itt++;
    //         }
    //         it++;
    //     }
    // index++;
    // }
    delete[]s;
    // s = pars_config(s, count);
    // s =  split(fill_vect(str), count);
    // count_location(s, count);
    // location(s, count);
    
}