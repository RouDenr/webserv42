// copyright by decordel 2023

#include "../inc/webserv.hpp"

void do_log_mess(const std::string &mess) {
    std::cout << "server: " << mess << "\n";
    Logger::getLogger()->writeLog("server", mess);
}


void do_err_mess(const std::string &mess) {
    std::cerr << "server: " << mess << "\n";
    Logger::getLogger()->writeLog("server", mess);
}
