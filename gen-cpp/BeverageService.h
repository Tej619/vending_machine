/**
 * Autogenerated by Thrift Compiler (0.19.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef BeverageService_H
#define BeverageService_H

#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include <memory>
#include "vending_machine_types.h"

namespace vending_machine {

#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class BeverageServiceIf {
 public:
  virtual ~BeverageServiceIf() {}
  virtual void GetBeverage(std::string& _return, const BeverageType::type btype) = 0;
};

class BeverageServiceIfFactory {
 public:
  typedef BeverageServiceIf Handler;

  virtual ~BeverageServiceIfFactory() {}

  virtual BeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(BeverageServiceIf* /* handler */) = 0;
  };

class BeverageServiceIfSingletonFactory : virtual public BeverageServiceIfFactory {
 public:
  BeverageServiceIfSingletonFactory(const ::std::shared_ptr<BeverageServiceIf>& iface) : iface_(iface) {}
  virtual ~BeverageServiceIfSingletonFactory() {}

  virtual BeverageServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) override {
    return iface_.get();
  }
  virtual void releaseHandler(BeverageServiceIf* /* handler */) override {}

 protected:
  ::std::shared_ptr<BeverageServiceIf> iface_;
};

class BeverageServiceNull : virtual public BeverageServiceIf {
 public:
  virtual ~BeverageServiceNull() {}
  void GetBeverage(std::string& /* _return */, const BeverageType::type /* btype */) override {
    return;
  }
};

typedef struct _BeverageService_GetBeverage_args__isset {
  _BeverageService_GetBeverage_args__isset() : btype(false) {}
  bool btype :1;
} _BeverageService_GetBeverage_args__isset;

class BeverageService_GetBeverage_args {
 public:

  BeverageService_GetBeverage_args(const BeverageService_GetBeverage_args&) noexcept;
  BeverageService_GetBeverage_args& operator=(const BeverageService_GetBeverage_args&) noexcept;
  BeverageService_GetBeverage_args() noexcept
                                   : btype(static_cast<BeverageType::type>(0)) {
  }

  virtual ~BeverageService_GetBeverage_args() noexcept;
  /**
   * 
   * @see BeverageType
   */
  BeverageType::type btype;

  _BeverageService_GetBeverage_args__isset __isset;

  void __set_btype(const BeverageType::type val);

  bool operator == (const BeverageService_GetBeverage_args & rhs) const
  {
    if (!(btype == rhs.btype))
      return false;
    return true;
  }
  bool operator != (const BeverageService_GetBeverage_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BeverageService_GetBeverage_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class BeverageService_GetBeverage_pargs {
 public:


  virtual ~BeverageService_GetBeverage_pargs() noexcept;
  /**
   * 
   * @see BeverageType
   */
  const BeverageType::type* btype;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BeverageService_GetBeverage_result__isset {
  _BeverageService_GetBeverage_result__isset() : success(false) {}
  bool success :1;
} _BeverageService_GetBeverage_result__isset;

class BeverageService_GetBeverage_result {
 public:

  BeverageService_GetBeverage_result(const BeverageService_GetBeverage_result&);
  BeverageService_GetBeverage_result& operator=(const BeverageService_GetBeverage_result&);
  BeverageService_GetBeverage_result() noexcept
                                     : success() {
  }

  virtual ~BeverageService_GetBeverage_result() noexcept;
  std::string success;

  _BeverageService_GetBeverage_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const BeverageService_GetBeverage_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const BeverageService_GetBeverage_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const BeverageService_GetBeverage_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _BeverageService_GetBeverage_presult__isset {
  _BeverageService_GetBeverage_presult__isset() : success(false) {}
  bool success :1;
} _BeverageService_GetBeverage_presult__isset;

class BeverageService_GetBeverage_presult {
 public:


  virtual ~BeverageService_GetBeverage_presult() noexcept;
  std::string* success;

  _BeverageService_GetBeverage_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class BeverageServiceClient : virtual public BeverageServiceIf {
 public:
  BeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  BeverageServiceClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
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
  void GetBeverage(std::string& _return, const BeverageType::type btype) override;
  void send_GetBeverage(const BeverageType::type btype);
  void recv_GetBeverage(std::string& _return);
 protected:
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  std::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class BeverageServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::std::shared_ptr<BeverageServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) override;
 private:
  typedef  void (BeverageServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_GetBeverage(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  BeverageServiceProcessor(::std::shared_ptr<BeverageServiceIf> iface) :
    iface_(iface) {
    processMap_["GetBeverage"] = &BeverageServiceProcessor::process_GetBeverage;
  }

  virtual ~BeverageServiceProcessor() {}
};

class BeverageServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  BeverageServiceProcessorFactory(const ::std::shared_ptr< BeverageServiceIfFactory >& handlerFactory) noexcept :
      handlerFactory_(handlerFactory) {}

  ::std::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) override;

 protected:
  ::std::shared_ptr< BeverageServiceIfFactory > handlerFactory_;
};

class BeverageServiceMultiface : virtual public BeverageServiceIf {
 public:
  BeverageServiceMultiface(std::vector<std::shared_ptr<BeverageServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~BeverageServiceMultiface() {}
 protected:
  std::vector<std::shared_ptr<BeverageServiceIf> > ifaces_;
  BeverageServiceMultiface() {}
  void add(::std::shared_ptr<BeverageServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void GetBeverage(std::string& _return, const BeverageType::type btype) override {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->GetBeverage(_return, btype);
    }
    ifaces_[i]->GetBeverage(_return, btype);
    return;
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class BeverageServiceConcurrentClient : virtual public BeverageServiceIf {
 public:
  BeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> prot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
{
    setProtocol(prot);
  }
  BeverageServiceConcurrentClient(std::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, std::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot, std::shared_ptr< ::apache::thrift::async::TConcurrentClientSyncInfo> sync) : sync_(sync)
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
  void GetBeverage(std::string& _return, const BeverageType::type btype) override;
  int32_t send_GetBeverage(const BeverageType::type btype);
  void recv_GetBeverage(std::string& _return, const int32_t seqid);
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
