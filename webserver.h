#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"

using std::string;

class Webserver {
    public:    
        Webserver(string name);
        ~Webserver();
        void setProcess(Request* r);
        Request* getRequest() {return currReq;}
        int getStatus() {return status;}
        void setStatus();
        string getName() {return name;}

    
    private:
        Request* currReq;
        int status;         //0 = busy, 1 = available
        string name;
};

#endif