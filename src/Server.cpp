// copyright (c) 2023 by Dennet Cordelia

#include "../inc/Server.hpp"
#include "Server.hpp"

Server::Server(const Socket &new_socket) : _socket(new_socket), _end(false) {
    ::memset(this->fds, 0, sizeof this->fds);

    this->fds[0].fd = this->_socket.getFd();
    this->fds[0].events = POLLIN;

    this->timeout = __SERV_TIMEOUT__;

}

void Server::pool() {
    webserv::do_log_mess("poll waiting...");
    int rv = ::poll(this->fds, this->nfds, this->timeout);

    if (rv <= 0) {
        webserv::throw_system_err();
    }
}

Server::~Server() {
    for (int i = 0; i < this->nfds; ++i) {
        if (this->fds[i].fd >= 0) ::close(this->fds[i].fd);
    }
}
