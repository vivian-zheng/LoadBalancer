#include <iostream>
#include <stdlib.h>  
#include <string>

#include "request.h"

using std::cout, std::endl, std::stoi, std::to_string;

/**
* @brief Generates a random IP address in the format "XXX.XXX.XXX.XXX".
* @return A string containing the generated IP address.
*/
string Request::generateIP() {
    string IP = "";

    int firstOctet = rand() % 256;
    int secondOctet = rand() % 256;
    int thirdOctet = rand() % 256;
    int fourthOctet = rand() % 256;

    IP = to_string(firstOctet) + "." + to_string(secondOctet) + "." + to_string(thirdOctet) + "." + to_string(fourthOctet);

    return IP;
}

/**
* @brief Constructor for the Request class.
* @details Initializes the runtime and generates the IPin and IPout fields by calling the generateIP() function.
*/
Request::Request() {
    // Generating the random runtime
    runtime = 2 + rand() % 235;

    // Generating the IP Addresses
    IPin = generateIP();
    IPout = generateIP();
}

/**
* @brief Destructor for the Request class.
* @details Resets the values of the runtime, startTime, IPin, and IPout fields.
*/
Request::~Request() {
    runtime = 0;
    startTime = 0;
    IPin = "";
    IPout = "";
}


// int main() {
//     Request r1;
//     cout << "r1 in: " << r1.getIPin() << endl;
//     cout << "r1 out: " << r1.getIPout() << endl;
//     cout << "r1 runtime: " << r1.getRuntime() << endl;

//     Request r2;
//     cout << "r2 in: " << r2.getIPin() << endl;
//     cout << "r2 out: " << r2.getIPout() << endl;
//     cout << "r2 runtime: " << r2.getRuntime() << endl;

//     return 0;
// }