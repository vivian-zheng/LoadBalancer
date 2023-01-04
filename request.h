#ifndef REQUEST_H
#define REQUEST_H

#include <string>

using std::string;

class request {
    public:    
        //constructor, destructor, getter, setter
    
    private:
        string IPin;
        string IPout;
        double time;        // Amount of time each request takes
};

#endif