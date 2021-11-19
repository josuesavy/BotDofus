#include "WrapperObjectDissociateRequestMessage.h"

void WrapperObjectDissociateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_WrapperObjectDissociateRequestMessage(output);
}

void WrapperObjectDissociateRequestMessage::serializeAs_WrapperObjectDissociateRequestMessage(Writer *output)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  output->writeVarInt((int)this->hostUID);
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
  }
  output->writeByte(this->hostPos);
}

void WrapperObjectDissociateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_WrapperObjectDissociateRequestMessage(input);
}

void WrapperObjectDissociateRequestMessage::deserializeAs_WrapperObjectDissociateRequestMessage(Reader *input)
{
  this->_hostUIDFunc(input);
  this->_hostPosFunc(input);
}

void WrapperObjectDissociateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WrapperObjectDissociateRequestMessage(tree);
}

void WrapperObjectDissociateRequestMessage::deserializeAsyncAs_WrapperObjectDissociateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&WrapperObjectDissociateRequestMessage::_hostUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&WrapperObjectDissociateRequestMessage::_hostPosFunc, this, std::placeholders::_1));
}

void WrapperObjectDissociateRequestMessage::_hostUIDFunc(Reader *input)
{
  this->hostUID = input->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of WrapperObjectDissociateRequestMessage.hostUID.";
  }
}

void WrapperObjectDissociateRequestMessage::_hostPosFunc(Reader *input)
{
  this->hostPos = input->readUByte();
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - WrapperObjectDissociateRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of WrapperObjectDissociateRequestMessage.hostPos.";
  }
}

WrapperObjectDissociateRequestMessage::WrapperObjectDissociateRequestMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTDISSOCIATEREQUESTMESSAGE;
}

