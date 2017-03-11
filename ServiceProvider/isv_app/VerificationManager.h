#ifndef VERIFICATIONMANAGER_H
#define VERIFICATIONMANAGER_H

#include <string>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>

#include "ServiceProvider.h"
#include "NetworkManagerClient.h"
#include "LogBase.h"
#include "Messages.pb.h"
#include "WebService.h"

using namespace std;

class VerificationManager {

public:
    static VerificationManager* getInstance();
    virtual ~VerificationManager();
    int init();
    vector<string> incomingHandler(string v, int type);
    void start();

private:
    VerificationManager();
    string prepareVerificationRequest();
    string handleMSG0(Messages::MessageMsg0 m);
    string handleMSG1(Messages::MessageMSG1 msg);
    string handleMSG3(Messages::MessageMSG3 msg);
    string createInitMsg(int type, string msg);
    string handleAppAttOk();

private:
    static VerificationManager* instance;
    NetworkManagerClient *nm = NULL;
    ServiceProvider *sp = NULL;
    WebService *ws = NULL;
};

#endif











