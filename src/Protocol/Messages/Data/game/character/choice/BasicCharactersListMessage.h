#ifndef BASICCHARACTERSLISTMESSAGE_H
#define BASICCHARACTERSLISTMESSAGE_H

#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class BasicCharactersListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_BasicCharactersListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_BasicCharactersListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_BasicCharactersListMessage(FuncTree tree);
  BasicCharactersListMessage();

  QList<QSharedPointer<CharacterBaseInformations>> characters;

private:
  void _characterstreeFunc(Reader *input);
  void _charactersFunc(Reader *input);

  FuncTree _characterstree;
};

#endif // BASICCHARACTERSLISTMESSAGE_H