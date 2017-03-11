#ifndef CLIENT_H
#define CLIENT_H

#include "AbstractNetworkOps.h"

using namespace std;

class Client : public AbstractNetworkOps {

public:
    Client(boost::asio::io_service& io_service, boost::asio::ssl::context& context, boost::asio::ip::tcp::resolver::iterator endpoint_iterator);

    virtual ~Client();
    bool verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx);
    void handle_connect(const boost::system::error_code& error);
    void handle_handshake(const boost::system::error_code& error);

    void startConnection();

private:
    boost::asio::ip::tcp::resolver::iterator endpoint_iterator;

};

#endif
