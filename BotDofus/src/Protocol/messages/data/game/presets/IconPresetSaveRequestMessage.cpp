#include "IconPresetSaveRequestMessage.h"

void IconPresetSaveRequestMessage::serialize(Writer *output)
{
  this->serializeAs_IconPresetSaveRequestMessage(output);
}

void IconPresetSaveRequestMessage::serializeAs_IconPresetSaveRequestMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  if(this->symbolId < 0)
  {
    qDebug()<<"ERREUR - IconPresetSaveRequestMessage -"<<"Forbidden value (" << this->symbolId << ") on element symbolId.";
  }
  output->writeByte(this->symbolId);
  output->writeBool(this->updateData);
}

void IconPresetSaveRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_IconPresetSaveRequestMessage(input);
}

void IconPresetSaveRequestMessage::deserializeAs_IconPresetSaveRequestMessage(Reader *input)
{
  this->_presetIdFunc(input);
  this->_symbolIdFunc(input);
  this->_updateDataFunc(input);
}

void IconPresetSaveRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IconPresetSaveRequestMessage(tree);
}

void IconPresetSaveRequestMessage::deserializeAsyncAs_IconPresetSaveRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IconPresetSaveRequestMessage::_presetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IconPresetSaveRequestMessage::_symbolIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&IconPresetSaveRequestMessage::_updateDataFunc, this, std::placeholders::_1));
}

void IconPresetSaveRequestMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void IconPresetSaveRequestMessage::_symbolIdFunc(Reader *input)
{
  this->symbolId = input->readByte();
  if(this->symbolId < 0)
  {
    qDebug()<<"ERREUR - IconPresetSaveRequestMessage -"<<"Forbidden value (" << this->symbolId << ") on element of IconPresetSaveRequestMessage.symbolId.";
  }
}

void IconPresetSaveRequestMessage::_updateDataFunc(Reader *input)
{
  this->updateData = input->readBool();
}

IconPresetSaveRequestMessage::IconPresetSaveRequestMessage()
{
  m_type = MessageEnum::ICONPRESETSAVEREQUESTMESSAGE;
}

