#ifndef PRISMFIGHTATTACKERADDMESSAGE_H
#define PRISMFIGHTATTACKERADDMESSAGE_H

#include "src/Protocol/Types/Data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class PrismFightAttackerAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightAttackerAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightAttackerAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightAttackerAddMessage(FuncTree tree);
  PrismFightAttackerAddMessage();

  uint subAreaId;
  uint fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> attacker;

private:
  void _subAreaIdFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _attackertreeFunc(Reader *input);

  FuncTree _attackertree;
};

#endif // PRISMFIGHTATTACKERADDMESSAGE_H