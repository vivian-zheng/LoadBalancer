#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"

using std::string;

class Webserver {
    public:    
        Webserver();
        ~Webserver();
        void setProcess(Request* r);
        int getStatus() {return status;}
    
    private:
        Request* currReq;
        int status;         //0 = busy, 1 = available
};

#endif