#include "configure_util.h"
#include "wake_on_lan.h"
int main() {
    ConfigureUtil::ConfigureMap conf = ConfigureUtil::ReadConfig("conf.txt");
    WakeOnLan wol(ConfigureUtil::MacStringToNumber(conf.at("mac")), ConfigureUtil::SplitStringAsIntList(conf.at("port"))[0]);
    wol.Wake();
}
