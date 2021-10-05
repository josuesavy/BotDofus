#ifndef TRUSTCERTIFICATE_H
#define TRUSTCERTIFICATE_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class TrustCertificate : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TrustCertificate(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TrustCertificate(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TrustCertificate(FuncTree tree);
  TrustCertificate();
  bool operator==(const TrustCertificate &compared);

  uint id;
  QString hash;

private:
  void _idFunc(Reader *input);
  void _hashFunc(Reader *input);
};

#endif // TRUSTCERTIFICATE_H