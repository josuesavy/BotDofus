#include "PresetDeleteResultMessage.h"

void PresetDeleteResultMessage::serialize(Writer *output)
{
  this->serializeAs_PresetDeleteResultMessage(output);
}

void PresetDeleteResultMessage::serializeAs_PresetDeleteResultMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  output->writeByte(this->code);
}

void PresetDeleteResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetDeleteResultMessage(input);
}

void PresetDeleteResultMessage::deserializeAs_PresetDeleteResultMessage(Reader *input)
{
  this->_presetIdFunc(input);
  this->_codeFunc(input);
}

void PresetDeleteResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetDeleteResultMessage(tree);
}

void PresetDeleteResultMessage::deserializeAsyncAs_PresetDeleteResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetDeleteResultMessage::_presetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PresetDeleteResultMessage::_codeFunc, this, std::placeholders::_1));
}

void PresetDeleteResultMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void PresetDeleteResultMessage::_codeFunc(Reader *input)
{
  this->code = input->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - PresetDeleteResultMessage -"<<"Forbidden value (" << this->code << ") on element of PresetDeleteResultMessage.code.";
  }
}

PresetDeleteResultMessage::PresetDeleteResultMessage()
{
  m_type = MessageEnum::PRESETDELETERESULTMESSAGE;
}

