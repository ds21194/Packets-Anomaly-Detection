#ifndef __ANOMALY_INTERFACE__
#define __ANOMALY_INTERFACE__

#include "IpAddr.hpp"

class AnomalyInterface{
public:

    /*
     * check whether the packet is considered an anomaly
     * @return: will return true if packet is considered anomaly and false otherwise
     */
    virtual bool anomalityCheck(IpAddr& ip) = 0;
};

#endif
