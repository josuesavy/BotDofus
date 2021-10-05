#ifndef PRISMSLISTUPDATEMESSAGE_H
#define PRISMSLISTUPDATEMESSAGE_H

#include "src/protocol/types/data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/prism/PrismsListMessage.h"

class PrismsListUpdateMessage : public PrismsListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismsListUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismsListUpdateMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismsListUpdateMessage(FuncTree tree);
  PrismsListUpdateMessage();
};

#endif // PRISMSLISTUPDATEMESSAGE_H