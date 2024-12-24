#ifndef CHARACTERSLISTMESSAGE_H
#define CHARACTERSLISTMESSAGE_H

#include "src/protocol/network/types/ClassManager.h"
#include "src/protocol/network/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class CharactersListMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharactersListMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharactersListMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharactersListMessage(FuncTree tree);
  CharactersListMessage();

  QList<QSharedPointer<CharacterBaseInformations>> characters;

private:
  void _characterstreeFunc(Reader *input);
  void _charactersFunc(Reader *input);

  FuncTree _characterstree;
};

#endif // CHARACTERSLISTMESSAGE_H