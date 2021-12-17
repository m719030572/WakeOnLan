#include "wake_on_lan.h"

#include <boost/asio.hpp>
#include <string>
#include <iostream>
#include "configure_util.h"
namespace ip = boost::asio::ip;
WakeOnLan::WakeOnLan(const std::vector<uint8_t>& mac, int port) : mac_(mac), port_(port) {}

void WakeOnLan::Wake() {
    std::string data;
    data.reserve(102);
    for (int i = 0; i < 6; ++i) {
        data += 0xff;
    }
    for (int i = 0; i < 16; ++i) {
        for (auto& i : mac_) {
            data += i;
        }
    }
    Send(data, port_, 102);
}
void WakeOnLan::Send(const std::string& data, int port,const int size) {
    boost::asio::io_service ios;
    ip::udp::socket sock(ios, ip::udp::endpoint(ip::udp::v4(), 0));
    sock.set_option(boost::asio::socket_base::broadcast(true));
    ip::udp::endpoint broadcast_ep(ip::address_v4::broadcast(), port);
    std::string logbuf = "send message : " + std::to_string(data.size())  + '\n';
    for (int i = 0; i < size; ++i) {
        logbuf = logbuf + "0x" + ConfigureUtil::CharToSixteenString(data[i]) + " ";
    }
    std::cout << logbuf << std::endl;
    sock.send_to(boost::asio::buffer(data), broadcast_ep);
}