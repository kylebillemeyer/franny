//
// Created by Kyle Billemeyer on 9/9/24.
//

#ifndef STRING_HPP
#define STRING_HPP
#include <sstream>
#include <vector>

namespace utility::string {
    inline std::vector<std::string> split(const std::string &s, const char delim) {
        std::vector<std::string> result;
        std::stringstream ss(s);
        std::string item;

        while (getline(ss, item, delim)) {
            result.push_back(item);
        }

        return result;
    }
}

#endif //STRING_HPP
