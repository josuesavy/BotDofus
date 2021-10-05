#include "ForgettableSpellEquipmentSlotsMessage.h"

void ForgettableSpellEquipmentSlotsMessage::serialize(Writer *output)
{
  this->serializeAs_ForgettableSpellEquipmentSlotsMessage(output);
}

void ForgettableSpellEquipmentSlotsMessage::serializeAs_ForgettableSpellEquipmentSlotsMessage(Writer *output)
{
  output->writeVarShort((int)this->quantity);
}

void ForgettableSpellEquipmentSlotsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ForgettableSpellEquipmentSlotsMessage(input);
}

void ForgettableSpellEquipmentSlotsMessage::deserializeAs_ForgettableSpellEquipmentSlotsMessage(Reader *input)
{
  this->_quantityFunc(input);
}

void ForgettableSpellEquipmentSlotsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ForgettableSpellEquipmentSlotsMessage(tree);
}

void ForgettableSpellEquipmentSlotsMessage::deserializeAsyncAs_ForgettableSpellEquipmentSlotsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ForgettableSpellEquipmentSlotsMessage::_quantityFunc, this, std::placeholders::_1));
}

void ForgettableSpellEquipmentSlotsMessage::_quantityFunc(Reader *input)
{
  this->quantity = input->readVarShort();
}

ForgettableSpellEquipmentSlotsMessage::ForgettableSpellEquipmentSlotsMessage()
{
  m_type = MessageEnum::FORGETTABLESPELLEQUIPMENTSLOTSMESSAGE;
}

