#ifndef SETCHARACTERRESTRICTIONSMESSAGE_H
#define SETCHARACTERRESTRICTIONSMESSAGE_H

#include "src/protocol/network/types/data/game/character/restriction/ActorRestrictionsInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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