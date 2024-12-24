#ifndef GAMEFIGHTTURNRESUMEMESSAGE_H
#define GAMEFIGHTTURNRESUMEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/context/fight/GameFightTurnStartMessage.h"

class GameFightTurnResumeMessage : public GameFightTurnStartMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnResumeMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnResumeMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnResumeMessage(FuncTree tree);
  GameFightTurnResumeMessage();

  uint remainingTime;

private:
  void _remainingTimeFunc(Reader *input);
};

#endif // GAMEFIGHTTURNRESUMEMESSAGE_H