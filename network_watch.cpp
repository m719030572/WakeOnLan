#include "network_watch.h"

#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>
#include <thread>
#include <vector>

#include "configure_util.h"
std::vector<std::thread> NetworkWatch::thread_list_;
std::mutex NetworkWatch::mutex_;
namespace ip = boost::asio::ip;
void NetworkWatch::Daemon() {
    AsyncWatchPort(7);
}

void NetworkWatch::AsyncWatchPort(int port) {
    std::unique_lock<std::mutex> lock(mutex_);
    thread_list_.emplace_back(&NetworkWatch::WatchPort, port);
}
void NetworkWatch::AsyncWatchPort(std::vector<int> port_list) {
    std::unique_lock<std::mutex> lock(mutex_);
    for (auto port : port_list) {
        thread_list_.emplace_back(&NetworkWatch::WatchPort, port);
    }

}
void NetworkWatch::WatchPort(int port) {
    boost::asio::io_service ios;
    ip::udp::socket sock(ios, ip::udp::endpoint(ip::address_v4(), port));
    boost::array<char, 1000> buffer;
    std::cout << "waiting message..." << std::endl;
    auto call_back = [&buffer](const boost::system::error_code& error, std::size_t bytes_transferred) {
            std::cout << "received message!\n" <<
                    " size : " << bytes_transferred << std::endl;
                    // " status :" << error.message() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            std::string data;
            for (int i = 0; i < bytes_transferred; ++i) {
                data += buffer[i];
            }
            std::string logbuf = "received message : ";
            for (auto& ch : data) {
                logbuf = logbuf + "0x" + ConfigureUtil::CharToSixteenString(ch) + " ";
            }
            std::cout << logbuf << std::endl;
            };
    sock.async_receive(boost::asio::buffer(buffer), call_back);
    ios.run();
}
void NetworkWatch::Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    std::vector<std::thread> list = std::move(thread_list_);
    thread_list_.clear();
    lock.unlock();
    std::cout << "wait for end." << std::endl;
    for (auto& i : list) {
        i.join();
    }
}