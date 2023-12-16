#include "../webserv.hpp"

fd_set add_socket(std::vector<int> arr, fd_set set)
{
    FD_ZERO(&set); // macro permet d initialiser fd_set des le debut pour etre vide
    std::vector<int>::iterator it = arr.begin();
    while (it != arr.end())
    {
        FD_SET(*it, &set);
        it++;
    }
    return (set);
}
int find_max_socket(std::vector<int> arr)
{
    std::vector<int>::iterator it = arr.begin();
    int i;
    i = *it;
    it++;
    while (it != arr.end())
    {
        if (i < *it)
            i = *it;
        it++;
    }
    return (i);
}

void check_socket(std::vector<int> arr, multiplexer &m)
{
    std::vector<int>::iterator it = arr.begin();
    while(it != arr.end())
    {
        if(!FD_ISSET(*it, &m.read_set))
        {
            std::cout << "socket not found\n";
            exit(EXIT_FAILURE);
        }
        it++;
    }
}

void ft_close(std::vector<int>arr)
{
    std::vector<int>::iterator it = arr.begin();
    while(it != arr.end())
    {
        close(*it);
        it++;
    }
}