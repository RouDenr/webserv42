// copyright (c) 2023 by Dennet Cordelia

#pragma once
#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__

#include "webserv.hpp"


class Request {
 public:
    Request();

    virtual void parse(const char *request) = 0;

    virtual ~Request() = 0;
};

#endif  // __REQUEST_HPP__
