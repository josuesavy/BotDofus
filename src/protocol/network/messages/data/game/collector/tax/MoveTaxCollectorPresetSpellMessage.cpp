#include "MoveTaxCollectorPresetSpellMessage.h"

void MoveTaxCollectorPresetSpellMessage::serialize(Writer *output)
{
  this->serializeAs_MoveTaxCollectorPresetSpellMessage(output);
}

void MoveTaxCollectorPresetSpellMessage::serializeAs_MoveTaxCollectorPresetSpellMessage(Writer *output)
{
  this->presetId.serializeAs_uuid(output);
  if(this->movedFrom < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->movedFrom << ") on element movedFrom.";
  }
  output->writeByte(this->movedFrom);
  if(this->movedTo < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->movedTo << ") on element movedTo.";
  }
  output->writeByte(this->movedTo);
}

void MoveTaxCollectorPresetSpellMessage::deserialize(Reader *input)
{
  this->deserializeAs_MoveTaxCollectorPresetSpellMessage(input);
}

void MoveTaxCollectorPresetSpellMessage::deserializeAs_MoveTaxCollectorPresetSpellMessage(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserialize(input);
  this->_movedFromFunc(input);
  this->_movedToFunc(input);
}

void MoveTaxCollectorPresetSpellMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MoveTaxCollectorPresetSpellMessage(tree);
}

void MoveTaxCollectorPresetSpellMessage::deserializeAsyncAs_MoveTaxCollectorPresetSpellMessage(FuncTree tree)
{
  this->_presetIdtree = tree.addChild(std::bind(&MoveTaxCollectorPresetSpellMessage::_presetIdtreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoveTaxCollectorPresetSpellMessage::_movedFromFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MoveTaxCollectorPresetSpellMessage::_movedToFunc, this, std::placeholders::_1));
}

void MoveTaxCollectorPresetSpellMessage::_presetIdtreeFunc(Reader *input)
{
  this->presetId = uuid();
  this->presetId.deserializeAsync(this->_presetIdtree);
}

void MoveTaxCollectorPresetSpellMessage::_movedFromFunc(Reader *input)
{
  this->movedFrom = input->readByte();
  if(this->movedFrom < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->movedFrom << ") on element of MoveTaxCollectorPresetSpellMessage.movedFrom.";
  }
}

void MoveTaxCollectorPresetSpellMessage::_movedToFunc(Reader *input)
{
  this->movedTo = input->readByte();
  if(this->movedTo < 0)
  {
    qDebug()<<"ERREUR - MoveTaxCollectorPresetSpellMessage -"<<"Forbidden value (" << this->movedTo << ") on element of MoveTaxCollectorPresetSpellMessage.movedTo.";
  }
}

MoveTaxCollectorPresetSpellMessage::MoveTaxCollectorPresetSpellMessage()
{
  m_type = MessageEnum::MOVETAXCOLLECTORPRESETSPELLMESSAGE;
}

