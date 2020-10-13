#ifndef GAMEACTIONNOOPMESSAGE_H
#define GAMEACTIONNOOPMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GameActionNoopMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameActionNoopMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameActionNoopMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameActionNoopMessage(FuncTree tree);
  GameActionNoopMessage();
};

#endif // GAMEACTIONNOOPMESSAGE_H