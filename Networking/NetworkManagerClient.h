#include "NetworkManager.h"

class NetworkManagerClient : public NetworkManager {

public:
    static NetworkManagerClient* getInstance(int port, std::string host = "localhost");
    void Init();
    void connectCallbackHandler(CallbackHandler cb);
    void startService();
    void setHost(std::string host);

private:
    NetworkManagerClient();

private:
    static NetworkManagerClient* instance;
    std::string host;
    Client *client = NULL;
};



