#include "SymbioticObjectAssociatedMessage.h"

void SymbioticObjectAssociatedMessage::serialize(Writer *output)
{
  this->serializeAs_SymbioticObjectAssociatedMessage(output);
}

void SymbioticObjectAssociatedMessage::serializeAs_SymbioticObjectAssociatedMessage(Writer *output)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociatedMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  output->writeVarInt((int)this->hostUID);
}

void SymbioticObjectAssociatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_SymbioticObjectAssociatedMessage(input);
}

void SymbioticObjectAssociatedMessage::deserializeAs_SymbioticObjectAssociatedMessage(Reader *input)
{
  this->_hostUIDFunc(input);
}

void SymbioticObjectAssociatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SymbioticObjectAssociatedMessage(tree);
}

void SymbioticObjectAssociatedMessage::deserializeAsyncAs_SymbioticObjectAssociatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SymbioticObjectAssociatedMessage::_hostUIDFunc, this, std::placeholders::_1));
}

void SymbioticObjectAssociatedMessage::_hostUIDFunc(Reader *input)
{
  this->hostUID = input->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociatedMessage -"<<"Forbidden value (" << this->hostUID << ") on element of SymbioticObjectAssociatedMessage.hostUID.";
  }
}

SymbioticObjectAssociatedMessage::SymbioticObjectAssociatedMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTASSOCIATEDMESSAGE;
}

