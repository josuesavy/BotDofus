#include "GameFightJoinMessage.h"

void GameFightJoinMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightJoinMessage(output);
}

void GameFightJoinMessage::serializeAs_GameFightJoinMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->isTeamPhase);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->canBeCancelled);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->canSayReady);
  _box0 = BooleanByteWrapper::setFlag(_box0, 3, this->isFightStarted);
  output->writeByte(_box0);
  if(this->timeMaxBeforeFightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->timeMaxBeforeFightStart << ") on element timeMaxBeforeFightStart.";
  }
  output->writeShort((short)this->timeMaxBeforeFightStart);
  output->writeByte(this->fightType);
}

void GameFightJoinMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightJoinMessage(input);
}

void GameFightJoinMessage::deserializeAs_GameFightJoinMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
  this->_timeMaxBeforeFightStartFunc(input);
  this->_fightTypeFunc(input);
}

void GameFightJoinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightJoinMessage(tree);
}

void GameFightJoinMessage::deserializeAsyncAs_GameFightJoinMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightJoinMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightJoinMessage::_timeMaxBeforeFightStartFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightJoinMessage::_fightTypeFunc, this, std::placeholders::_1));
}

void GameFightJoinMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->isTeamPhase = BooleanByteWrapper::getFlag(_box0, 0);
  this->canBeCancelled = BooleanByteWrapper::getFlag(_box0, 1);
  this->canSayReady = BooleanByteWrapper::getFlag(_box0, 2);
  this->isFightStarted = BooleanByteWrapper::getFlag(_box0, 3);
}

void GameFightJoinMessage::_timeMaxBeforeFightStartFunc(Reader *input)
{
  this->timeMaxBeforeFightStart = input->readShort();
  if(this->timeMaxBeforeFightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->timeMaxBeforeFightStart << ") on element of GameFightJoinMessage.timeMaxBeforeFightStart.";
  }
}

void GameFightJoinMessage::_fightTypeFunc(Reader *input)
{
  this->fightType = input->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - GameFightJoinMessage -"<<"Forbidden value (" << this->fightType << ") on element of GameFightJoinMessage.fightType.";
  }
}

GameFightJoinMessage::GameFightJoinMessage()
{
  m_type = MessageEnum::GAMEFIGHTJOINMESSAGE;
}

