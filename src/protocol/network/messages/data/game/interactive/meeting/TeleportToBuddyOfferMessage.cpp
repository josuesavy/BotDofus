#include "TeleportToBuddyOfferMessage.h"

void TeleportToBuddyOfferMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportToBuddyOfferMessage(output);
}

void TeleportToBuddyOfferMessage::serializeAs_TeleportToBuddyOfferMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  if(this->buddyId < 0 || this->buddyId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
  }
  output->writeVarLong((double)this->buddyId);
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element timeLeft.";
  }
  output->writeVarInt((int)this->timeLeft);
}

void TeleportToBuddyOfferMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportToBuddyOfferMessage(input);
}

void TeleportToBuddyOfferMessage::deserializeAs_TeleportToBuddyOfferMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
  this->_buddyIdFunc(input);
  this->_timeLeftFunc(input);
}

void TeleportToBuddyOfferMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportToBuddyOfferMessage(tree);
}

void TeleportToBuddyOfferMessage::deserializeAsyncAs_TeleportToBuddyOfferMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportToBuddyOfferMessage::_dungeonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportToBuddyOfferMessage::_buddyIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportToBuddyOfferMessage::_timeLeftFunc, this, std::placeholders::_1));
}

void TeleportToBuddyOfferMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyOfferMessage.dungeonId.";
  }
}

void TeleportToBuddyOfferMessage::_buddyIdFunc(Reader *input)
{
  this->buddyId = input->readVarUhLong();
  if(this->buddyId < 0 || this->buddyId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyOfferMessage.buddyId.";
  }
}

void TeleportToBuddyOfferMessage::_timeLeftFunc(Reader *input)
{
  this->timeLeft = input->readVarUhInt();
  if(this->timeLeft < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyOfferMessage -"<<"Forbidden value (" << this->timeLeft << ") on element of TeleportToBuddyOfferMessage.timeLeft.";
  }
}

TeleportToBuddyOfferMessage::TeleportToBuddyOfferMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYOFFERMESSAGE;
}

