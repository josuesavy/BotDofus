#include "AllianceFightFighterRemovedMessage.h"

void AllianceFightFighterRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightFighterRemovedMessage(output);
}

void AllianceFightFighterRemovedMessage::serializeAs_AllianceFightFighterRemovedMessage(Writer *output)
{
  this->allianceFightInfo.serializeAs_SocialFightInfo(output);
  if(this->fighterId < 0 || this->fighterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceFightFighterRemovedMessage -"<<"Forbidden value (" << this->fighterId << ") on element fighterId.";
  }
  output->writeVarLong((double)this->fighterId);
}

void AllianceFightFighterRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightFighterRemovedMessage(input);
}

void AllianceFightFighterRemovedMessage::deserializeAs_AllianceFightFighterRemovedMessage(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserialize(input);
  this->_fighterIdFunc(input);
}

void AllianceFightFighterRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightFighterRemovedMessage(tree);
}

void AllianceFightFighterRemovedMessage::deserializeAsyncAs_AllianceFightFighterRemovedMessage(FuncTree tree)
{
  this->_allianceFightInfotree = tree.addChild(std::bind(&AllianceFightFighterRemovedMessage::_allianceFightInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFightFighterRemovedMessage::_fighterIdFunc, this, std::placeholders::_1));
}

void AllianceFightFighterRemovedMessage::_allianceFightInfotreeFunc(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserializeAsync(this->_allianceFightInfotree);
}

void AllianceFightFighterRemovedMessage::_fighterIdFunc(Reader *input)
{
  this->fighterId = input->readVarUhLong();
  if(this->fighterId < 0 || this->fighterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - AllianceFightFighterRemovedMessage -"<<"Forbidden value (" << this->fighterId << ") on element of AllianceFightFighterRemovedMessage.fighterId.";
  }
}

AllianceFightFighterRemovedMessage::AllianceFightFighterRemovedMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTFIGHTERREMOVEDMESSAGE;
}

