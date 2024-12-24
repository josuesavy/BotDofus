#ifndef TRUSTSTATUSMESSAGE_H
#define TRUSTSTATUSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class TrustStatusMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TrustStatusMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TrustStatusMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TrustStatusMessage(FuncTree tree);
  TrustStatusMessage();

  bool certified;

private:
  void _certifiedFunc(Reader *input);
};

#endif // TRUSTSTATUSMESSAGE_H