// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.

#include "BeverageBeverageService.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using namespace  ::vending_machine;

class BeverageBeverageServiceHandler : virtual public BeverageBeverageServiceIf {
 public:
  BeverageBeverageServiceHandler() {
    // Your initialization goes here
  }

  void getBeverage(std::string& _return, const BeverageType::type btype) {
    // Your implementation goes here
    printf("getBeverage\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  ::std::shared_ptr<BeverageBeverageServiceHandler> handler(new BeverageBeverageServiceHandler());
  ::std::shared_ptr<TProcessor> processor(new BeverageBeverageServiceProcessor(handler));
  ::std::shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  ::std::shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  ::std::shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

