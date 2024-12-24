#include "MimicryObjectEraseRequestMessage.h"

void MimicryObjectEraseRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MimicryObjectEraseRequestMessage(output);
}

void MimicryObjectEraseRequestMessage::serializeAs_MimicryObjectEraseRequestMessage(Writer *output)
{
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element hostUID.";
  }
  output->writeVarInt((int)this->hostUID);
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element hostPos.";
  }
  output->writeByte(this->hostPos);
}

void MimicryObjectEraseRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MimicryObjectEraseRequestMessage(input);
}

void MimicryObjectEraseRequestMessage::deserializeAs_MimicryObjectEraseRequestMessage(Reader *input)
{
  this->_hostUIDFunc(input);
  this->_hostPosFunc(input);
}

void MimicryObjectEraseRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MimicryObjectEraseRequestMessage(tree);
}

void MimicryObjectEraseRequestMessage::deserializeAsyncAs_MimicryObjectEraseRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MimicryObjectEraseRequestMessage::_hostUIDFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MimicryObjectEraseRequestMessage::_hostPosFunc, this, std::placeholders::_1));
}

void MimicryObjectEraseRequestMessage::_hostUIDFunc(Reader *input)
{
  this->hostUID = input->readVarUhInt();
  if(this->hostUID < 0)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostUID << ") on element of MimicryObjectEraseRequestMessage.hostUID.";
  }
}

void MimicryObjectEraseRequestMessage::_hostPosFunc(Reader *input)
{
  this->hostPos = input->readUByte();
  if(this->hostPos < 0 || this->hostPos > 255)
  {
    qDebug()<<"ERREUR - MimicryObjectEraseRequestMessage -"<<"Forbidden value (" << this->hostPos << ") on element of MimicryObjectEraseRequestMessage.hostPos.";
  }
}

MimicryObjectEraseRequestMessage::MimicryObjectEraseRequestMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTERASEREQUESTMESSAGE;
}

