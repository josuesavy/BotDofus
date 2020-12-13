#ifndef TRUSTSTATUSMESSAGE_H
#define TRUSTSTATUSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/messages/AbstractMessage.h"

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

  bool trusted;
  bool certified;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // TRUSTSTATUSMESSAGE_H