#ifndef TAXCOLLECTOREQUIPMENTUPDATEMESSAGE_H
#define TAXCOLLECTOREQUIPMENTUPDATEMESSAGE_H

#include "src/protocol/types/data/game/character/characteristic/CharacterCharacteristics.h"
#include "src/protocol/types/data/game/data/items/ObjectItem.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class TaxCollectorEquipmentUpdateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_TaxCollectorEquipmentUpdateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_TaxCollectorEquipmentUpdateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_TaxCollectorEquipmentUpdateMessage(FuncTree tree);
  TaxCollectorEquipmentUpdateMessage();

  double uniqueId;
  QSharedPointer<ObjectItem> object;
  bool added;
  CharacterCharacteristics characteristics;

private:
  void _uniqueIdFunc(Reader *input);
  void _objecttreeFunc(Reader *input);
  void _addedFunc(Reader *input);
  void _characteristicstreeFunc(Reader *input);

  FuncTree _objecttree;
  FuncTree _characteristicstree;
};

#endif // TAXCOLLECTOREQUIPMENTUPDATEMESSAGE_H