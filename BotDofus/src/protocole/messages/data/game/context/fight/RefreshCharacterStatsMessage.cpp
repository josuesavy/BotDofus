#include "RefreshCharacterStatsMessage.h"

void RefreshCharacterStatsMessage::serialize(Writer *output)
{
  this->serializeAs_RefreshCharacterStatsMessage(output);
}

void RefreshCharacterStatsMessage::serializeAs_RefreshCharacterStatsMessage(Writer *output)
{
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - RefreshCharacterStatsMessage -"<<"Forbidden value (" << this->fighterId << ") on element fighterId.";
  }
  output->writeDouble(this->fighterId);
  this->stats->serializeAs_GameFightCharacteristics(output);
}

void RefreshCharacterStatsMessage::deserialize(Reader *input)
{
  this->deserializeAs_RefreshCharacterStatsMessage(input);
}

void RefreshCharacterStatsMessage::deserializeAs_RefreshCharacterStatsMessage(Reader *input)
{
  this->_fighterIdFunc(input);
  this->stats = QSharedPointer<GameFightCharacteristics>(new GameFightCharacteristics() );
  this->stats->deserialize(input);
}

void RefreshCharacterStatsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RefreshCharacterStatsMessage(tree);
}

void RefreshCharacterStatsMessage::deserializeAsyncAs_RefreshCharacterStatsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&RefreshCharacterStatsMessage::_fighterIdFunc, this, std::placeholders::_1));
  this->_statstree = tree.addChild(std::bind(&RefreshCharacterStatsMessage::_statstreeFunc, this, std::placeholders::_1));
}

void RefreshCharacterStatsMessage::_fighterIdFunc(Reader *input)
{
  this->fighterId = input->readDouble();
  if(this->fighterId < -9.007199254740992E15 || this->fighterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - RefreshCharacterStatsMessage -"<<"Forbidden value (" << this->fighterId << ") on element of RefreshCharacterStatsMessage.fighterId.";
  }
}

void RefreshCharacterStatsMessage::_statstreeFunc(Reader *input)
{
  this->stats = QSharedPointer<GameFightCharacteristics>(new GameFightCharacteristics() );
  this->stats->deserializeAsync(this->_statstree);
}

RefreshCharacterStatsMessage::RefreshCharacterStatsMessage()
{
  m_type = MessageEnum::REFRESHCHARACTERSTATSMESSAGE;
}

