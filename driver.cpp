#include <iostream>
#include <stdlib.h>  
#include <string>
#include "time.h"

#include "loadBalancer.h"
#include "request.h"
#include "webserver.h"

using std::cout, std::endl, std::to_string;

vector<Webserver*> servers;
LoadBalancer lb;
int numServers = 0;
int currCycle = 0;

int MAX_CLOCK_CYCLES = 10000;
int NUM_REQUESTS = 10000;

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
    int numRequests = 2 + rand() % 100;
    for(int i = 0; i < numRequests; i++) {
        Request* r = new Request();
        lb.pushRequest(r);
    }
}


int main() {
    // Seed a time for better randomness
    srand(time(0));

    // INITIALIZE SERVERS
    numServers = 10;
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
                cout << "Clock cycle " << currCycle << ": server " << currServer->getName() << " completed request from " << currServer->getRequest()->getIPin() << " to " << currServer->getRequest()->getIPout() << endl;
                currServer->setStatus();
            }
        }
        currCycle++;

    }

    



    return 0;
}