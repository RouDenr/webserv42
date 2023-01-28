// copyright by decordel 2023

#include "../inc/webserv.hpp"

void fullServInfo(addrinfo **serv_info, const char *conf_file) {
    (void)conf_file;
    addrinfo hints;

    std::memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    if (getaddrinfo(NULL, PORT, &hints, serv_info) != 0) {
        throw std::system_error(EFAULT, std::generic_category());
    }
}

int polling_server(const Socket &listen_socket) {
    Server main_server(listen_socket);

    try {
        do {
        } while (!main_server.end());

    } catch (const std::system_error &err) {
        std::cerr << "server: " << err.what();
        return err.code().value();
    }
    return 0;
}

int main(int argc, char **argv) {
    Socket socket;
    addrinfo *serv_info;
    Logger::setFile(__LOG_FILE__);

    if (argc != 2 && false) return 1;

    try {
        fullServInfo(&serv_info, argv[1]);
        socket.bind(serv_info);
        freeaddrinfo(serv_info);
        socket.listen(BACKLOG);
    } catch (const std::system_error &err) {
        std::cerr << "server: " << err.what();
        freeaddrinfo(serv_info);
        return err.code().value();
    }
    std::cout << "server: waiting for connection..." << std::endl;

    return polling_server(socket);
}
