//
// Created by Dennet Cordelia on 15.01.2023.
//

#include "../inc/Socket.hpp"


void Socket::bind(addrinfo *ai) {
    int yes;

    for (addrinfo *i = ai; i != nullptr; i = i->ai_next) {
        this->fd = ::socket(i->ai_family, i->ai_socktype, i->ai_protocol);

        if (this->fd == -1) {
            continue;
        }

        ::setsockopt(this->fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(int));
        if (::bind(this->fd, i->ai_addr, i->ai_addrlen) == -1) {
            close(this->fd);
        } else {
            return;
        }
    }
    throw std::system_error(EFAULT, std::generic_category());
}

void Socket::listen(int backlog) {
    if (::listen(this->fd, backlog) == -1) {
        throw std::system_error(EFAULT, std::generic_category());
    }
}