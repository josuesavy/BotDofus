#ifndef GAMEFIGHTTURNREADYREQUESTMESSAGE_H
#define GAMEFIGHTTURNREADYREQUESTMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GameFightTurnReadyRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightTurnReadyRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightTurnReadyRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightTurnReadyRequestMessage(FuncTree tree);
  GameFightTurnReadyRequestMessage();

  double id;

private:
  void _idFunc(Reader *input);
};

#endif // GAMEFIGHTTURNREADYREQUESTMESSAGE_H