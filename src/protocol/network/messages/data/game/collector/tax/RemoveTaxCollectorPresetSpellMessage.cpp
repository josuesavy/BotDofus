#include "RemoveTaxCollectorPresetSpellMessage.h"

void RemoveTaxCollectorPresetSpellMessage::serialize(Writer *output)
{
  this->serializeAs_RemoveTaxCollectorPresetSpellMessage(output);
}

void RemoveTaxCollectorPresetSpellMessage::serializeAs_RemoveTaxCollectorPresetSpellMessage(Writer *output)
{
  this->presetId.serializeAs_Uuid(output);
  if(this->slot < 0)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->slot << ") on element slot.";
  }
  output->writeByte(this->slot);
}

void RemoveTaxCollectorPresetSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_RemoveTaxCollectorPresetSpellMessage(input);
}

void RemoveTaxCollectorPresetSpellMessage::deserializeAs_RemoveTaxCollectorPresetSpellMessage(Reader *input)
{
  this->presetId = Uuid();
  this->presetId.deserialize(input);
  this->_slotFunc(input);
}

void RemoveTaxCollectorPresetSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RemoveTaxCollectorPresetSpellMessage(tree);
}

void RemoveTaxCollectorPresetSpellMessage::deserializeAsyncAs_RemoveTaxCollectorPresetSpellMessage(FuncTree tree)
{
  this->_presetIdtree = tree.addChild(std::bind(&RemoveTaxCollectorPresetSpellMessage::_presetIdtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RemoveTaxCollectorPresetSpellMessage::_slotFunc, this, std::placeholders::_1));
}

void RemoveTaxCollectorPresetSpellMessage::_presetIdtreeFunc(Reader *input)
{
  this->presetId = Uuid();
  this->presetId.deserializeAsync(this->_presetIdtree);
}

void RemoveTaxCollectorPresetSpellMessage::_slotFunc(Reader *input)
{
  this->slot = input->readByte();
  if(this->slot < 0)
  {
    qDebug()<<"ERREUR - RemoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->slot << ") on element of RemoveTaxCollectorPresetSpellMessage.slot.";
  }
}

RemoveTaxCollectorPresetSpellMessage::RemoveTaxCollectorPresetSpellMessage()
{
  m_type = MessageEnum::REMOVETAXCOLLECTORPRESETSPELLMESSAGE;
}

