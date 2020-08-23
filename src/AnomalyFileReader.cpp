#include "AnomalyFileReader.hpp"

AnomalyFileReader::AnomalyFileReader(std::string filepath){
  this->file.open(filepath, std::ios::in);

}

void AnomalyFileReader::readFile(){
  std::string line;
  if(file.is_open()){
    while(std::getline(this->file, line)){
        this->extractPacket(line);
    }
  }
}


void AnomalyFileReader::extractPacket(std::string packet) {
  const std::regex regex(PACKET_REGEX);
  std::smatch match;
  std::regex_match(packet, match, regex);

  struct PackDetails pack = {
    .timestamp = match.str(TIMESTAMP_GR),
    .port_s = std::stoi(match.str(PORT_S_GR)),
    .port_d = std::stoi(match.str(PORT_D_GR)),
    .ip_s = match.str(IP_S_GR).c_str(),
    .ip_d = match.str(IP_S_GR).c_str()
  };

  this->packs.push_back(pack);
}

std::vector<std::string>
AnomalyFileReader::getIpAddresses(){
  if(this->packs.empty()){
    this->readFile();
  }

  std::vector<std::string> result;
  for(uint i = 0; i < this->packs.size(); i++){
    result.push_back(this->packs[i].ip_s);
    result.push_back(this->packs[i].ip_d);
  }

  return result;
}


std::vector<PacketInfo> AnomalyFileReader::getPackets(){
  if(this->packs.empty()){
    this->readFile();
  }

  std::vector<PacketInfo> packets;
  for(uint i = 0; i < this->packs.size(); ++i){
    // PacketInfo pack(this->packs[i].ip_s, this->packs[i].ip_d.c_str()); //TODO: add class that implement PacketInfo and use it here
  }

  return packets;
}


std::vector<std::tuple<std::string, std::string>>
AnomalyFileReader::getPacketsIp(){
  if(this->packs.empty()){
    this->readFile();
  }

  std::vector<std::tuple<std::string, std::string>> packs;
  for(uint i = 0; i < this->packs.size(); ++i){
    packs.push_back({this->packs[i].ip_s, this->packs[i].ip_d});
  }

  return packs;
}

AnomalyFileReader::~AnomalyFileReader(){
  file.close();
}
