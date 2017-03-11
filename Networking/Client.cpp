#include "Client.h"
#include "LogBase.h"
#include "Network_def.h"
#include "Messages.pb.h"

#include <boost/lexical_cast.hpp>

using namespace util;

Client::Client(boost::asio::io_service& io_service,
               boost::asio::ssl::context& context,
               boost::asio::ip::tcp::resolver::iterator endpoint_iterator) : AbstractNetworkOps(io_service, context) {
    socket_.set_verify_mode(boost::asio::ssl::verify_peer);
    socket_.set_verify_callback(boost::bind(&Client::verify_certificate, this, _1, _2));

    this->endpoint_iterator = endpoint_iterator;
}

Client::~Client() {}


void Client::startConnection() {
    Log("Start connecting...");

    boost::system::error_code ec;
    boost::asio::connect(socket_.lowest_layer(), this->endpoint_iterator, ec);

    handle_connect(ec);
}


bool Client::verify_certificate(bool preverified, boost::asio::ssl::verify_context& ctx) {
    char subject_name[256];
    X509* cert = X509_STORE_CTX_get_current_cert(ctx.native_handle());
    X509_NAME_oneline(X509_get_subject_name(cert), subject_name, 256);

    Log("Verifying certificate: %s", subject_name);

    return preverified;
}


void Client::handle_connect(const boost::system::error_code &error) {
    if (!error) {
        Log("Connection established");

        boost::system::error_code ec;
        socket_.handshake(boost::asio::ssl::stream_base::client, ec);

        handle_handshake(ec);
    } else {
        Log("Connect failed: %s", error.message(), log::error);
    }
}


void Client::handle_handshake(const boost::system::error_code& error) {
    if (!error) {
        Log("Handshake successful");

        auto ret = this->callback_handler("", -1);
        send(ret);
    } else {
        Log("Handshake failed: %s", error.message(), log::error);
    }
}






