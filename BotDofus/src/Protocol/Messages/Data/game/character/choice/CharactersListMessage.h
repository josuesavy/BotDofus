#ifndef CHARACTERSLISTMESSAGE_H
#define CHARACTERSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/character/choice/BasicCharactersListMessage.h"

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