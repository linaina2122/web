#ifndef WEBSERV_HPP
    #define WEBSERV_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <sys/stat.h>

class server{
    public:
    std::vector<std::string>vec; //all config file
    std::vector<std::string>setvec;
    std::vector<std::multimap<std::string, std::string> > vectorOfloc; // location
    std::multimap<std::string, std::string>s_content; // stactic content
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
void check_directives(server *s, int count);
server* fill_default(server *s, int count);
server* parsing_functions(server *s, int count);
std::string skip_tab(std::string str);
#endif
