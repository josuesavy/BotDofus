#ifndef PRISMUSEREQUESTMESSAGE_H
#define PRISMUSEREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismUseRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismUseRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismUseRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismUseRequestMessage(FuncTree tree);
  PrismUseRequestMessage();

  uint moduleToUse;

private:
  void _moduleToUseFunc(Reader *input);
};

#endif // PRISMUSEREQUESTMESSAGE_H