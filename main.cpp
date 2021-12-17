#include <string>
#include "network_watch.h"
#include "wake_on_lan.h"
#include "network_watch.h"
#include "configure_util.h"
#include <fstream>
int main() {
    ConfigureUtil::ConfigureMap conf = ConfigureUtil::ReadConfig("conf.txt");
    WakeOnLan wol(ConfigureUtil::MacStringToNumber(conf.at("mac")), ConfigureUtil::SplitStringAsIntList(conf.at("port"))[0]);
    NetworkWatch::AsyncWatchPort(ConfigureUtil::SplitStringAsIntList(conf.at("port"))[0]);
    wol.Wake();
    NetworkWatch::Wait();
}