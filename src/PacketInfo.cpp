#include "PacketInfo.hpp"

PacketInfo::PacketInfo(char* sourceIp, char* destinationIp){
  this->sourceIp = new IpAddr(sourceIp); // TODO: exchange with smart pointers
  this->destinationIp = new IpAddr(destinationIp);
}


PacketInfo::PacketInfo(std::string& sourceIp, std::string& destinationIp){
  // this->sourceIp = // TODO: exchange with smart pointers
  this->sourceIp = new IpAddr(sourceIp);
  this->destinationIp = new IpAddr(destinationIp);
}

PacketInfo::~PacketInfo(){
  delete(this->sourceIp);
  delete(this->destinationIp);
}
