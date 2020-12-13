#ifndef PRISMFIGHTDEFENDERADDMESSAGE_H
#define PRISMFIGHTDEFENDERADDMESSAGE_H

#include "src/protocol/types/data/game/character/CharacterMinimalPlusLookInformations.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/Protocol/Types/ClassManager.h"
#include "src/protocol/messages/AbstractMessage.h"

class PrismFightDefenderAddMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_PrismFightDefenderAddMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_PrismFightDefenderAddMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_PrismFightDefenderAddMessage(FuncTree tree);
  PrismFightDefenderAddMessage();

  uint subAreaId;
  uint fightId;
  QSharedPointer<CharacterMinimalPlusLookInformations> defender;

private:
  void _subAreaIdFunc(Reader *input);
  void _fightIdFunc(Reader *input);
  void _defendertreeFunc(Reader *input);

  FuncTree _defendertree;
};

#endif // PRISMFIGHTDEFENDERADDMESSAGE_H