#ifndef __PACKET_INFO__
#define __PACKET_INFO__

#include <iostream>
#include "IpAddr.hpp"

class PacketInfo{
private:
  IpAddr* sourceIp;
  IpAddr* destinationIp;

public:
    PacketInfo(char* sourceIp, char* destinationIp);


    PacketInfo(std::string& sourceIp, std::string& destinationIp);

    /**
     * get the destination IP Adress
     * @return: String of an IP Adress
     */
    virtual IpAddr& getDestinationIP() const = 0;

    /**
     * get the source IP Adress
     * @return String of an IP Adress
     */
    virtual IpAddr& getSourceIP() const = 0;

    /**
     * check if ip is equal to source or destination ip
     * @return: true if it is equal, and false otherwise
     */
    virtual bool contains(IpAddr& ip) = 0;

    ~PacketInfo();
};

#endif
