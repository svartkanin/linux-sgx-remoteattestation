#include "NetworkManagerClient.h"
#include "../GeneralSettings.h"

NetworkManagerClient* NetworkManagerClient::instance = NULL;

NetworkManagerClient::NetworkManagerClient() {}


void NetworkManagerClient::Init() {
    if (client) {
        delete client;
        client = NULL;
    }

    boost::asio::ip::tcp::resolver resolver(this->io_service);
    boost::asio::ip::tcp::resolver::query query(this->host, std::to_string(this->port).c_str());
    boost::asio::ip::tcp::resolver::iterator iterator = resolver.resolve(query);

    boost::asio::ssl::context ctx(boost::asio::ssl::context::sslv23);
    ctx.load_verify_file(Settings::server_crt);

    this->client = new Client(io_service, ctx, iterator);
}


NetworkManagerClient* NetworkManagerClient::getInstance(int port,  std::string host) {
    if (instance == NULL) {
        instance = new NetworkManagerClient();
        instance->setPort(port);
        instance->setHost(host);
    }

    return instance;
}


void NetworkManagerClient::startService() {
    this->client->startConnection();
}


void NetworkManagerClient::setHost(std::string host) {
    this->host = host;
}


void NetworkManagerClient::connectCallbackHandler(CallbackHandler cb) {
    this->client->setCallbackHandler(cb);
}


























