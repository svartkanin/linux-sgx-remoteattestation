#include "NetworkManager.h"

class NetworkManagerServer : public NetworkManager {

public:
    static NetworkManagerServer* getInstance(int port);
    void Init();
    void connectCallbackHandler(CallbackHandler cb);
    void startService();

private:
    NetworkManagerServer();

private:
    static NetworkManagerServer* instance;
    Server *server = NULL;

};



