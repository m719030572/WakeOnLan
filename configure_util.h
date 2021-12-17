#ifndef CONFIGURE_UTIL_H
#define CONFIGURE_UTIL_H
#include <string>
#include <map>
#include <vector>
struct WolConf {
    std::string mac;
    std::vector<int> port_list;
};
class ConfigureUtil {
public:
    typedef std::map<std::string, std::string> ConfigureMap;
    static ConfigureMap ReadConfig(const std::string& file);
    static std::vector<int> SplitStringAsIntList(const std::string& str);
    static std::vector<uint8_t> MacStringToNumber(const std::string& str);
    static std::string CharToSixteenString(const unsigned char ch);
    static unsigned char SixteenStringToChar(const std::string& str);
private:
    static bool CharIsNumber(const char ch);
};
#endif