#include <iostream>
#include <fstream>
#include <stdlib.h>  
#include <string>
#include "time.h"

#include "loadBalancer.h"
#include "request.h"
#include "webserver.h"

using std::cout, std::endl, std::to_string, std::cin, std::ofstream;

vector<Webserver*> servers;
LoadBalancer lb;
int numServers = 0;
int currCycle = 0;

ofstream logfile;

int randomSendTime = -1;

int MAX_CLOCK_CYCLES = 10000;
int NUM_REQUESTS = 200;

void initializeServers(int numServers) {
    for(int i = 0; i < numServers; i++) {
        Webserver* w = new Webserver(to_string(i + 1));
        servers.push_back(w);
    }
}

void initializeQueue(int initalNum) {
    for(int i = 0; i < initalNum; i++) {
        Request* r = new Request();
        lb.pushRequest(r);
    }
}

void pushRandomRequests() {
    int numRequests = rand() % 2;
    for(int i = 0; i < numRequests; i++) {
        Request* r = new Request();
        lb.pushRequest(r);
    }
}

int main() {
    // Seed a time for better randomness
    srand(time(0));

    // Open file for writing
    logfile.open("load_balancer_log.txt");

    // INITIALIZE SERVERS
    cout << "Please enter the number of servers you want: ";
    cin >> numServers;
    initializeServers(numServers);

    // Test if servers initialized
    // for(int i = 0; i < 10; i++) {
    //     cout << servers.at(i)->getName() << endl;
    // }

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
    cout << "End size: " << lb.getRequestVector().size() << endl;
    logfile << endSizeString;
    
    logfile.close();


    return 0;
}