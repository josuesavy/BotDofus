#ifndef CHARACTERSLISTMESSAGE_H
#define CHARACTERSLISTMESSAGE_H

#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/character/choice/BasicCharactersListMessage.h"

class CharactersListMessage : public BasicCharactersListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharactersListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharactersListMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharactersListMessage(FuncTree tree);
  CharactersListMessage();

  bool hasStartupActions;

private:
  void _hasStartupActionsFunc(Reader *input);
};

#endif // CHARACTERSLISTMESSAGE_H