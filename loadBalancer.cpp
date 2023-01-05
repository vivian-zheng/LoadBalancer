#include <iostream>
#include <stdlib.h>  

#include "loadBalancer.h"
#include "request.h"

using std::cout, std::endl;

LoadBalancer::LoadBalancer() {
    
}

LoadBalancer::~LoadBalancer() {

}

Request* LoadBalancer::popRequest() {
    if(requestQueue.empty()) {
        return nullptr;
    }

    Request* newReq = requestQueue.front();
    requestQueue.erase(requestQueue.begin());

    return newReq;
}

void LoadBalancer::pushRequest(Request* r) {
    requestQueue.push_back(r);
}

// int main() {
//     LoadBalancer lb;
    
//     Request r1;
//     cout << "r1 in: " << r1.getIPin() << endl;
//     cout << "r1 out: " << r1.getIPout() << endl;
//     cout << "r1 runtime: " << r1.getRuntime() << endl;

//     Request r2;
//     cout << "r2 in: " << r2.getIPin() << endl;
//     cout << "r2 out: " << r2.getIPout() << endl;
//     cout << "r2 runtime: " << r2.getRuntime() << endl;

//     Request r3;
//     cout << "r3 in: " << r3.getIPin() << endl;
//     cout << "r3 out: " << r3.getIPout() << endl;
//     cout << "r3 runtime: " << r3.getRuntime() << endl;

//     Request r4;
//     cout << "r4 in: " << r4.getIPin() << endl;
//     cout << "r4 out: " << r4.getIPout() << endl;
//     cout << "r4 runtime: " << r4.getRuntime() << endl;

//     lb.pushRequest(&r1);
//     lb.pushRequest(&r2);
//     lb.pushRequest(&r3);
//     lb.pushRequest(&r4);

//     Request* currReq = lb.popRequest();
//     cout << "currReq in: " << currReq->getIPin() << endl;
//     cout << "currReq out: " << currReq->getIPout() << endl;
//     cout << "currReq runtime: " << currReq->getRuntime() << endl;

//     return 0;
// }