#ifndef __iP_ADDR__
#define __iP_ADDR__

#include <string.h>
#include <iostream>
#include <exception>
#include <regex>
#include <sstream>
#include <string>

class IpAddr{
private:
  short u1;
  short u2;
  short u3;
  short u4;


  #define ILLEGAL_IP_EXCEPTION "Illegal IP address"
  #define IP_REGEX R"(\d+)"

  short toShort(const char* number);

  friend void swap(IpAddr& lhr, IpAddr& lhs) noexcept;

public:

  IpAddr(char* ip);

  IpAddr(std::string& ip);

  IpAddr(IpAddr const& other);

  IpAddr(IpAddr && other)noexcept;

  IpAddr& operator=(IpAddr other);

  IpAddr& operator=(IpAddr&& other) noexcept;

  inline bool operator<=(const IpAddr& lhr);

  inline bool operator>=(const IpAddr& lhr);

  inline bool operator==(const IpAddr& lhr);


};

#endif
