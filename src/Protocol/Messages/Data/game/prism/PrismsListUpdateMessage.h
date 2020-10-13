#ifndef PRISMSLISTUPDATEMESSAGE_H
#define PRISMSLISTUPDATEMESSAGE_H

#include "src/Protocol/Types/Data/game/prism/PrismSubareaEmptyInfo.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/prism/PrismsListMessage.h"

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