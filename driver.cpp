#include <iostream>
#include <fstream>
#include <stdlib.h>  
#include <string>
#include "time.h"

#include "loadBalancer.h"
#include "request.h"
#include "webserver.h"

using std::cout, std::endl, std::to_string, std::cin, std::ofstream;

//NOTE: all doxygen comments completed with chatGPT

/**
 * @brief Vector of pointers to Webserver objects representing the servers in the simulation.
 */
vector<Webserver*> servers;

/**
 * @brief LoadBalancer object representing the load balancer in the simulation.
 */
LoadBalancer lb;

/**
 * @brief Integer variable representing the number of servers in the simulation.
 */
int numServers = 0;

/**
 * @brief Integer variable representing the current clock cycle in the simulation.
 */
int currCycle = 0;

/**
 * @brief ofstream object for writing log information to a file.
 */
ofstream logfile;

/**
 * @brief Integer variable representing the next time a random request will be added to the simulation.
 */
int randomSendTime = -1;

/**
 * @brief Integer constant representing the maximum number of clock cycles in the simulation.
 */
int MAX_CLOCK_CYCLES = 10000;

/**
 * @brief Integer constant representing the initial number of requests in the simulation.
 */
int NUM_REQUESTS = 200;

/**
 * @brief Initializes the servers in the simulation.
 *
 * @param numServers The number of servers to initialize.
 */
void initializeServers(int numServers) {
    for(int i = 0; i < numServers; i++) {
        Webserver* w = new Webserver(to_string(i + 1));
        servers.push_back(w);
    }
}

/**
 * @brief Initializes the request queue in the load balancer with a given number of requests.
 *
 * @param initalNum The number of requests to add to the queue.
 */
void initializeQueue(int initalNum) {
    for(int i = 0; i < initalNum; i++) {
        Request* r = new Request();
        lb.pushRequest(r);
    }
}

/**
 * @brief Adds a random number of requests to the request queue in the load balancer.
 */
void pushRandomRequests() {
    int numRequests = rand() % 2;
    for(int i = 0; i < numRequests; i++) {
        Request* r = new Request();
        lb.pushRequest(r);
    }
}

/**
 * @brief The main function of the program.
 *
 * @return The exit code of the program.
 */
int main() {
    // Seed a time for better randomness
    srand(time(0));

    // Open file for writing
    logfile.open("load_balancer_log.txt");

    // INITIALIZE SERVERS
    cout << "Please enter the number of servers you want: ";
    cin >> numServers;
    initializeServers(numServers);

    // ADD 1000 RANDOM REQUESTS TO QUEUE in LB
    initializeQueue(NUM_REQUESTS);

    // Loop through each clock cycle
    while(currCycle < MAX_CLOCK_CYCLES) {
        //Randomly add new requests
        if(randomSendTime <= currCycle) {
            pushRandomRequests();
            randomSendTime = (rand() % 10) + currCycle + 2;
        }

        // Loop through each server
        for(int i = 0; i < numServers; i++) {
            // Get the current server
            Webserver* currServer = servers.at(i);

            // Check status, 0 = busy, 1 = available
            // If the server is available, get a new request and process it in the server and set the server status as busy
            if(currServer->getStatus() == 1) {
                Request* newR = lb.popRequest();

                if(newR == nullptr) {
                    cout << "Queue is empty!" << endl;
                    return 0;
                }

                newR->setStartTime(currCycle);
                currServer->setProcess(newR);
                currServer->setStatus();
            }

            // Check if the current request is done (by comparing current time with estimated end time)
            int endTime = currServer->getRequest()->getRuntime() + currServer->getRequest()->getStartTime();

            // If the current request is done, output status and set the new status of the server to available
            if(currCycle == endTime) {
                string logString = "Clock cycle " + to_string(currCycle) + ": server " + currServer->getName() + " completed request from " + currServer->getRequest()->getIPin() + " to " + currServer->getRequest()->getIPout() + "\n";
                cout << logString;
                logfile << logString;
                currServer->setStatus();
            }
        }
        currCycle++;
    }

    string endSizeString = "End size: " + to_string(lb.getRequestVector().size()) + "\n";
    cout << "End size of queue: " << lb.getRequestVector().size() << endl;
    logfile << endSizeString;

    // Close file
    logfile.close();

    return 0;
}
