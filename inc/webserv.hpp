// copyright by decordel 2023

#pragma once

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <poll.h>

//   #include <arpa/inet.h>
//   #include <netinet/in.h>

#include <cerrno>
#include <csignal>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>
#include "Socket.hpp"
#include "Server.hpp"
#include "Logger.hpp"

#define PORT "80"
#define SIZE_RECV_DATA 100
#define SIZE_SEND_DATA 100
#define BACKLOG 10

#define __LOG_FILE__ "webserv.log"

typedef struct sigaction sigaction_t;


#endif
