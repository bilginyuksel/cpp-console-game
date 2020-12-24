//
// Created by bilgi on 12/24/2020.
//

#include "logger.h"

bool Log::enabled_ = false;

void Log::SetEnabled(bool enabled) {
    enabled_ = enabled;
}

bool Log::IsEnabled() {
    return enabled_;
}

void Log::i(const std::string &tag, const std::string &message) {
    printLogMessage(info, tag, message);
}

void Log::w(const std::string &tag, const std::string &message) {
    printLogMessage(warn, tag, message);
}

void Log::e(const std::string &tag, const std::string &message) {
    printLogMessage(err, tag, message);
}

void Log::d(const std::string &tag, const std::string &message) {
    printLogMessage(debug, tag, message);
}

void Log::printLogMessage(const std::string level, const std::string &tag, const std::string &message) {
    if (IsEnabled()) {
        std::time_t current_time = std::time(nullptr);
        std::string time_result = std::ctime(&current_time);
        if(time_result.length() > 0)
            time_result.pop_back(); // ctime automatically adds \n so remove it.
        std::cout << time_result << " [" << level << tag << "] " <<  message << "\n";
    }
}
