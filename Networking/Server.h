#ifndef SERVER_H
#define SERVER_H

#include "Session.h"
#include "LogBase.h"

#include <cstdlib>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ssl.hpp>


class Server {

    typedef boost::asio::ssl::stream<boost::asio::ip::tcp::socket> ssl_socket;

public:
    Server(boost::asio::io_service& io_service, int port);
    virtual ~Server();
    std::string get_password() const;
    void handle_accept(Session* new_session, const boost::system::error_code& error);
    void start_accept();
    void connectCallbackHandler(CallbackHandler cb);

private:
    boost::asio::io_service& io_service_;
    boost::asio::ip::tcp::acceptor acceptor_;
    boost::asio::ssl::context context_;
    CallbackHandler callback_handler;
};


#endif


