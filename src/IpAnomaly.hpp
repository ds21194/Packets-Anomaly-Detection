#ifndef __IP_ANOMALY__
#define __IP_ANOMALY__

#include <iostream>
#include <vector>
#include <string.h>
#include "AnomalyInterface.hpp"

class IpAnomaly : public AnomalyInterface{
private:

    IpAddr* ip_start;
    IpAddr* ip_end;

public:
    /**
     * create an object that describe an ip anomaly (range of ip addresses)
     */
    IpAnomaly(char* start, char* end);

    /*
     * check whether the ip is considered an anomaly
     * @return: will return true if ip is considered anomaly and false otherwise
     */
    bool anomalityCheck(const IpAddr& ip);

    ~IpAnomaly();
};
#endif
