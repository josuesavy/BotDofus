#ifndef BREACHKICKRESPONSEMESSAGE_H
#define BREACHKICKRESPONSEMESSAGE_H

#include "src/protocol/network/types/data/game/character/CharacterMinimalInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class BreachKickResponseMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BreachKickResponseMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BreachKickResponseMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BreachKickResponseMessage(FuncTree tree);
  BreachKickResponseMessage();

  CharacterMinimalInformations target;
  bool kicked;

private:
  void _targettreeFunc(Reader *input);
  void _kickedFunc(Reader *input);

  FuncTree _targettree;
};

#endif // BREACHKICKRESPONSEMESSAGE_H