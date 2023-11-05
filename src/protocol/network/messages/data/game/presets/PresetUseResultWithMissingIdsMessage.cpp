#include "PresetUseResultWithMissingIdsMessage.h"

void PresetUseResultWithMissingIdsMessage::serialize(Writer *output)
{
  this->serializeAs_PresetUseResultWithMissingIdsMessage(output);
}

void PresetUseResultWithMissingIdsMessage::serializeAs_PresetUseResultWithMissingIdsMessage(Writer *output)
{
  PresetUseResultMessage::serializeAs_PresetUseResultMessage(output);
  output->writeShort((short)this->missingIds.size());
  for(uint _i1 = 0; _i1 < this->missingIds.size(); _i1++)
  {
    if(this->missingIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - PresetUseResultWithMissingIdsMessage -"<<"Forbidden value (" << this->missingIds[_i1] << ") on element 1 (starting at 1) of missingIds.";
    }
    output->writeVarShort((int)this->missingIds[_i1]);
  }
}

void PresetUseResultWithMissingIdsMessage::deserialize(Reader *input)
{
  this->deserializeAs_PresetUseResultWithMissingIdsMessage(input);
}

void PresetUseResultWithMissingIdsMessage::deserializeAs_PresetUseResultWithMissingIdsMessage(Reader *input)
{
  uint _val1 = 0;
  PresetUseResultMessage::deserialize(input);
  uint _missingIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _missingIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - PresetUseResultWithMissingIdsMessage -"<<"Forbidden value (" << _val1 << ") on elements of missingIds.";
    }
    this->missingIds.append(_val1);
  }
}

void PresetUseResultWithMissingIdsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PresetUseResultWithMissingIdsMessage(tree);
}

void PresetUseResultWithMissingIdsMessage::deserializeAsyncAs_PresetUseResultWithMissingIdsMessage(FuncTree tree)
{
  PresetUseResultMessage::deserializeAsync(tree);
  this->_missingIdstree = tree.addChild(std::bind(&PresetUseResultWithMissingIdsMessage::_missingIdstreeFunc, this, std::placeholders::_1));
}

void PresetUseResultWithMissingIdsMessage::_missingIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_missingIdstree.addChild(std::bind(&PresetUseResultWithMissingIdsMessage::_missingIdsFunc, this, std::placeholders::_1));
  }
}

void PresetUseResultWithMissingIdsMessage::_missingIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - PresetUseResultWithMissingIdsMessage -"<<"Forbidden value (" << _val << ") on elements of missingIds.";
  }
  this->missingIds.append(_val);
}

PresetUseResultWithMissingIdsMessage::PresetUseResultWithMissingIdsMessage()
{
  m_type = MessageEnum::PRESETUSERESULTWITHMISSINGIDSMESSAGE;
}

