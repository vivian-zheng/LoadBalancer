#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>
#include "request.h"

using std::vector;

class LoadBalancer {
    public:    
        //constructor, destructor, getter, setter
        LoadBalancer();
        ~LoadBalancer();

        Request* popRequest();
        void pushRequest(Request* r);
        vector<Request*> getRequestVector() {return requestQueue;}

    
    private:
        //queue of requests
        vector<Request*> requestQueue;
};

#endif