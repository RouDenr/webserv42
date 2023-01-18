// copyright by decordel 2023

#pragma once
#ifndef __SERVER_HPP__
#define __SERVER_HPP__
// # define __COUNT_FDS__ 200
#define __SERV_TIMEOUT__ 3 * 60 * 1000
#include "webserv.hpp"

class Socket;

class Server {
    const Socket &_socket;

    pollfd fds[200];
    int nfds;
    int timeout;

    bool _end;

 public:
    explicit Server(const Socket &new_socket);
    Server(const Server &) = default;

    bool end() const { return _end; }

    ~Server();
};

#endif  // __SERVER_HPP__
