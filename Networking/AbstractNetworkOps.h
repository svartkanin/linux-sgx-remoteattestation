#ifndef ABSTRACTNETWORKOPS_H
#define ABSTRACTNETWORKOPS_H

#include "LogBase.h"

#include <vector>
#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <functional>
#include <boost/asio/buffer.hpp>
#include <boost/asio.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;

typedef function<vector<string>(string, int)> CallbackHandler;

class AbstractNetworkOps {

    typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

public:
    AbstractNetworkOps();
    AbstractNetworkOps(boost::asio::io_service& io_service, boost::asio::ssl::context& context);
    virtual ~AbstractNetworkOps();
    ssl_socket::lowest_layer_type& socket();
    void setCallbackHandler(CallbackHandler cb);

protected:
    ssl_socket socket_;
    enum { max_length = 1024 };
    CallbackHandler callback_handler = NULL;

protected:
    void read();
    void send(vector<string>);
    void process_read(char* buffer, int size, int type);

private:
    void saveCloseSocket();

};


#endif






