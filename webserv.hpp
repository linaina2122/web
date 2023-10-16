#ifndef WEBSERV_HPP
    #define WEBSERV_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>

class server{
    public:
    std::vector<std::string>vec;
    int loc_count;
    std::vector<std::vector<std::string> > vectorOfloc;
};

std::vector<std::string> read_from_file(const char *argv);
int num_of_server(std::vector<std::string> str);
// store *pars_config(store *s, int count);
//  store *split(store *v, int count);
server *fill_vect(std::vector<std::string>str);
// store *pars(store *s, int count);
// int check_brackets(store v);
int count_location(server v);
server *location_bloc(server *v, int count);
#endif
