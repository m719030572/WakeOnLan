#ifndef WAKE_ON_LAN_H
#define WAKE_ON_LAN_H
#include <string>
#include <vector>
class WakeOnLan {
public:
    WakeOnLan(const std::vector<uint8_t>& mac, int port);
    void Wake();
private:
    void Send(const std::string& data, int port,const int size);
    std::vector<uint8_t> mac_;
    int port_;
};
#endif