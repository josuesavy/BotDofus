#include "TeleportToBuddyCloseMessage.h"

void TeleportToBuddyCloseMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportToBuddyCloseMessage(output);
}

void TeleportToBuddyCloseMessage::serializeAs_TeleportToBuddyCloseMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->buddyId << ") on element buddyId.";
  }
  output->writeVarLong((double)this->buddyId);
}

void TeleportToBuddyCloseMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportToBuddyCloseMessage(input);
}

void TeleportToBuddyCloseMessage::deserializeAs_TeleportToBuddyCloseMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
  this->_buddyIdFunc(input);
}

void TeleportToBuddyCloseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportToBuddyCloseMessage(tree);
}

void TeleportToBuddyCloseMessage::deserializeAsyncAs_TeleportToBuddyCloseMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportToBuddyCloseMessage::_dungeonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportToBuddyCloseMessage::_buddyIdFunc, this, std::placeholders::_1));
}

void TeleportToBuddyCloseMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportToBuddyCloseMessage.dungeonId.";
  }
}

void TeleportToBuddyCloseMessage::_buddyIdFunc(Reader *input)
{
  this->buddyId = input->readVarUhLong();
  if(this->buddyId < 0 || this->buddyId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TeleportToBuddyCloseMessage -"<<"Forbidden value (" << this->buddyId << ") on element of TeleportToBuddyCloseMessage.buddyId.";
  }
}

TeleportToBuddyCloseMessage::TeleportToBuddyCloseMessage()
{
  m_type = MessageEnum::TELEPORTTOBUDDYCLOSEMESSAGE;
}

