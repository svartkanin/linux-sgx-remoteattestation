#include "NetworkManagerServer.h"

NetworkManagerServer* NetworkManagerServer::instance = NULL;

NetworkManagerServer::NetworkManagerServer() {}


void NetworkManagerServer::Init() {
    this->server = new Server(this->io_service, this->port);
}


NetworkManagerServer* NetworkManagerServer::getInstance(int port) {
    if (instance == NULL) {
        instance = new NetworkManagerServer();
        instance->setPort(port);
    }

    return instance;
}


void NetworkManagerServer::startService() {
    this->server->start_accept();
    this->io_service.run();
}


void NetworkManagerServer::connectCallbackHandler(CallbackHandler cb) {
    this->server->connectCallbackHandler(cb);
}


