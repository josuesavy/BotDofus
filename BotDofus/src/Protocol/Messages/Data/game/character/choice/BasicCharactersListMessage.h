#ifndef BASICCHARACTERSLISTMESSAGE_H
#define BASICCHARACTERSLISTMESSAGE_H

#include "src/protocol/types/data/game/character/choice/CharacterBaseInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

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