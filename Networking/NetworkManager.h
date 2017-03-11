#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "Server.h"
#include "Client.h"
#include "LogBase.h"
#include "Network_def.h"

#include <string>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace util;

class NetworkManager {

    typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

public:
    NetworkManager();
    virtual ~NetworkManager();
    void sendMsg();
    void Init();
    void setPort(int port);
    void printMsg(bool send, const char* msg);

    template <typename T>
    string serialize(T msg) {
        string s;
        if (msg.SerializeToString(&s)) {
            Log("Serialization successful");
            return s;
        } else {
            Log("Serialization failed", log::error);
            return "";
        }
    }

public:
    boost::asio::io_service io_service;
    int port;
};


#endif











