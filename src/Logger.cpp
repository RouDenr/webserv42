// copyright by decordel 2023

#include "../inc/Logger.hpp"

const char *Logger::LoggerNotInitException::what() const throw() {
    return "logger not init";
}

Logger::Logger(const std::string& file_name) {
    this->file_name = file_name;
    this->log_file.open(file_name, std::ios::app);
}

Logger::~Logger() {
    log_file.close();
}

void Logger::setFile(const std::string &file_name) {
    if (!logger) {
        logger = new Logger(file_name);
    } else {
        Logger *tmp = logger;
        logger = new Logger(file_name);
        delete tmp;
    }
}

Logger *Logger::getLogger() {
    if (!logger) {
        throw Logger::LoggerNotInitException();
    }
    return logger;
}

void Logger::writeLog(std::string message) {
    time_t rawtime;
    tm* timeinfo;
    time(&rawtime);
    timeinfo = ::localtime_r(&rawtime, timeinfo);
    char buffer[80];
    ::strftime(buffer, 80, "%d-%m-%Y %I:%M:%S", timeinfo);
    std::string str(buffer);
    this->log_file << ": " << str << " : " << message << std::endl;
}
