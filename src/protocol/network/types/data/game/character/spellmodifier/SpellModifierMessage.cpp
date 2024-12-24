#include "SpellModifierMessage.h"

void SpellModifierMessage::serialize(Writer *output)
{
  this->serializeAs_SpellModifierMessage(output);
}

void SpellModifierMessage::serializeAs_SpellModifierMessage(Writer *output)
{
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellModifierMessage -"<<"Forbidden value (" << this->spellId << ") on element spellId.";
  }
  output->writeVarShort((int)this->spellId);
  output->writeByte(this->actionType);
  output->writeByte(this->modifierType);
  output->writeInt((int)this->context);
  output->writeInt((int)this->equipment);
}

void SpellModifierMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpellModifierMessage(input);
}

void SpellModifierMessage::deserializeAs_SpellModifierMessage(Reader *input)
{
  this->_spellIdFunc(input);
  this->_actionTypeFunc(input);
  this->_modifierTypeFunc(input);
  this->_contextFunc(input);
  this->_equipmentFunc(input);
}

void SpellModifierMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpellModifierMessage(tree);
}

void SpellModifierMessage::deserializeAsyncAs_SpellModifierMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SpellModifierMessage::_spellIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellModifierMessage::_actionTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellModifierMessage::_modifierTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellModifierMessage::_contextFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SpellModifierMessage::_equipmentFunc, this, std::placeholders::_1));
}

void SpellModifierMessage::_spellIdFunc(Reader *input)
{
  this->spellId = input->readVarUhShort();
  if(this->spellId < 0)
  {
    qDebug()<<"ERREUR - SpellModifierMessage -"<<"Forbidden value (" << this->spellId << ") on element of SpellModifierMessage.spellId.";
  }
}

void SpellModifierMessage::_actionTypeFunc(Reader *input)
{
  this->actionType = input->readByte();
  if(this->actionType < 0)
  {
    qDebug()<<"ERREUR - SpellModifierMessage -"<<"Forbidden value (" << this->actionType << ") on element of SpellModifierMessage.actionType.";
  }
}

void SpellModifierMessage::_modifierTypeFunc(Reader *input)
{
  this->modifierType = input->readByte();
  if(this->modifierType < 0)
  {
    qDebug()<<"ERREUR - SpellModifierMessage -"<<"Forbidden value (" << this->modifierType << ") on element of SpellModifierMessage.modifierType.";
  }
}

void SpellModifierMessage::_contextFunc(Reader *input)
{
  this->context = input->readInt();
}

void SpellModifierMessage::_equipmentFunc(Reader *input)
{
  this->equipment = input->readInt();
}

SpellModifierMessage::SpellModifierMessage()
{
  m_types<<ClassEnum::SPELLMODIFIERMESSAGE;
}

bool SpellModifierMessage::operator==(const SpellModifierMessage &compared)
{
  if(spellId == compared.spellId)
  if(actionType == compared.actionType)
  if(modifierType == compared.modifierType)
  if(context == compared.context)
  if(equipment == compared.equipment)
  return true;
  
  return false;
}

