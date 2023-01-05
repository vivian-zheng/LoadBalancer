#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using std::string;

class Request {
    public:    
        //constructor, destructor, getter, setter
        Request();
        ~Request();
        int getRuntime() const {return runtime;}
        int getStartTime() const {return startTime;}
        string getIPin() const {return IPin;}
        string getIPout() const {return IPout;}

        void setStartTime(int sT) {startTime = sT;}

        // Helper function to generate IP
        string generateIP();
    
    private:
        string IPin;
        string IPout;
        int runtime;        // Amount of time each request takes
        int startTime;
};

#endif