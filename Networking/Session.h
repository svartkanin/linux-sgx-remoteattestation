#ifndef SESSION_H
#define SESSION_H

#include "AbstractNetworkOps.h"

using namespace std;

class Session : public AbstractNetworkOps {

    typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

public:
    Session(boost::asio::io_service& io_service, boost::asio::ssl::context& context);
    virtual ~Session();
    void start();
    void handle_handshake(const boost::system::error_code& error);

};


#endif






