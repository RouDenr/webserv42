// copyright by decordel 2023

#include "../inc/Server.hpp"

Server::Server(const Socket &new_socket) : _socket(new_socket), _end(false) {
    ::memset(this->fds, 0, sizeof this->fds);

    this->fds[0].fd = this->_socket.getFd();
    this->fds[0].events = POLLIN;

    this->timeout = __SERV_TIMEOUT__;

}

Server::~Server() {
    for (int i = 0; i < this->nfds; ++i) {
        if (this->fds[i].fd >= 0) ::close(this->fds[i].fd);
    }
}
