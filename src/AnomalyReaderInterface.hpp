#ifndef __ANOMALY_READER_INTERFACE__
#define __ANOMALY_READER_INTERFACE__

#include <iostream>
#include <vector>
#include "AnomalyInterface.hpp"

class AnomalyReader{

public:
    AnomalyReader(std::string& filepath);

    virtual AnomalyInterface& readAnomaly() = 0;

    virtual std::vector<AnomalyInterface>& readAnomalies() = 0;
};

#endif
