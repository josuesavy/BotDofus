#include "PlayerStatusUpdateMessage.h"

void PlayerStatusUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PlayerStatusUpdateMessage(output);
}

void PlayerStatusUpdateMessage::serializeAs_PlayerStatusUpdateMessage(Writer *output)
{
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element accountId.";
  }
  output->writeInt((int)this->accountId);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
}

void PlayerStatusUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PlayerStatusUpdateMessage(input);
}

void PlayerStatusUpdateMessage::deserializeAs_PlayerStatusUpdateMessage(Reader *input)
{
  this->_accountIdFunc(input);
  this->_playerIdFunc(input);
  uint _id3 = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id3));
  this->status->deserialize(input);
}

void PlayerStatusUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerStatusUpdateMessage(tree);
}

void PlayerStatusUpdateMessage::deserializeAsyncAs_PlayerStatusUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PlayerStatusUpdateMessage::_accountIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PlayerStatusUpdateMessage::_playerIdFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&PlayerStatusUpdateMessage::_statustreeFunc, this, std::placeholders::_1));
}

void PlayerStatusUpdateMessage::_accountIdFunc(Reader *input)
{
  this->accountId = input->readInt();
  if(this->accountId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->accountId << ") on element of PlayerStatusUpdateMessage.accountId.";
  }
}

void PlayerStatusUpdateMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PlayerStatusUpdateMessage -"<<"Forbidden value (" << this->playerId << ") on element of PlayerStatusUpdateMessage.playerId.";
  }
}

void PlayerStatusUpdateMessage::_statustreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

PlayerStatusUpdateMessage::PlayerStatusUpdateMessage()
{
  m_type = MessageEnum::PLAYERSTATUSUPDATEMESSAGE;
}

