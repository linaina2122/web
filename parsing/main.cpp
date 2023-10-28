#include "webserv.hpp"

int main(int argc, char **argv)
{
    // int index = 0;
    (void)argc;
    std::vector<std::string> str;
    server *s;
    str = read_from_file(argv[1]);
   int count = num_of_server(str);
    s = fill_vect(str);
    s = parsing_functions(s, count);
    // while(index < count)
    // {
    //   // s[index].s_content = s[index].get_directives(s[index].setvec);
    //     std::multimap<std::string, std::string>::iterator it =  s[index].s_content.begin();
    //     while(it !=  s[index].s_content.end())
    //     {
    //         std::cout << it->first << std::endl;
    //         std::cout << it->second << std::endl; 
    //         it++;

    //     }
    //     index++;
    // }
    check_directives(s, count);
    delete[]s;   
}