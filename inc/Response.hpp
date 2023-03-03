// copyright by decordel 2023

#pragma once
#ifndef __RESPONSE_HPP__
#define __RESPONSE_HPP__

#include "webserv.hpp"



class Response {
 public:
    Response();
    //explicit Response(Request *request);

    virtual const char *getBody() = 0;
    virtual const char *getHead() = 0;

    ~Response();
};

#endif  // __RESPONSE_HPP__
