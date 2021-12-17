#include "configure_util.h"
#include "network_watch.h"
int main() {
    ConfigureUtil::ConfigureMap conf = ConfigureUtil::ReadConfig("conf.txt");
    NetworkWatch::AsyncWatchPort(ConfigureUtil::SplitStringAsIntList(conf.at("port")));
    NetworkWatch::Wait();
    return 0;
}