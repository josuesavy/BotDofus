#ifndef CHARACTERSLISTWITHREMODELINGMESSAGE_H
#define CHARACTERSLISTWITHREMODELINGMESSAGE_H

#include "src/Protocol/Types/Data/game/character/choice/CharacterToRemodelInformations.h"
#include "src/Protocol/Types/Data/game/character/choice/CharacterBaseInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"
#include "src/Protocol/Messages/Data/game/character/choice/CharactersListMessage.h"

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