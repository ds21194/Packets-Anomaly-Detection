#include "TestInterface.hpp"
#include "../src/IpAddr.hpp"

class IpAddrTest : public TestInterface {
public:
  IpAddrTest();

  void IpCreationTest();

  void IpCreationError();

  void IpEqTest();
};
