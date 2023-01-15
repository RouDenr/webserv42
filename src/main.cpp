// copyright by decordel 2023

#include "../inc/webserv.hpp"

void fullServInfo(addrinfo **serv_info) {
    addrinfo hints;

    std::memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, PORT, &hints, serv_info) != 0) {
        throw std::system_error(EFAULT, std::generic_category());
    }
}



int main() {
    int error = 0;
//    sigaction_t sa;

    Socket socket;
    addrinfo *serv_info;

    try {
        fullServInfo(&serv_info);
        socket.bind(serv_info);
        freeaddrinfo(serv_info);
        socket.listen(BACKLOG);
    } catch (const std::system_error &err) {
        std::cerr << "server: " << err.what();
        freeaddrinfo(serv_info);
        return err.code().value();
    }
    std::cout << "server: waiting for connection..." << std::endl;
//    do {
//
//    } while (true);

    return error;
}
