#include "MountInformationRequestMessage.h"

void MountInformationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountInformationRequestMessage(output);
}

void MountInformationRequestMessage::serializeAs_MountInformationRequestMessage(Writer *output)
{
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  if(this->time < -9007199254740992 || this->time > 9007199254740992)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->time << ") on element time.";
  }
  output->writeDouble(this->time);
}

void MountInformationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountInformationRequestMessage(input);
}

void MountInformationRequestMessage::deserializeAs_MountInformationRequestMessage(Reader *input)
{
  this->_idFunc(input);
  this->_timeFunc(input);
}

void MountInformationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountInformationRequestMessage(tree);
}

void MountInformationRequestMessage::deserializeAsyncAs_MountInformationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountInformationRequestMessage::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MountInformationRequestMessage::_timeFunc, this, std::placeholders::_1));
}

void MountInformationRequestMessage::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->id << ") on element of MountInformationRequestMessage.id.";
  }
}

void MountInformationRequestMessage::_timeFunc(Reader *input)
{
  this->time = input->readDouble();
  if(this->time < -9007199254740992 || this->time > 9007199254740992)
  {
    qDebug()<<"ERREUR - MountInformationRequestMessage -"<<"Forbidden value (" << this->time << ") on element of MountInformationRequestMessage.time.";
  }
}

MountInformationRequestMessage::MountInformationRequestMessage()
{
  m_type = MessageEnum::MOUNTINFORMATIONREQUESTMESSAGE;
}

