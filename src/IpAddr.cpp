#include "IpAddr.hpp"

IpAddr::IpAddr(char* ip){

  int dotOc = 0;
  for(int i = 0; ip[i] != '\0'; ++i){
    if(ip[i] == '.') dotOc++;
  }
  if(dotOc != 4)
    throw ILLEGAL_IP_EXCEPTION;

  ip = strtok(ip, ".");

  this->u1 = toShort(&(ip[0]));
  this->u2 = toShort(&(ip[1]));
  this->u3 = toShort(&(ip[2]));
  this->u4 = toShort(&(ip[3]));
}

IpAddr::IpAddr(IpAddr const& other) :
 u1(other.u1),
 u2(other.u2),
 u3(other.u3),
 u4(other.u4) {}

IpAddr::IpAddr(std::string& ip){
  const std::regex regex(IP_REGEX);
  std::smatch match;
  if(std::regex_match(ip, match, regex)){
   this->u1 = std::stoi(match.str(1));
   this->u2 = std::stoi(match.str(2));
   this->u3 = std::stoi(match.str(3));
   this->u4 = std::stoi(match.str(4));
  }else{
   throw ILLEGAL_IP_EXCEPTION;
  }
}

IpAddr::IpAddr(IpAddr && other) noexcept {
   swap(*this, other);
 }

inline bool IpAddr::operator<=(const IpAddr& lhr){
  if(this->u1 < lhr.u1) return true;
  if(this->u1 > lhr.u1) return false;

  if(this->u2 < lhr.u2) return true;
  if(this->u2 > lhr.u2) return false;

  if(this->u3 < lhr.u3) return true;
  if(this->u3 > lhr.u3) return false;

  if(this->u4 < lhr.u4) return true;
  if(this->u4 > lhr.u4) return false;

  return true;
}

IpAddr& IpAddr::operator=(IpAddr other){
  swap(*this, other);
  return *this;
}

IpAddr& IpAddr::operator=(IpAddr&& other) noexcept {
  swap(*this, other);
  return *this;
}

inline bool IpAddr::operator>=(const IpAddr& lhr){
  return !(*this <= lhr);
}

inline bool IpAddr::operator==(const IpAddr& lhr){
  return (*this <= lhr) && (*this >= lhr);
}

short IpAddr::toShort(const char* number){
  short num;
  try{
    num = atoi(number);
  } catch (std::exception e){
    throw ILLEGAL_IP_EXCEPTION;
  }

  if(num < 0 || num > 256){
    throw ILLEGAL_IP_EXCEPTION;
  }

  return num;
}

void swap(IpAddr& lhr, IpAddr& lhs) noexcept{
  std::swap(lhr.u1, lhs.u1);
  std::swap(lhr.u2, lhs.u2);
  std::swap(lhr.u3, lhs.u3);
  std::swap(lhr.u4, lhs.u4);
}
