// copyright (c) 2023 by Dennet Cordelia

#pragma once
#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__

#include "webserv.hpp"



class Response {
 public:
    Response();

    virtual const char *to_string() = 0;

    virtual ~Response() = 0;
};

#endif  // __RESPONSE_HPP__
