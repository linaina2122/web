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
    std::vector<std::string>setvec;
    std::vector<std::vector<std::string> > vectorOfloc;

    
    std::multimap<std::string, std::string> get_directives(std::vector<std::string>setvec);

};


std::vector<std::string> read_from_file(const char *argv);
int num_of_server(std::vector<std::string> str);
server *pars_config(server *s, int count);
server *fill_vect(std::vector<std::string>str);
int check_brackets(server v);
server *set_bloc(server *v, int count);
int count_location(server v);
server *location_bloc(server *v, int count);
int check_new_line(server v);
#endif
