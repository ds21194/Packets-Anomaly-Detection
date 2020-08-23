#include "IpAnomaly.hpp"


IpAnomaly::IpAnomaly(char* start, char* end){
  this->ip_start = new IpAddr(start);
  this->ip_end = new IpAddr(end);
}

bool IpAnomaly::anomalityCheck(const IpAddr& ip){
  return *this->ip_start <= ip && *this->ip_end >= ip;
}

IpAnomaly::~IpAnomaly(){
  delete(this->ip_start);
  delete(this->ip_end);
}
