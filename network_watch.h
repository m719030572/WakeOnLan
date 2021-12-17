#ifndef NETWORK_WATCH_H
#define NETWORK_WATCH_H
#include <thread>
#include <vector>
#include <mutex>
class NetworkWatch {
public:
    void Daemon();
    static void AsyncWatchPort(int port);
    static void AsyncWatchPort(std::vector<int> port_list);
    static void WatchPort(int port);
    static void Wait();
private:
    static std::vector<std::thread> thread_list_;
    static std::mutex mutex_;
};
#endif