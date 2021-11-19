#include "WrapperObjectAssociatedMessage.h"

void WrapperObjectAssociatedMessage::serialize(Writer *output)
{
  this->serializeAs_WrapperObjectAssociatedMessage(output);
}

void WrapperObjectAssociatedMessage::serializeAs_WrapperObjectAssociatedMessage(Writer *output)
{
  SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(output);
}

void WrapperObjectAssociatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_WrapperObjectAssociatedMessage(input);
}

void WrapperObjectAssociatedMessage::deserializeAs_WrapperObjectAssociatedMessage(Reader *input)
{
  SymbioticObjectAssociatedMessage::deserialize(input);
}

void WrapperObjectAssociatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WrapperObjectAssociatedMessage(tree);
}

void WrapperObjectAssociatedMessage::deserializeAsyncAs_WrapperObjectAssociatedMessage(FuncTree tree)
{
  SymbioticObjectAssociatedMessage::deserializeAsync(tree);
}

WrapperObjectAssociatedMessage::WrapperObjectAssociatedMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTASSOCIATEDMESSAGE;
}

