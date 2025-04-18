/**
 * Autogenerated by Thrift Compiler (0.19.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef BeverageBeverageService_H
#define BeverageBeverageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class BeverageBeverageServiceIf {
 public:
  virtual ~BeverageBeverageServiceIf() {}
  virtual void getBeverage(std::string& _return, const BeverageType::type btype) = 0;
};

class BeverageBeverageServiceIfFactory {
 public:
  typedef BeverageBeverageServiceIf Handler;

  virtual ~BeverageBeverageServiceIfFactory() {}

  virtual BeverageBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(BeverageBeverageServiceIf* /* handler */) = 0;
  };

class BeverageBeverageServiceIfSingletonFactory : virtual public BeverageBeverageServiceIfFactory {
 public:
  BeverageBeverageServiceIfSingletonFactory(const ::std::shared_ptr<BeverageBeverageServiceIf>& iface) : iface_(iface) {}
  virtual ~BeverageBeverageServiceIfSingletonFactory() {}

  virtual BeverageBeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(BeverageBeverageServiceIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<BeverageBeverageServiceIf> iface_;
};

class BeverageBeverageServiceNull : virtual public BeverageBeverageServiceIf {
 public:
  virtual ~BeverageBeverageServiceNull() {}
  void getBeverage(std::string& /* _return */, const BeverageType::type /* btype */) override {
    return;
  }
};

typedef struct _BeverageBeverageService_getBeverage_args__isset {
  _BeverageBeverageService_getBeverage_args__isset() : btype(false) {}
  bool btype :1;
} _BeverageBeverageService_getBeverage_args__isset;

class BeverageBeverageService_getBeverage_args {
 public:

  BeverageBeverageService_getBeverage_args(const BeverageBeverageService_getBeverage_args&) noexcept;
  BeverageBeverageService_getBeverage_args& operator=(const BeverageBeverageService_getBeverage_args&) noexcept;
  BeverageBeverageService_getBeverage_args() noexcept
                                           : btype(static_cast<BeverageType::type>(0)) {
  }

  virtual ~BeverageBeverageService_getBeverage_args() noexcept;
  /**
   * 
   * @see BeverageType
   */
  BeverageType::type btype;

  _BeverageBeverageService_getBeverage_args__isset __isset;

  void __set_btype(const BeverageType::type val);

  bool operator == (const BeverageBeverageService_getBeverage_args & rhs) const
  {
    if (!(btype == rhs.btype))
      return false;
    return true;
  }
  bool operator != (const BeverageBeverageService_getBeverage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BeverageBeverageService_getBeverage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class BeverageBeverageService_getBeverage_pargs {
 public:


  virtual ~BeverageBeverageService_getBeverage_pargs() noexcept;
  /**
   * 
   * @see BeverageType
   */
  const BeverageType::type* btype;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BeverageBeverageService_getBeverage_result__isset {
  _BeverageBeverageService_getBeverage_result__isset() : success(false) {}
  bool success :1;
} _BeverageBeverageService_getBeverage_result__isset;

class BeverageBeverageService_getBeverage_result {
 public:

  BeverageBeverageService_getBeverage_result(const BeverageBeverageService_getBeverage_result&);
  BeverageBeverageService_getBeverage_result& operator=(const BeverageBeverageService_getBeverage_result&);
  BeverageBeverageService_getBeverage_result() noexcept
                                             : success() {
  }

  virtual ~BeverageBeverageService_getBeverage_result() noexcept;
  std::string success;

  _BeverageBeverageService_getBeverage_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const BeverageBeverageService_getBeverage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const BeverageBeverageService_getBeverage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BeverageBeverageService_getBeverage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BeverageBeverageService_getBeverage_presult__isset {
  _BeverageBeverageService_getBeverage_presult__isset() : success(false) {}
  bool success :1;
} _BeverageBeverageService_getBeverage_presult__isset;

class BeverageBeverageService_getBeverage_presult {
 public:


  virtual ~BeverageBeverageService_getBeverage_presult() noexcept;
  std::string* success;

  _BeverageBeverageService_getBeverage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class BeverageBeverageServiceClient : virtual public BeverageBeverageServiceIf {
 public:
  BeverageBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  BeverageBeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getBeverage(std::string& _return, const BeverageType::type btype) override;
  void send_getBeverage(const BeverageType::type btype);
  void recv_getBeverage(std::string& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class BeverageBeverageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<BeverageBeverageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (BeverageBeverageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_getBeverage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  BeverageBeverageServiceProcessor(::std::shared_ptr<BeverageBeverageServiceIf> iface) :
    iface_(iface) {
    processMap_["getBeverage"] = &BeverageBeverageServiceProcessor::process_getBeverage;
  }

  virtual ~BeverageBeverageServiceProcessor() {}
};

class BeverageBeverageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  BeverageBeverageServiceProcessorFactory(const ::std::shared_ptr< BeverageBeverageServiceIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< BeverageBeverageServiceIfFactory > handlerFactory_;
};

class BeverageBeverageServiceMultiface : virtual public BeverageBeverageServiceIf {
 public:
  BeverageBeverageServiceMultiface(std::vector<std::shared_ptr<BeverageBeverageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~BeverageBeverageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<BeverageBeverageServiceIf> > ifaces_;
  BeverageBeverageServiceMultiface() {}
  void add(::std::shared_ptr<BeverageBeverageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void getBeverage(std::string& _return, const BeverageType::type btype) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->getBeverage(_return, btype);
    }
    ifaces_[i]->getBeverage(_return, btype);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class BeverageBeverageServiceConcurrentClient : virtual public BeverageBeverageServiceIf {
 public:
  BeverageBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  BeverageBeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void getBeverage(std::string& _return, const BeverageType::type btype) override;
  int32_t send_getBeverage(const BeverageType::type btype);
  void recv_getBeverage(std::string& _return, const int32_t seqid);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif

} // namespace

#endif
