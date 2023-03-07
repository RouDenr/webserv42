// copyright (c) 2023 by Dennet Cordelia

#pragma once
#ifndef __LOGGER_HPP__
#define __LOGGER_HPP__

#include <ctime>
#include <fstream>
#include <string>

#include "webserv.hpp"

class Logger {
    static Logger *logger;
    std::ofstream log_file;  // Объект для записи в файл
    std::string file_name;   // Имя файла
    // std::string class_name;

    explicit Logger(const std::string &file_name);

 public:
    class LoggerNotInitException : public std::exception {
     public:
        virtual const char *what() const throw();
    };

    static void setFile(const std::string &file_name);
    static Logger *getLogger();
    ~Logger();

    // Запись сообщения message в файл.
    void Logger::writeLog(const std::string &prefix,
                          const std::string &message);
};

Logger *Logger::logger = 0;

#endif  // __LOGGER_HPP__
