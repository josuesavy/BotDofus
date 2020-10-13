#include "GameFightEndMessage.h"

void GameFightEndMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightEndMessage(output);
}

void GameFightEndMessage::serializeAs_GameFightEndMessage(Writer *output)
{
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameFightEndMessage -"<<"Forbidden value (" << this->duration << ") on element duration.";
  }
  output->writeInt((int)this->duration);
  output->writeVarShort((int)this->rewardRate);
  output->writeShort((short)this->lootShareLimitMalus);
  output->writeShort((short)this->results.size());
  for(uint _i4 = 0; _i4 < this->results.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<FightResultListEntry>(this->results[_i4])->getTypes().last());
    qSharedPointerCast<FightResultListEntry>(this->results[_i4])->serialize(output);
  }
  output->writeShort((short)this->namedPartyTeamsOutcomes.size());
  for(uint _i5 = 0; _i5 < this->namedPartyTeamsOutcomes.size(); _i5++)
  {
    (this->namedPartyTeamsOutcomes[_i5]).serializeAs_NamedPartyTeamWithOutcome(output);
  }
}

void GameFightEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightEndMessage(input);
}

void GameFightEndMessage::deserializeAs_GameFightEndMessage(Reader *input)
{
  uint _id4 = 0;
  QSharedPointer<FightResultListEntry> _item4 ;
  NamedPartyTeamWithOutcome _item5 ;
  this->_durationFunc(input);
  this->_rewardRateFunc(input);
  this->_lootShareLimitMalusFunc(input);
  uint _resultsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _resultsLen; _i4++)
  {
    _id4 = input->readUShort();
    _item4 = qSharedPointerCast<FightResultListEntry>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->results.append(_item4);
  }
  uint _namedPartyTeamsOutcomesLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _namedPartyTeamsOutcomesLen; _i5++)
  {
    _item5 = NamedPartyTeamWithOutcome();
    _item5.deserialize(input);
    this->namedPartyTeamsOutcomes.append(_item5);
  }
}

void GameFightEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightEndMessage(tree);
}

void GameFightEndMessage::deserializeAsyncAs_GameFightEndMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightEndMessage::_durationFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEndMessage::_rewardRateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEndMessage::_lootShareLimitMalusFunc, this, std::placeholders::_1));
  this->_resultstree = tree.addChild(std::bind(&GameFightEndMessage::_resultstreeFunc, this, std::placeholders::_1));
  this->_namedPartyTeamsOutcomestree = tree.addChild(std::bind(&GameFightEndMessage::_namedPartyTeamsOutcomestreeFunc, this, std::placeholders::_1));
}

void GameFightEndMessage::_durationFunc(Reader *input)
{
  this->duration = input->readInt();
  if(this->duration < 0)
  {
    qDebug()<<"ERREUR - GameFightEndMessage -"<<"Forbidden value (" << this->duration << ") on element of GameFightEndMessage.duration.";
  }
}

void GameFightEndMessage::_rewardRateFunc(Reader *input)
{
  this->rewardRate = input->readVarShort();
}

void GameFightEndMessage::_lootShareLimitMalusFunc(Reader *input)
{
  this->lootShareLimitMalus = input->readShort();
}

void GameFightEndMessage::_resultstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_resultstree.addChild(std::bind(&GameFightEndMessage::_resultsFunc, this, std::placeholders::_1));
  }
}

void GameFightEndMessage::_resultsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<FightResultListEntry> _item = qSharedPointerCast<FightResultListEntry>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->results.append(_item);
}

void GameFightEndMessage::_namedPartyTeamsOutcomestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_namedPartyTeamsOutcomestree.addChild(std::bind(&GameFightEndMessage::_namedPartyTeamsOutcomesFunc, this, std::placeholders::_1));
  }
}

void GameFightEndMessage::_namedPartyTeamsOutcomesFunc(Reader *input)
{
  NamedPartyTeamWithOutcome _item = NamedPartyTeamWithOutcome();
  _item.deserialize(input);
  this->namedPartyTeamsOutcomes.append(_item);
}

GameFightEndMessage::GameFightEndMessage()
{
  m_type = MessageEnum::GAMEFIGHTENDMESSAGE;
}

