#include "../webserv.hpp"

int check_digit(std::string str) 
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '.')
        {
            i++;
            continue;
        }
        if (std::isdigit(str[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_digiit(std::string str) 
{
    int i = 0;
    while (str[i])
    {
        if (std::isdigit(str[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_host_directive(const std::string& str) {
    std::istringstream iss(str);
    int num;
    char delimiter;
    for (int i = 0; i < 4; ++i) {
        if (!(iss >> num) || num < 0 || num > 255) {
            return 1;
        }
        if ((i < 3 && !(iss >> delimiter) )|| delimiter != '.') {
            return 1;
        }
    }
    return 0;
}

int check_listen_directive(std::string str)
{
    if(check_digiit(str))
        return(1);
    return (0);
}

int check_server_name_directive(std::string str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] == '.' || str[i] == '*' || str[i] == '-' || str[i] == '_' )
        {
            i++;
            continue;
        }
        if (std::isalnum(str[i]) == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_root(std::string s)
{
    struct stat buf;
   const char *str = s.c_str();
    
    if(stat(str, &buf) != 0)
        return(1);
    return(0);
}

int check_dup(std::multimap<std::string , std::string>s)
{
    std::string tmp;
    std::multimap<std::string, std::string>::iterator it = s.begin();
    while(it != s.end())
    {
        std::multimap<std::string, std::string>::iterator itt = s.end();
        itt--;
        while(itt != it)
        {
            if(itt->first == it->first)
            {
                if(itt->first == "error_page")
                {
                    if(it->second == itt->second)
                        return(1);
                    else
                    {
                        itt--;
                        continue;
                    }
                }
                return(1);
            }
            itt--;
        }
        it++;
    }
    return(0);
}
void check_directives(server *s, int count)
{
    int index = 0;
    while(index < count)
    {
        std::multimap<std::string, std::string>::iterator it = s[index].s_content.begin();
        while(it != s[index].s_content.end())
        {
            if(check_dup(s[index].s_content))
            {
                std::cout << "dup in server" << index << std::endl;
                exit(EXIT_FAILURE);
            }
            if(it->first == "host")
            {
                if(check_host_directive(it->second))
                {
                    std::cout << "host of server " << index << "is not valid\n ";
                    exit(EXIT_FAILURE);
                }
            }
            if(it->first == "listen")
            {
                if(check_listen_directive(it->second))
                {
                    std::cout << "port of server " << index << " is not valid\n";
                    exit(EXIT_FAILURE);
                }
            }
            if(it->first == "server_name")
            {
                if(check_server_name_directive(it->second))
                {
                    std::cout << "server_name of server " << index << "is not valid\n";
                    exit(EXIT_FAILURE);
                }
            }
            if(it->first == "root")
            {
                if(check_root(it->second))
                {
                    std::cout << "directory of server "<< index << "is not found\n";
                    exit(EXIT_FAILURE);
                }
            }
            if(it->first == "client_max_body_size")
            {
                if(check_digiit(it->second))
                {
                    std::cout << "error body size of server " << index << std::endl;
                    exit(EXIT_FAILURE);
                }
            }
            it++;
        }
        index++;
    }
}

void check_dup(server *s, int count)
{
    int i = 0;
    std::string str;
    int port;
    while(count > i)
    {
        int index = count - 1;
        str = s[index].ft_get(s[index].s_content, "host");
        port = s[index].get(s[index].s_content, "listen");
        while(index > i)
        {
            index--;
            if(str == s[index].ft_get(s[index].s_content, "host"))
            {
                std::cout << "duplication in host directive server :" << count << std::endl;
                exit(EXIT_FAILURE);
            }
            if(port == s[index].get(s[index].s_content, "listen"))
            {
                {
                std::cout << "duplication in listen directive : "<< count << std::endl;
                exit(EXIT_FAILURE);
                }
            }
        }
        count--;
    }
}

