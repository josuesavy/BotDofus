#include "BreachRoomUnlockResultMessage.h"

void BreachRoomUnlockResultMessage::serialize(Writer *output)
{
  this->serializeAs_BreachRoomUnlockResultMessage(output);
}

void BreachRoomUnlockResultMessage::serializeAs_BreachRoomUnlockResultMessage(Writer *output)
{
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - BreachRoomUnlockResultMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  output->writeByte(this->roomId);
  output->writeByte(this->result);
}

void BreachRoomUnlockResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachRoomUnlockResultMessage(input);
}

void BreachRoomUnlockResultMessage::deserializeAs_BreachRoomUnlockResultMessage(Reader *input)
{
  this->_roomIdFunc(input);
  this->_resultFunc(input);
}

void BreachRoomUnlockResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachRoomUnlockResultMessage(tree);
}

void BreachRoomUnlockResultMessage::deserializeAsyncAs_BreachRoomUnlockResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&BreachRoomUnlockResultMessage::_roomIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&BreachRoomUnlockResultMessage::_resultFunc, this, std::placeholders::_1));
}

void BreachRoomUnlockResultMessage::_roomIdFunc(Reader *input)
{
  this->roomId = input->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - BreachRoomUnlockResultMessage -"<<"Forbidden value (" << this->roomId << ") on element of BreachRoomUnlockResultMessage.roomId.";
  }
}

void BreachRoomUnlockResultMessage::_resultFunc(Reader *input)
{
  this->result = input->readByte();
  if(this->result < 0)
  {
    qDebug()<<"ERREUR - BreachRoomUnlockResultMessage -"<<"Forbidden value (" << this->result << ") on element of BreachRoomUnlockResultMessage.result.";
  }
}

BreachRoomUnlockResultMessage::BreachRoomUnlockResultMessage()
{
  m_type = MessageEnum::BREACHROOMUNLOCKRESULTMESSAGE;
}

