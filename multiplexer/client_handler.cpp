#include "../webserv.hpp"

void read_from_clt(int socket, multiplexer &m)
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
    std::cout << clt_socket << std::endl;
    if(clt_socket > m.max_socket)
        m.max_socket = clt_socket;
    FD_SET(clt_socket, &m.read_set);
    if(FD_ISSET(3,&m.read_set))
        std::cout << "yes" << std::endl;
    // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    m.bytes_read_from_client = read(clt_socket, buff, 1024);
    std::cout << m.bytes_read_from_client << std::endl;

    if ( m.bytes_read_from_client < 0)
    {
        perror("recv");
        close(clt_socket);
        exit(EXIT_FAILURE);
    }
    if ( m.bytes_read_from_client == 0)
        std::cout << "end of connexion \n";

    close(clt_socket);
    std::cout << "socket closed successfuly\n";
}
void send_to_clt(int socket, multiplexer &m)
{
    struct sockaddr_storage clt_addr;
    socklen_t size = sizeof(clt_addr);
    clt_addr.ss_family = AF_INET;
    char buff[1024] = "message -_-";
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
    std::cout << "here\n";
    exit(0);
    m.bytes_send_to_client = send(clt_socket, buff, 1024, 0);
    if (m.bytes_send_to_client < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }
    else if (m.bytes_send_to_client == 0)
        std::cout << "end of connexion\n";
    close(clt_socket);
    if (close(clt_socket) == -1) 
        perror("close");
    std::cout << "socket closed successfuly\n";
}