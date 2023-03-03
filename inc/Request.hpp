// copyright by decordel 2023

#pragma once
#ifndef __REQUEST_HPP__
#define __REQUEST_HPP__

#include "webserv.hpp"


class Request {
 public:
    Request();
    Request(const char *c_str, size_t size);

    virtual const char *getBody() = 0;
    virtual const char *getHead() = 0;

    virtual ~Request() = 0;
};

#endif  // __REQUEST_HPP__
