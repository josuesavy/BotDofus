#ifndef PRISMSETSABOTAGEDREFUSEDMESSAGE_H
#define PRISMSETSABOTAGEDREFUSEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismSetSabotagedRefusedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismSetSabotagedRefusedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismSetSabotagedRefusedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismSetSabotagedRefusedMessage(FuncTree tree);
  PrismSetSabotagedRefusedMessage();

  uint subAreaId;
  int reason;

private:
  void _subAreaIdFunc(Reader *input);
  void _reasonFunc(Reader *input);
};

#endif // PRISMSETSABOTAGEDREFUSEDMESSAGE_H