#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <string>

//NOTE: all doxygen comments completed with chatGPT

/**
 * @file webserver.h
 *
 * This file contains the declaration of the Webserver class.
 */

/**
 * @brief Namespace for the standard C++ library.
 */
using std::string;

/**
 * @brief Forward declaration of the Request class.
 */
class Request;

/**
 * @brief Class representing a web server in the load balancing simulation.
 */
class Webserver {
    public:
        /**
         * @brief Constructor for the Webserver class.
         *
         * @param name The name of the server.
         */
        Webserver(string name);

        /**
         * @brief Destructor for the Webserver class.
         */
        ~Webserver();

        /**
         * @brief Sets the current request being processed by the server.
         *
         * @param r The request to set.
         */
        void setProcess(Request* r);

        /**
         * @brief Gets the current request being processed by the server.
         *
         * @return The current request being processed by the server.
         */
        Request* getRequest() {return currReq;}

        /**
         * @brief Gets the status of the server.
         *
         * @return The status of the server. 0 if busy, 1 if available.
         */
        int getStatus() {return status;}

        /**
         * @brief Sets the status of the server.
         */
        void setStatus();

        /**
         * @brief Gets the name of the server.
         *
         * @return The name of the server.
         */
        string getName() {return name;}

    private:
            /**
             * @brief The current request being processed by the server.
             */
            Request* currReq;

            /**
             * @brief The status of the server. 0 if busy, 1 if available.
             */
            int status; 

            /**
             * @brief The name of the server.
             */
            string name;
};

#endif
