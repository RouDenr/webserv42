//
// Created by Dennet Cordelia on 15.01.2023.
//

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
};


#endif //__SOCKET_HPP__
