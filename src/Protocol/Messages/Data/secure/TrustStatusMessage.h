#ifndef TRUSTSTATUSMESSAGE_H
#define TRUSTSTATUSMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Engines/IO/Network/Utils/BooleanByteWrapper.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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