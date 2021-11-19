#include "ChangeHavenBagRoomRequestMessage.h"

void ChangeHavenBagRoomRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ChangeHavenBagRoomRequestMessage(output);
}

void ChangeHavenBagRoomRequestMessage::serializeAs_ChangeHavenBagRoomRequestMessage(Writer *output)
{
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - ChangeHavenBagRoomRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  output->writeByte(this->roomId);
}

void ChangeHavenBagRoomRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ChangeHavenBagRoomRequestMessage(input);
}

void ChangeHavenBagRoomRequestMessage::deserializeAs_ChangeHavenBagRoomRequestMessage(Reader *input)
{
  this->_roomIdFunc(input);
}

void ChangeHavenBagRoomRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ChangeHavenBagRoomRequestMessage(tree);
}

void ChangeHavenBagRoomRequestMessage::deserializeAsyncAs_ChangeHavenBagRoomRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ChangeHavenBagRoomRequestMessage::_roomIdFunc, this, std::placeholders::_1));
}

void ChangeHavenBagRoomRequestMessage::_roomIdFunc(Reader *input)
{
  this->roomId = input->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - ChangeHavenBagRoomRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element of ChangeHavenBagRoomRequestMessage.roomId.";
  }
}

ChangeHavenBagRoomRequestMessage::ChangeHavenBagRoomRequestMessage()
{
  m_type = MessageEnum::CHANGEHAVENBAGROOMREQUESTMESSAGE;
}

