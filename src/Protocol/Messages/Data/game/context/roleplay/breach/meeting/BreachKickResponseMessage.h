#ifndef BREACHKICKRESPONSEMESSAGE_H
#define BREACHKICKRESPONSEMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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