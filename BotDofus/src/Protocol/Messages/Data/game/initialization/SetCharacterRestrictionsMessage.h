#ifndef SETCHARACTERRESTRICTIONSMESSAGE_H
#define SETCHARACTERRESTRICTIONSMESSAGE_H

#include "src/Protocol/Types/Data/game/character/restriction/ActorRestrictionsInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class SetCharacterRestrictionsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_SetCharacterRestrictionsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_SetCharacterRestrictionsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_SetCharacterRestrictionsMessage(FuncTree tree);
  SetCharacterRestrictionsMessage();

  double actorId;
  ActorRestrictionsInformations restrictions;

private:
  void _actorIdFunc(Reader *input);
  void _restrictionstreeFunc(Reader *input);

  FuncTree _restrictionstree;
};

#endif // SETCHARACTERRESTRICTIONSMESSAGE_H