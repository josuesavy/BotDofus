#include "MimicryObjectAssociatedMessage.h"

void MimicryObjectAssociatedMessage::serialize(Writer *output)
{
  this->serializeAs_MimicryObjectAssociatedMessage(output);
}

void MimicryObjectAssociatedMessage::serializeAs_MimicryObjectAssociatedMessage(Writer *output)
{
  SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(output);
}

void MimicryObjectAssociatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_MimicryObjectAssociatedMessage(input);
}

void MimicryObjectAssociatedMessage::deserializeAs_MimicryObjectAssociatedMessage(Reader *input)
{
  SymbioticObjectAssociatedMessage::deserialize(input);
}

void MimicryObjectAssociatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MimicryObjectAssociatedMessage(tree);
}

void MimicryObjectAssociatedMessage::deserializeAsyncAs_MimicryObjectAssociatedMessage(FuncTree tree)
{
  SymbioticObjectAssociatedMessage::deserializeAsync(tree);
}

MimicryObjectAssociatedMessage::MimicryObjectAssociatedMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTASSOCIATEDMESSAGE;
}

