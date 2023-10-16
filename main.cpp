#include "webserv.hpp"

int main(int argc, char **argv)
{
    // int index = 0;
    int count;
    (void)argc;
    std::vector<std::string> str;
    server *s;
    str = read_from_file(argv[1]);
    count = num_of_server(str);
    s = fill_vect(str);
    std::vector<std::string>::iterator it;
    s = location_bloc(s, count);

    // while(index < count)
    // {
    //     // int i = 0;
    //     it = s[index].loc->begin();
    //     while(it != s[index].loc->end())
    // {
    //     std::cout << *it << std::endl;
    //     it++;
    // }
    // index++;
    // }
    // location_bloc(s, count);
    delete[]s;
    // s = pars_config(s, count);
    // s =  split(fill_vect(str), count);
    // count_location(s, count);
    // location(s, count);
    
}