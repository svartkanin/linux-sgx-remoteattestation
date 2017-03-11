#include "Session.h"

#include <boost/lexical_cast.hpp>

using namespace util;

Session::Session(boost::asio::io_service& io_service, boost::asio::ssl::context& context) : AbstractNetworkOps(io_service, context) {}

Session::~Session() {}


void Session::start() {
    Log("Connection from %s", socket().remote_endpoint().address().to_string());

    socket_.async_handshake(boost::asio::ssl::stream_base::server,
                            boost::bind(&Session::handle_handshake, this,
                                        boost::asio::placeholders::error));
}


void Session::handle_handshake(const boost::system::error_code& error) {
    if (!error) {
        Log("Handshake successful");
        this->read();
    } else {
        Log("Handshake was not successful: %s", error.message(), log::error);
        delete this;
    }
}




