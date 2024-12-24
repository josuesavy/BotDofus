#ifndef GAMEFIGHTSTARTMESSAGE_H
#define GAMEFIGHTSTARTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightStartMessage(FuncTree tree);
  GameFightStartMessage();
};

#endif // GAMEFIGHTSTARTMESSAGE_H