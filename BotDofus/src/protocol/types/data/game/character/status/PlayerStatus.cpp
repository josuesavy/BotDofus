#include "PlayerStatus.h"

void PlayerStatus::serialize(Writer *output)
{
  this->serializeAs_PlayerStatus(output);
}

void PlayerStatus::serializeAs_PlayerStatus(Writer *output)
{
  output->writeByte(this->statusId);
}

void PlayerStatus::deserialize(Reader *input)
{
  this->deserializeAs_PlayerStatus(input);
}

void PlayerStatus::deserializeAs_PlayerStatus(Reader *input)
{
  this->_statusIdFunc(input);
}

void PlayerStatus::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerStatus(tree);
}

void PlayerStatus::deserializeAsyncAs_PlayerStatus(FuncTree tree)
{
  tree.addChild(std::bind(&PlayerStatus::_statusIdFunc, this, std::placeholders::_1));
}

void PlayerStatus::_statusIdFunc(Reader *input)
{
  this->statusId = input->readByte();
  if(this->statusId < 0)
  {
    qDebug()<<"ERREUR - PlayerStatus -"<<"Forbidden value (" << this->statusId << ") on element of PlayerStatus.statusId.";
  }
}

PlayerStatus::PlayerStatus()
{
  m_types<<ClassEnum::PLAYERSTATUS;
}

bool PlayerStatus::operator==(const PlayerStatus &compared)
{
  if(statusId == compared.statusId)
  return true;
  
  return false;
}

