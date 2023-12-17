#include "../webserv.hpp"
#include <fcntl.h>

std::vector<int> socket_init(server *s, int count)
{
    int i = 0;
    std::vector<int> sock_array;
    while (i < count)
    {
        struct addrinfo hints;
        struct addrinfo *results;
        struct sockaddr_in addr;
        std::string str = s[i].ft_get(s[i].s_content, "host");
        const char *ip = str.c_str();
        std::string p = s[i].ft_get(s[i].s_content, "listen");
        int lis = s[i].get(s[i].s_content, "listen");
        const char *port = p.c_str();
        memset(&hints, 0, sizeof(hints));
        hints.ai_family = AF_INET;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_protocol = 0;

        if (getaddrinfo(ip, port, &hints, &results) != 0)
        {
            std::perror("getaddrinfo");
            exit(EXIT_FAILURE);
        }
        int s_fd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
        if (s_fd < 0)
        {
            std::perror("socket");
            freeaddrinfo(results);
            exit(EXIT_FAILURE);
        }
        std::cout << "socket created successfuly " << std::endl;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(lis); //'host'to'network'short/long
        if (!inet_pton(PF_INET, ip, &addr.sin_addr))
        {
            std::perror("inet_pton");
            exit(EXIT_FAILURE);
        }
        int binding = bind(s_fd, results->ai_addr, results->ai_addrlen);
        if (binding < 0)
        {
            perror("bind");
            freeaddrinfo(results);
            close(s_fd);
            exit(EXIT_FAILURE);
        }
        std::cout << "Binding successfuly\n";
        if (listen(s_fd, 10) < 0)
        {
            perror("listen\n");
            freeaddrinfo(results);
            close(s_fd);
            exit(EXIT_FAILURE);
        }
        std::cout << "listening\n";
        freeaddrinfo(results);
        sock_array.push_back(s_fd);
        i++;
    }
    return (sock_array);
}

void select_init(server *s, int count)
{
    std::vector<int> arr = socket_init(s, count);
    multiplexer m;
    struct clt_info clt;
    memset(&clt, 0, sizeof(clt_info));
    m.read_set = add_socket(arr, m.read_set);
    m.write_set = add_socket(arr, m.write_set);
    check_socket(arr, m);
    m.max_socket = find_max_socket(arr);
    fd_set copy_set;
    FD_ZERO(&copy_set);
    while (1)
    {
        copy_set = m.read_set;
        int result = select(m.max_socket + 1, &copy_set, NULL, NULL, NULL);
        if (result < 0)
        {
            perror("select");
            exit(EXIT_FAILURE);
        }
        int i = 0;
        while (i <= m.max_socket)
        {
            if (FD_ISSET(arr[i], &m.read_set))
            {
                read_from_clt(arr[i], clt);
            }
            else
                send_to_clt(m, clt);
            i++;
        }
    }
        ft_close(arr);
}
