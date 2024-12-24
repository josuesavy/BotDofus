#include "NuggetsInformationMessage.h"

void NuggetsInformationMessage::serialize(Writer *output)
{
  this->serializeAs_NuggetsInformationMessage(output);
}

void NuggetsInformationMessage::serializeAs_NuggetsInformationMessage(Writer *output)
{
  output->writeInt((int)this->nuggetsQuantity);
}

void NuggetsInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_NuggetsInformationMessage(input);
}

void NuggetsInformationMessage::deserializeAs_NuggetsInformationMessage(Reader *input)
{
  this->_nuggetsQuantityFunc(input);
}

void NuggetsInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_NuggetsInformationMessage(tree);
}

void NuggetsInformationMessage::deserializeAsyncAs_NuggetsInformationMessage(FuncTree tree)
{
  tree.addChild(std::bind(&NuggetsInformationMessage::_nuggetsQuantityFunc, this, std::placeholders::_1));
}

void NuggetsInformationMessage::_nuggetsQuantityFunc(Reader *input)
{
  this->nuggetsQuantity = input->readInt();
}

NuggetsInformationMessage::NuggetsInformationMessage()
{
  m_type = MessageEnum::NUGGETSINFORMATIONMESSAGE;
}

