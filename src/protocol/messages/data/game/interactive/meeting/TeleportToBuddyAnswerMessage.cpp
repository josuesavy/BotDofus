#include "TeleportToBuddyAnswerMessage.h"

void TeleportToBuddyAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportToBuddyAnswerMessage(output);
}

void TeleportToBuddyAnswerMessage::serializeAs_TeleportToBuddyAnswerMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
  }
  output->writeVarLong((double)this->buddyId);
  output->writeBool(this->accept);
}

void TeleportToBuddyAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportToBuddyAnswerMessage(input);
}

void TeleportToBuddyAnswerMessage::deserializeAs_TeleportToBuddyAnswerMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
  this->_buddyIdFunc(input);
  this->_acceptFunc(input);
}

void TeleportToBuddyAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportToBuddyAnswerMessage(tree);
}

void TeleportToBuddyAnswerMessage::deserializeAsyncAs_TeleportToBuddyAnswerMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportToBuddyAnswerMessage::_dungeonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportToBuddyAnswerMessage::_buddyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportToBuddyAnswerMessage::_acceptFunc, this, std::placeholders::_1));
}

void TeleportToBuddyAnswerMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyAnswerMessage.dungeonId.";
  }
}

void TeleportToBuddyAnswerMessage::_buddyIdFunc(Reader *input)
{
  this->buddyId = input->readVarUhLong();
  if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportToBuddyAnswerMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyAnswerMessage.buddyId.";
  }
}

void TeleportToBuddyAnswerMessage::_acceptFunc(Reader *input)
{
  this->accept = input->readBool();
}

TeleportToBuddyAnswerMessage::TeleportToBuddyAnswerMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYANSWERMESSAGE;
}

