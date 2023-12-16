#ifndef WEBSERV_HPP
    #define WEBSERV_HPP

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <arpa/inet.h>
#include <sys/select.h>

class server{
    public:
    std::vector<std::string>vec; //all config file
    std::vector<std::string>setvec;
    std::vector<std::multimap<std::string, std::string> > vectorOfloc; // location
    std::multimap<std::string, std::string>s_content; // stactic content
    std::multimap<std::string, std::string> get_directives(std::vector<std::string>setvec);

    int get(std::multimap<std::string, std::string>s_content , std::string s); 
    std::string ft_get(std::multimap<std::string, std::string>s_content, std::string s);
    std::string get_loc_dir(std::vector<std::multimap<std::string, std::string> > vectorOfloc, std::string pattern, std::string s);
};
struct multiplexer{
    fd_set read_set;
    int max_socket;
    ssize_t bytes_send_to_client;
    ssize_t bytes_read_from_client;
    int i;
};

struct clt_info{
    int socket;
    char recv[1024];
    int bytes_recved;
    socklen_t address_length;
    struct sockaddr_storage address;
};

//parsing
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
void check_dup(server *s, int count);
void check_root(server *s, int count);
void check_methode(server *s, int count);
//multiplexer
std::vector<int> socket_init(server *s, int count);
void send_to_clt(int socket, multiplexer &m);
void read_from_clt(int socket, multiplexer &m);
fd_set add_socket(std::vector<int> arr, fd_set set);
int find_max_socket(std::vector<int> arr);
void select_init(server *s, int count);
void check_socket(std::vector<int> arr, multiplexer &m);
void ft_close(std::vector<int>arr);









#endif
