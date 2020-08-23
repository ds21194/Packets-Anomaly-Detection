#ifndef __ANOMALY_FILE_READER__
#define __ANOMALY_FILE_READER__

/**
This file is describing the ip ranges of malicious ip addresses.
Format of the file:

IP_START_RANGE:IP_END_RANGE

EXAMPLE:

1.180.0.0 1.185.255.255
8.210.44.0  8.210.45.255

1.0.1.0:1.0.3.255
1.0.8.0:1.0.15.255
1.0.32.0:1.0.63.255
1.1.0.0:1.1.0.255
1.1.2.0:1.1.63.255
1.2.0.0:1.2.2.255
1.2.4.0:1.2.127.255
1.3.0.0:1.3.255.255
1.4.1.0:1.4.127.255
1.8.0.0:1.8.255.255
1.10.0.0:1.10.9.255
1.80.0.0:1.95.255.255

*/

#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include <stdexcept>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <string>
#include "PacketInfo.hpp"

class AnomalyFileReader{
private:
  // Error messages:
  #define ANOMALY_FILE "../SP/http_requests"
  #define WRONG_FORMAT_ERROR "File is not in the right format"
  #define PACKET_REGEX R"(.+)\sIP\s(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})\.(\d{1,5})\s>\s(\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3})\.(\d{1,5})"
  #define TIMESTAMP_GR 1
  #define IP_S_GR 2
  #define PORT_S_GR 3
  #define IP_D_GR 4
  #define PORT_D_GR 5


  struct PackDetails{
    int port_s;
    int port_d;
    std::string timestamp;
    std::string time;
    std::string ip_s;
    std::string ip_d;
  } PackDetails;

  std::ifstream file; // file to read from
  std::vector<struct PackDetails> packs; // form after saving

  void readFile();

  void extractPacket(std::string packet);

public:
  /**
   * @filepath: file path to the anomaly file
   */
  AnomalyFileReader(std::string filepath);

  /**
   * read and return all IpAddresses in the file
   */
  std::vector<std::string> getIpAddresses();

  /**
   * read and return all packets in the file"
   */
  std::vector<PacketInfo> getPackets();

  /**
   * read and return all ips of the same packet in a tuple of
   * <sourceIP, destinationIP>
   */
  std::vector<std::tuple<std::string, std::string>> getPacketsIp();


  ~AnomalyFileReader();
};

#endif
