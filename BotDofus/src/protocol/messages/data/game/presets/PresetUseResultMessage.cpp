#include "PresetUseResultMessage.h"

void PresetUseResultMessage::serialize(Writer *output)
{
  this->serializeAs_PresetUseResultMessage(output);
}

void PresetUseResultMessage::serializeAs_PresetUseResultMessage(Writer *output)
{
  output->writeShort((short)this->presetId);
  output->writeByte(this->code);
}

void PresetUseResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetUseResultMessage(input);
}

void PresetUseResultMessage::deserializeAs_PresetUseResultMessage(Reader *input)
{
  this->_presetIdFunc(input);
  this->_codeFunc(input);
}

void PresetUseResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetUseResultMessage(tree);
}

void PresetUseResultMessage::deserializeAsyncAs_PresetUseResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PresetUseResultMessage::_presetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PresetUseResultMessage::_codeFunc, this, std::placeholders::_1));
}

void PresetUseResultMessage::_presetIdFunc(Reader *input)
{
  this->presetId = input->readShort();
}

void PresetUseResultMessage::_codeFunc(Reader *input)
{
  this->code = input->readByte();
  if(this->code < 0)
  {
    qDebug()<<"ERREUR - PresetUseResultMessage -"<<"Forbidden value (" << this->code << ") on element of PresetUseResultMessage.code.";
  }
}

PresetUseResultMessage::PresetUseResultMessage()
{
  m_type = MessageEnum::PRESETUSERESULTMESSAGE;
}

