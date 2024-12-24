#ifndef GAMEFIGHTTURNENDMESSAGE_H
#define GAMEFIGHTTURNENDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightTurnEndMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnEndMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnEndMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnEndMessage(FuncTree tree);
  GameFightTurnEndMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // GAMEFIGHTTURNENDMESSAGE_H