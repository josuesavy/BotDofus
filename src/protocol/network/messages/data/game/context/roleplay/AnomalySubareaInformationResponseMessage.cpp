#include "AnomalySubareaInformationResponseMessage.h"

void AnomalySubareaInformationResponseMessage::serialize(Writer *output)
{
  this->serializeAs_AnomalySubareaInformationResponseMessage(output);
}

void AnomalySubareaInformationResponseMessage::serializeAs_AnomalySubareaInformationResponseMessage(Writer *output)
{
  output->writeShort((short)this->subareas.size());
  for(uint _i1 = 0; _i1 < this->subareas.size(); _i1++)
  {
    (this->subareas[_i1]).serializeAs_AnomalySubareaInformation(output);
  }
}

void AnomalySubareaInformationResponseMessage::deserialize(Reader *input)
{
  this->deserializeAs_AnomalySubareaInformationResponseMessage(input);
}

void AnomalySubareaInformationResponseMessage::deserializeAs_AnomalySubareaInformationResponseMessage(Reader *input)
{
  AnomalySubareaInformation _item1 ;
  uint _subareasLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _subareasLen; _i1++)
  {
    _item1 = AnomalySubareaInformation();
    _item1.deserialize(input);
    this->subareas.append(_item1);
  }
}

void AnomalySubareaInformationResponseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AnomalySubareaInformationResponseMessage(tree);
}

void AnomalySubareaInformationResponseMessage::deserializeAsyncAs_AnomalySubareaInformationResponseMessage(FuncTree tree)
{
  this->_subareastree = tree.addChild(std::bind(&AnomalySubareaInformationResponseMessage::_subareastreeFunc, this, std::placeholders::_1));
}

void AnomalySubareaInformationResponseMessage::_subareastreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_subareastree.addChild(std::bind(&AnomalySubareaInformationResponseMessage::_subareasFunc, this, std::placeholders::_1));
  }
}

void AnomalySubareaInformationResponseMessage::_subareasFunc(Reader *input)
{
  AnomalySubareaInformation _item = AnomalySubareaInformation();
  _item.deserialize(input);
  this->subareas.append(_item);
}

AnomalySubareaInformationResponseMessage::AnomalySubareaInformationResponseMessage()
{
  m_type = MessageEnum::ANOMALYSUBAREAINFORMATIONRESPONSEMESSAGE;
}

