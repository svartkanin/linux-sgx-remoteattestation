#include "NetworkManager.h"

NetworkManager::NetworkManager() {}

NetworkManager::~NetworkManager() {}


void NetworkManager::setPort(int port) {
    this->port = port;
}


void NetworkManager::printMsg(bool send, const char* msg) {
    string s(msg);
    replace(s.begin(), s.end(), '\n', '-');
    if (send)
        Log("Send msg: '%s'", s);
    else
        Log("Received msg: '%s'", s);
}




