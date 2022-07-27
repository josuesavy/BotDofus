#include "TeleportBuddiesMessage.h"

void TeleportBuddiesMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportBuddiesMessage(output);
}

void TeleportBuddiesMessage::serializeAs_TeleportBuddiesMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
}

void TeleportBuddiesMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportBuddiesMessage(input);
}

void TeleportBuddiesMessage::deserializeAs_TeleportBuddiesMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
}

void TeleportBuddiesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportBuddiesMessage(tree);
}

void TeleportBuddiesMessage::deserializeAsyncAs_TeleportBuddiesMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportBuddiesMessage::_dungeonIdFunc, this, std::placeholders::_1));
}

void TeleportBuddiesMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - TeleportBuddiesMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of TeleportBuddiesMessage.dungeonId.";
  }
}

TeleportBuddiesMessage::TeleportBuddiesMessage()
{
  m_type = MessageEnum::TELEPORTBUDDIESMESSAGE;
}

