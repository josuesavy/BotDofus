#include "PresetSaveErrorMessage.h"

void PresetSaveErrorMessage::serialize(Writer *output)
{
  this->serializeAs_PresetSaveErrorMessage(output);
}

void PresetSaveErrorMessage::serializeAs_PresetSaveErrorMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  output->writeByte(this->code);
}

void PresetSaveErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetSaveErrorMessage(input);
}

void PresetSaveErrorMessage::deserializeAs_PresetSaveErrorMessage(Reader *input)
{
  this->_presetIdFunc(input);
  this->_codeFunc(input);
}

void PresetSaveErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetSaveErrorMessage(tree);
}

void PresetSaveErrorMessage::deserializeAsyncAs_PresetSaveErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetSaveErrorMessage::_presetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PresetSaveErrorMessage::_codeFunc, this, std::placeholders::_1));
}

void PresetSaveErrorMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void PresetSaveErrorMessage::_codeFunc(Reader *input)
{
  this->code = input->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - PresetSaveErrorMessage -"<<"Forbidden value (" << this->code << ") on element of PresetSaveErrorMessage.code.";
  }
}

PresetSaveErrorMessage::PresetSaveErrorMessage()
{
  m_type = MessageEnum::PRESETSAVEERRORMESSAGE;
}

