#ifndef LOADBALANCER_H
#define LOADBALANCER_H

#include <string>
#include <vector>

//NOTE: all doxygen comments completed with chatGPT

/**
 * @file loadbalancer.h
 *
 * This file contains the declaration of the LoadBalancer class.
 */

/**
 * @brief Forward declaration of the Request class.
 */
#include "request.h"

/**
 * @brief Namespace for the standard C++ library.
 */
using std::vector;

/**
 * @brief Class representing a load balancer in the load balancing simulation.
 */
class LoadBalancer {
    public:
        /**
         * @brief Constructor for the LoadBalancer class.
         */
        LoadBalancer();

        /**
         * @brief Destructor for the LoadBalancer class.
         */
        ~LoadBalancer();

        /**
         * @brief Removes a request from the request queue.
         *
         * @return The request that was removed from the queue.
         */
        Request* popRequest();

        /**
         * @brief Adds a request to the request queue.
         *
         * @param r The request to add to the queue.
         */
        void pushRequest(Request* r);

        /**
         * @brief Gets the request queue.
         *
         * @return The request queue.
         */
        vector<Request*> getRequestVector() {return requestQueue;}

    private:
        /**
        * @brief The request queue.
        */
        vector<Request*> requestQueue;
};

#endif