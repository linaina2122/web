#include "../webserv.hpp"

void read_from_clt(clt_info &clt, int socket)
{
    std::cout << "from read\n";
    clt.bytes_recved = read(socket, clt.recv, 1024);
    if ( clt.bytes_recved <= 0)
    {
        std::cout << "end of connexion\n";
        close(clt.socket);
    }
}

void send_to_clt(multiplexer &m, int socket)
{
    std::cout << "from send\n";

    char buffer[14] = "message._.\n";
    // FD_SET(socket, &m.write_set);
    m.bytes_send_to_client = send(socket, buffer, 14, 0);
    // while (m.bytes_send_to_client < 0)
    // {
    //     std::cout << "trying to send\n";
    //     m.bytes_send_to_client = send(socket, buffer, 1024, 0);
    // }
    std::cout << "here ========" << m.bytes_send_to_client << std::endl;
    
    if (m.bytes_send_to_client == 0)
        std::cout << "end of connexion\n";
}
