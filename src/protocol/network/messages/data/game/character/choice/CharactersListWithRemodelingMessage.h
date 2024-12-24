#ifndef CHARACTERSLISTWITHREMODELINGMESSAGE_H
#define CHARACTERSLISTWITHREMODELINGMESSAGE_H

#include "src/protocol/network/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/protocol/network/types/data/game/character/choice/CharacterToRemodelInformations.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/character/choice/CharactersListMessage.h"

class CharactersListWithRemodelingMessage : public CharactersListMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_CharactersListWithRemodelingMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_CharactersListWithRemodelingMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_CharactersListWithRemodelingMessage(FuncTree tree);
  CharactersListWithRemodelingMessage();

  QList<CharacterToRemodelInformations> charactersToRemodel;

private:
  void _charactersToRemodeltreeFunc(Reader *input);
  void _charactersToRemodelFunc(Reader *input);

  FuncTree _charactersToRemodeltree;
};

#endif // CHARACTERSLISTWITHREMODELINGMESSAGE_H