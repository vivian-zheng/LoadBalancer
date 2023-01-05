#ifndef REQUEST_H
#define REQUEST_H

#include <string>

/**
 * @file request.h
 *
 * This file contains the declaration of the Request class.
 */

/**
 * @brief Namespace for the standard C++ library.
 */
using std::string;

/**
 * @brief Class representing a request in the load balancing simulation.
 */
class Request {
    public:
        /**
         * @brief Constructor for the Request class.
         */
        Request();

        /**
         * @brief Destructor for the Request class.
         */
        ~Request();

        /**
         * @brief Gets the runtime of the request.
         *
         * @return The runtime of the request.
         */
        int getRuntime() const {return runtime;}

        /**
         * @brief Gets the start time of the request.
         *
         * @return The start time of the request.
         */
        int getStartTime() const {return startTime;}

        /**
         * @brief Gets the incoming IP address of the request.
         *
         * @return The incoming IP address of the request.
         */
        string getIPin() const {return IPin;}

        /**
         * @brief Gets the outgoing IP address of the request.
         *
         * @return The outgoing IP address of the request.
         */
        string getIPout() const {return IPout;}

        /**
         * @brief Sets the start time of the request.
         *
         * @param sT The start time to set.
         */
        void setStartTime(int sT) {startTime = sT;}

        /**
         * @brief Helper function to generate a random IP address.
         *
         * @return The generated IP address.
         */
        string generateIP();
    
    private:
        /**
         * @brief The incoming IP address of the request.
         */
        string IPin;

        /**
         * @brief The outgoing IP address of the request.
         */
        string IPout;

        /**
         * @brief The runtime of the request.
         */
        int runtime;

        /**
         * @brief The start time of the request.
         */
        int startTime;
};

#endif
