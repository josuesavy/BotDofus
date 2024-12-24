#ifndef GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H
#define GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GameFightOptionStateUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GameFightOptionStateUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GameFightOptionStateUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GameFightOptionStateUpdateMessage(FuncTree tree);
  GameFightOptionStateUpdateMessage();

  uint fightId;
  uint teamId;
  uint option;
  bool state;

private:
  void _fightIdFunc(Reader *input);
  void _teamIdFunc(Reader *input);
  void _optionFunc(Reader *input);
  void _stateFunc(Reader *input);
};

#endif // GAMEFIGHTOPTIONSTATEUPDATEMESSAGE_H