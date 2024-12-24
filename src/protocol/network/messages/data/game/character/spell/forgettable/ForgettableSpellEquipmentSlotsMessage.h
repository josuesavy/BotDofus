#ifndef FORGETTABLESPELLEQUIPMENTSLOTSMESSAGE_H
#define FORGETTABLESPELLEQUIPMENTSLOTSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class ForgettableSpellEquipmentSlotsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_ForgettableSpellEquipmentSlotsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_ForgettableSpellEquipmentSlotsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_ForgettableSpellEquipmentSlotsMessage(FuncTree tree);
  ForgettableSpellEquipmentSlotsMessage();

  int quantity;

private:
  void _quantityFunc(Reader *input);
};

#endif // FORGETTABLESPELLEQUIPMENTSLOTSMESSAGE_H