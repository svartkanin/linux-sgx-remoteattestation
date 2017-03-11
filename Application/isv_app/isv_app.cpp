#include <iostream>
#include <unistd.h>

#include "LogBase.h"

using namespace util;

#include "MessageHandler.h"

int Main(int argc, char* argv[]) {
    LogBase::Inst();

    int ret = 0;

    MessageHandler msg;
    msg.init();
    msg.start();

    return ret;
}


int main( int argc, char **argv ) {
    try {
        return Main(argc, argv);
    } catch (std::exception& e) {
        Log("exception: %s", e.what());
    } catch (...) {
        Log("unexpected exception") ;
    }

    return -1;
}







