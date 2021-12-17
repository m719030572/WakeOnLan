#include "configure_util.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
ConfigureUtil::ConfigureMap ConfigureUtil::ReadConfig(const std::string& file) {
    std::ifstream ifs(file, std::ios::in);
    if (!ifs.is_open()) {
        throw (file + " open failed ");
    }
    std::string data;
    ConfigureMap ret;
    while (std::getline(ifs, data)) {
        int loc = data.find_first_of('=');
        if (data.back() == '\r' || data.back() == '\n') {
            data.pop_back();
        }
        ret.insert(std::make_pair(data.substr(0, loc), data.substr(loc+1, data.size() - loc)));
    }
    data = "Read configure: ";
    for (auto& it : ret) {
        data = data + it.first + "=" + it.second + " ";
    }
    data += "\n";
    std::cout << data;
    return ret;
}
std::vector<int> ConfigureUtil::SplitStringAsIntList(const std::string& str) {
    int start = 0;
    bool flag = false;
    std::vector<int> ret;
    for (int i = 0; i < str.size(); ++i) {
        if (flag && !CharIsNumber(str[i])) {
            ret.push_back(std::atoi(str.substr(start, i-start).data()));
            start = -1;
            flag = false;
        }
        if (!flag && CharIsNumber(str[i])) {
            start = i;
            flag = true;
        }
    }
    if (start != -1) {
        ret.push_back(std::atoi(str.substr(start, str.size() + 1 - start).data()));
    }
    return ret;
}
bool ConfigureUtil::CharIsNumber(const char ch) {
    return (ch - '0') >= 0 && (ch - '0') <= 9;
}
std::vector<uint8_t> ConfigureUtil::MacStringToNumber(const std::string& str) {
    std::vector<uint8_t> ret;
    if (str.size() % 2 != 0) {
        return ret;
    }
    for (int i = 0; i < str.size(); i = i + 2) {
        std::string tmp = str.substr(i, 2);
        ret.push_back(std::stoi(tmp, nullptr, 16));
    }
    return ret;
}
std::string ConfigureUtil::CharToSixteenString(const unsigned char ch) {
    int h = ch/16;
    int l = ch%16;
    std::string ret;
    switch (h) {
    case 10:
        ret.push_back('a');
        break;
    case 11:
        ret.push_back('b');
        break;
    case 12:
        ret.push_back('c');
        break;
    case 13:
        ret.push_back('d');
        break;
    case 14:
        ret.push_back('e');
        break;
    case 15:
        ret.push_back('f');
        break;
    default:
        ret += std::to_string(static_cast<unsigned int>(h));
        break;
    }
    switch (l) {
    case 10:
        ret.push_back('a');
        break;
    case 11:
        ret.push_back('b');
        break;
    case 12:
        ret.push_back('c');
        break;
    case 13:
        ret.push_back('d');
        break;
    case 14:
        ret.push_back('e');
        break;
    case 15:
        ret.push_back('f');
        break;
    default:
        ret += std::to_string(static_cast<unsigned int>(l));
        break;
    }
    return ret;
}
unsigned char ConfigureUtil::SixteenStringToChar(const std::string& str) {
    char h = 0;
    char l = 0;
    int ih = 0;
    int il = 0;
    l = str[0];
    if (str.size() == 2) {
        h = str[0];
        l = str[1];
    }
    switch (h) {
    case 'a':
    case 'A':
        ih = 10;
        break;
    case 'b':
    case 'B':
        ih = 10;
        break;
    case 'c':
    case 'C':
        ih = 10;
        break;
    case 'd':
    case 'D':
        ih = 10;
        break;
    case 'e':
    case 'E':
        ih = 10;
        break;
    case 'f':
    case 'F':
        ih = 10;
        break;
    default:
        ih = h - '0';
        break;
    }
    switch (l) {
    case 'a':
    case 'A':
        il = 10;
        break;
    case 'b':
    case 'B':
        il = 10;
        break;
    case 'c':
    case 'C':
        il = 10;
        break;
    case 'd':
    case 'D':
        il = 10;
        break;
    case 'e':
    case 'E':
        il = 10;
        break;
    case 'f':
    case 'F':
        il = 10;
        break;
    default:
        il = l - '0';
        break;
    }
    return ih*16 + il;
}