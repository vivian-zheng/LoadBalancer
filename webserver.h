#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>
#include "request.h"

using std::string;

class Webserver {
    public:    
        //constructor, destructor, getter, setter
        Webserver();
        ~Webserver();
        void changeStatus();
        void setProcess(Request* r);

        //get request
        //process request
        //ask for request
    
    private:
        //process 
        Request currReq;
        int status;         //0 = busy, 1 = available
};

#endif