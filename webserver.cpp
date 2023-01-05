#include <iostream>
#include <stdlib.h>  

#include "webserver.h"

using std::cout, std::endl, std::string;

Webserver::Webserver(string n) {
    name = n;
    status = 1;
}

Webserver::~Webserver() {

}

void Webserver::setProcess(Request* r) {
    currReq = r;
}

void Webserver::setStatus() {
    if(status == 0) {
        status = 1;
        return;
    } 

    status = 0;
}


// int main() {


//     return 0;
// }