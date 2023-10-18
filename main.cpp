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
    // std::cout << "here\n";

    // std::vector<std::vector< std::string> >::iterator it;
    // s = location_bloc(s, count);
    std::cout << count << std::endl;
    while(index < count)
    {
        std::vector< std::string>::iterator it = s[index].vec.begin();
        while(it != s[index].vec.end())
        {
            // std::cout << *it << std::endl;
            it++;
        }
    index++;
    }
    delete[]s;
    // s =  split(fill_vect(str), count);
    // count_location(s, count);
    // location(s, count);
    
}