#ifndef GAMEFIGHTJOINREQUESTMESSAGE_H
#define GAMEFIGHTJOINREQUESTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightJoinRequestMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightJoinRequestMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightJoinRequestMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightJoinRequestMessage(FuncTree tree);
  GameFightJoinRequestMessage();

  double fighterId;
  uint fightId;

private:
  void _fighterIdFunc(Reader *input);
  void _fightIdFunc(Reader *input);
};

#endif // GAMEFIGHTJOINREQUESTMESSAGE_H