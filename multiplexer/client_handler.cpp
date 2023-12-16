#include "../webserv.hpp"

void read_from_clt(int socket, multiplexer &m)
{
    struct sockaddr_storage clt_addr;
    socklen_t size = sizeof(clt_addr);
    clt_addr.ss_family = AF_INET;
    char buff[1024];
    m.i = accept(socket, reinterpret_cast<struct sockaddr *>(&clt_addr), &size);
    if (m.i < 0)
    {
        perror("accept");
        exit(0);
    }
    std::cout << "connexion accepted successfuly" << std::endl;
    std::cout << m.i << std::endl;
    if(m.i > m.max_socket)
        m.max_socket = m.i;
    FD_SET(m.i, &m.read_set);
    if(FD_ISSET(4,&m.read_set))
        std::cout << "yes" << std::endl;
    // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
    m.bytes_read_from_client = read(m.i, buff, 1024);
    std::cout << m.bytes_read_from_client << std::endl;
    if ( m.bytes_read_from_client < 0)
    {
        perror("read");
        close(m.i);
        exit(EXIT_FAILURE);
    }
    if ( m.bytes_read_from_client == 0)
        std::cout << "end of connexion \n";
    close(m.i);
    std::cout << "socket closed successfuly\n";
}
void send_to_clt(int socket, multiplexer &m)
{
    (void)socket;
    char buff[1024] = "message -_-";
    m.i = send(socket, buff, 1024, 0);
    std::cout <<"iiiiiiiii "<< m.i<< std::endl;
    if (m.i < 0)
    {
        perror("send");
        exit(EXIT_FAILURE);
    }
    else if (socket == 0)
        std::cout << "end of connexion\n";
    close(m.i);
    if (close(m.i) == -1) 
        perror("close");
    std::cout << "socket closed successfuly\n";
}