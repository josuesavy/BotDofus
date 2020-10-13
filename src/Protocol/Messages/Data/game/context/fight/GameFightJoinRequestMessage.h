#ifndef GAMEFIGHTJOINREQUESTMESSAGE_H
#define GAMEFIGHTJOINREQUESTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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