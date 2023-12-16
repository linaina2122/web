#include "webserv.hpp"

int main(int argc, char **argv)
{
    (void)argc;
    std::vector<std::string> str;
    server *s;
    str = read_from_file(argv[1]);
   int count = num_of_server(str);
    s = fill_vect(str);
    s = parsing_functions(s, count);
//    select_init(s, count);
    delete[]s;
}