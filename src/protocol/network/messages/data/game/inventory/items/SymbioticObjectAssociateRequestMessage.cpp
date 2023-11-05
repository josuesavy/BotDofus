#include "SymbioticObjectAssociateRequestMessage.h"

void SymbioticObjectAssociateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_SymbioticObjectAssociateRequestMessage(output);
}

void SymbioticObjectAssociateRequestMessage::serializeAs_SymbioticObjectAssociateRequestMessage(Writer *output)
{
  if(this->symbioteUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbioteUID << ") on element symbioteUID.";
  }
  output->writeVarInt((int)this->symbioteUID);
  if(this->symbiotePos < 0 || this->symbiotePos > 255)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbiotePos << ") on element symbiotePos.";
  }
  output->writeByte(this->symbiotePos);
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  output->writeVarInt((int)this->hostUID);
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
  }
  output->writeByte(this->hostPos);
}

void SymbioticObjectAssociateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_SymbioticObjectAssociateRequestMessage(input);
}

void SymbioticObjectAssociateRequestMessage::deserializeAs_SymbioticObjectAssociateRequestMessage(Reader *input)
{
  this->_symbioteUIDFunc(input);
  this->_symbiotePosFunc(input);
  this->_hostUIDFunc(input);
  this->_hostPosFunc(input);
}

void SymbioticObjectAssociateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SymbioticObjectAssociateRequestMessage(tree);
}

void SymbioticObjectAssociateRequestMessage::deserializeAsyncAs_SymbioticObjectAssociateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SymbioticObjectAssociateRequestMessage::_symbioteUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SymbioticObjectAssociateRequestMessage::_symbiotePosFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SymbioticObjectAssociateRequestMessage::_hostUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&SymbioticObjectAssociateRequestMessage::_hostPosFunc, this, std::placeholders::_1));
}

void SymbioticObjectAssociateRequestMessage::_symbioteUIDFunc(Reader *input)
{
  this->symbioteUID = input->readVarUhInt();
  if(this->symbioteUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbioteUID << ") on element of SymbioticObjectAssociateRequestMessage.symbioteUID.";
  }
}

void SymbioticObjectAssociateRequestMessage::_symbiotePosFunc(Reader *input)
{
  this->symbiotePos = input->readUByte();
  if(this->symbiotePos < 0 || this->symbiotePos > 255)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->symbiotePos << ") on element of SymbioticObjectAssociateRequestMessage.symbiotePos.";
  }
}

void SymbioticObjectAssociateRequestMessage::_hostUIDFunc(Reader *input)
{
  this->hostUID = input->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of SymbioticObjectAssociateRequestMessage.hostUID.";
  }
}

void SymbioticObjectAssociateRequestMessage::_hostPosFunc(Reader *input)
{
  this->hostPos = input->readUByte();
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - SymbioticObjectAssociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of SymbioticObjectAssociateRequestMessage.hostPos.";
  }
}

SymbioticObjectAssociateRequestMessage::SymbioticObjectAssociateRequestMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTASSOCIATEREQUESTMESSAGE;
}

