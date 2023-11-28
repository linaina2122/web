#include "../webserv.hpp"

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

multiplexer read_from_clt(int socket, multiplexer &m)
{
    struct sockaddr_storage clt_addr;
    socklen_t size = sizeof(clt_addr);
    clt_addr.ss_family = AF_INET;
    char buff[1024];
    int clt_socket = accept(socket, reinterpret_cast<struct sockaddr *>(&clt_addr), &size);

    if (clt_socket < 0)
    {
        perror("accept");
        exit(0);
    }
    std::cout << "connexion accepted successfuly" << std::endl;
    if(clt_socket > m.max_socket)
        m.max_socket = clt_socket;
    FD_SET(clt_socket, &m.read_set);
    // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    m.bytes_read_from_client = recv(clt_socket, buff, 1024, 0);
    if ( m.bytes_read_from_client< 0)
    {
        perror("recv");
        close(clt_socket);
        exit(EXIT_FAILURE);
    }
    if ( m.bytes_read_from_client == 0)
        std::cout << "end of connexion \n";
    return (m);
}
multiplexer send_to_clt(int socket, multiplexer &m)
{
    struct sockaddr_storage clt_addr;
    socklen_t size = sizeof(clt_addr);
    clt_addr.ss_family = AF_INET;
    char buff[1024] = "qq";
    int clt_socket = accept(socket, reinterpret_cast<struct sockaddr *>(&clt_addr), &size);
    if (clt_socket < 0)
    {
        perror("accept");
        close(clt_socket);
        exit(EXIT_FAILURE);
    }
    std::cout << "connexion accepted successfuly " << std::endl;
    // ssize_t send(int sockfd, const void *buf, size_t len, int flags);
    if (clt_socket > m.max_socket)
        m.max_socket = clt_socket;
    m.bytes_send_to_client = send(clt_socket, buff, 1024, 0);
    if (m.bytes_send_to_client < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }
    else if (m.bytes_send_to_client == 0)
        std::cout << "end of connexion\n";
    return (m);
}
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
void select_init(server *s, int count)
{
    std::vector<int> arr = socket_init(s, count);
    multiplexer m;
    m.read_set = add_socket(arr, m.read_set);
    check_socket(arr, m);
    m.max_socket = find_max_socket(arr);
    fd_set copy_set;
    FD_ZERO(&copy_set);
    while (1)
    {
        copy_set = m.read_set;

        // int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
        int result = select(m.max_socket + 1, &copy_set, NULL, NULL, NULL);
        std::cout << result << std::endl;
        if (result < 0)
        {
            perror("select");
            exit(EXIT_FAILURE);
        }
        std::cout << result << std::endl;
        int i = 0;
        while (i < m.max_socket)
        {
            if (FD_ISSET(arr[i], &m.read_set))
                read_from_clt(arr[i], m);
            else
                send_to_clt(arr[i], m);
            i++;
        }
        ft_close(arr);
    }
}
