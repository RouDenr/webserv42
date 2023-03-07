// copyright (c) 2023 by Dennet Cordelia

#ifndef __SOCKET_HPP__
# define __SOCKET_HPP__
# include "webserv.hpp"


class Socket {
    int fd;

 public:
    Socket() {}
    Socket(const Socket&) = default;

    void bind(addrinfo *server_info);
    void listen(int backlog);

    int getFd() const { return this->fd; }
};


#endif //__SOCKET_HPP__
