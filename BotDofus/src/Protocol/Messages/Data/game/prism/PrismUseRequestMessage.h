#ifndef PRISMUSEREQUESTMESSAGE_H
#define PRISMUSEREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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