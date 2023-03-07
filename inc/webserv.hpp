// copyright (c) 2023 by Dennet Cordelia

#pragma once

#ifndef WEBSERV_HPP
#define WEBSERV_HPP

#include <netdb.h>
#include <poll.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//   #include <arpa/inet.h>
//   #include <netinet/in.h>

#include <cerrno>
#include <csignal>
#include <cstring>
#include <exception>
#include <iostream>
#include <string>

#include "Logger.hpp"
#include "Request.hpp"
#include "Response.hpp"
#include "Server.hpp"
#include "Socket.hpp"

#define PORT "80"
#define SIZE_RECV_DATA 100
#define SIZE_SEND_DATA 100
#define BACKLOG 10

#define __LOG_FILE__ "webserv.log"

typedef struct sigaction sigaction_t;

// * UTILS
namespace webserv {

void do_log_mess(const std::string &mess);
void do_err_mess(const std::string &mess);
void throw_system_err();
}  // namespace webserv

#endif
