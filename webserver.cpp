#include <iostream>
#include <stdlib.h>  

#include "webserver.h"

//NOTE: all doxygen comments completed with chatGPT

/**
 * @brief Namespace for the standard C++ library.
 */
using std::cout, std::endl, std::string;

/**
 * @brief Constructor for the Webserver class.
 *
 * @param n The name of the server.
 */
Webserver::Webserver(string n) {
    name = n;
    status = 1;
}

/**
 * @brief Destructor for the Webserver class.
 */
Webserver::~Webserver() {

}

/**
 * @brief Sets the current request being processed by the server.
 *
 * @param r The request to set.
 */
void Webserver::setProcess(Request* r) {
    currReq = r;
}

/**
 * @brief Sets the status of the server.
 */
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