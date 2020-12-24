//
// Created by bilgi on 12/24/2020.
//

#ifndef CLIENGINEDEMO_LOGGER_H
#define CLIENGINEDEMO_LOGGER_H

#include <iostream>
#include <ctime>

const std::string info = "INFO:";
const std::string err = "ERROR:";
const std::string debug = "DEBUG:";
const std::string warn = "WARNING:";

class Log {
private:
    static bool enabled_;
    static void printLogMessage(std::string level, const std::string &tag, const std::string &message);

public:
    static void SetEnabled(bool enabled);
    static bool IsEnabled();
    static void i(const std::string &tag, const std::string &message);
    static void d(const std::string &tag, const std::string &message);
    static void e(const std::string &tag, const std::string &message);
    static void w(const std::string &tag, const std::string &message);

};

#endif //CLIENGINEDEMO_LOGGER_H
