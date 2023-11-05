#include "NuggetsDistributionMessage.h"

void NuggetsDistributionMessage::serialize(Writer *output)
{
  this->serializeAs_NuggetsDistributionMessage(output);
}

void NuggetsDistributionMessage::serializeAs_NuggetsDistributionMessage(Writer *output)
{
  output->writeShort((short)this->beneficiaries.size());
  for(uint _i1 = 0; _i1 < this->beneficiaries.size(); _i1++)
  {
    (this->beneficiaries[_i1]).serializeAs_NuggetsBeneficiary(output);
  }
}

void NuggetsDistributionMessage::deserialize(Reader *input)
{
  this->deserializeAs_NuggetsDistributionMessage(input);
}

void NuggetsDistributionMessage::deserializeAs_NuggetsDistributionMessage(Reader *input)
{
  NuggetsBeneficiary _item1 ;
  uint _beneficiariesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _beneficiariesLen; _i1++)
  {
    _item1 = NuggetsBeneficiary();
    _item1.deserialize(input);
    this->beneficiaries.append(_item1);
  }
}

void NuggetsDistributionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NuggetsDistributionMessage(tree);
}

void NuggetsDistributionMessage::deserializeAsyncAs_NuggetsDistributionMessage(FuncTree tree)
{
  this->_beneficiariestree = tree.addChild(std::bind(&NuggetsDistributionMessage::_beneficiariestreeFunc, this, std::placeholders::_1));
}

void NuggetsDistributionMessage::_beneficiariestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_beneficiariestree.addChild(std::bind(&NuggetsDistributionMessage::_beneficiariesFunc, this, std::placeholders::_1));
  }
}

void NuggetsDistributionMessage::_beneficiariesFunc(Reader *input)
{
  NuggetsBeneficiary _item = NuggetsBeneficiary();
  _item.deserialize(input);
  this->beneficiaries.append(_item);
}

NuggetsDistributionMessage::NuggetsDistributionMessage()
{
  m_type = MessageEnum::NUGGETSDISTRIBUTIONMESSAGE;
}

