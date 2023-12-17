#include "../webserv.hpp"

void read_from_clt(int socket, clt_info &clt)
{
    struct sockaddr_storage clt_addr;
    socklen_t size = sizeof(clt_addr);
    clt_addr.ss_family = AF_INET;
    clt.socket = accept(socket, reinterpret_cast<struct sockaddr *>(&clt_addr), &size);
    if (clt.socket < 0)
    {
        perror("accept");
        exit(0);
    }
    std::cout << "connexion accepted successfuly" << std::endl;
    clt.bytes_recved = read(clt.socket, clt.recv, 1024);
    if ( clt.bytes_recved < 0)
    {
        perror("read");
        close(clt.socket);
        exit(EXIT_FAILURE);
    }
    if ( clt.bytes_recved == 0)
        std::cout << "end of connexion \n";
}
void send_to_clt(multiplexer &m, clt_info &clt)
{
    char buffer[1024] = "message._.\n";
    FD_SET(clt.socket, &m.write_set);
    m.bytes_send_to_client = send(clt.socket, buffer, 1024, 0);
    while (m.bytes_send_to_client < 0)
    {
        std::cout << "trying to send\n";
        m.bytes_send_to_client = send(clt.socket, buffer, 1024, 0);
    }
    if (m.bytes_send_to_client == 0)
        std::cout << "end of connexion\n";
}