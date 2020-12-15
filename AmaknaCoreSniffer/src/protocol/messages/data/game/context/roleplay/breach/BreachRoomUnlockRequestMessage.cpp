#include "BreachRoomUnlockRequestMessage.h"

void BreachRoomUnlockRequestMessage::serialize(Writer *output)
{
  this->serializeAs_BreachRoomUnlockRequestMessage(output);
}

void BreachRoomUnlockRequestMessage::serializeAs_BreachRoomUnlockRequestMessage(Writer *output)
{
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - BreachRoomUnlockRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  output->writeByte(this->roomId);
}

void BreachRoomUnlockRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachRoomUnlockRequestMessage(input);
}

void BreachRoomUnlockRequestMessage::deserializeAs_BreachRoomUnlockRequestMessage(Reader *input)
{
  this->_roomIdFunc(input);
}

void BreachRoomUnlockRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachRoomUnlockRequestMessage(tree);
}

void BreachRoomUnlockRequestMessage::deserializeAsyncAs_BreachRoomUnlockRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachRoomUnlockRequestMessage::_roomIdFunc, this, std::placeholders::_1));
}

void BreachRoomUnlockRequestMessage::_roomIdFunc(Reader *input)
{
  this->roomId = input->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - BreachRoomUnlockRequestMessage -"<<"Forbidden value (" << this->roomId << ") on element of BreachRoomUnlockRequestMessage.roomId.";
  }
}

BreachRoomUnlockRequestMessage::BreachRoomUnlockRequestMessage()
{
  m_type = MessageEnum::BREACHROOMUNLOCKREQUESTMESSAGE;
}

