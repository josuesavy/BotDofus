#ifndef GAMEFIGHTTURNSTARTMESSAGE_H
#define GAMEFIGHTTURNSTARTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightTurnStartMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnStartMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnStartMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnStartMessage(FuncTree tree);
  GameFightTurnStartMessage();

  double id;
  uint waitTime;

private:
  void _idFunc(Reader *input);
  void _waitTimeFunc(Reader *input);
};

#endif // GAMEFIGHTTURNSTARTMESSAGE_H