#include "GameFightStartingMessage.h"

void GameFightStartingMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightStartingMessage(output);
}

void GameFightStartingMessage::serializeAs_GameFightStartingMessage(Writer *output)
{
  output->writeByte(this->fightType);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->attackerId < -9.007199254740992E15 || this->attackerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->attackerId << ") on element attackerId.";
  }
  output->writeDouble(this->attackerId);
  if(this->defenderId < -9.007199254740992E15 || this->defenderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->defenderId << ") on element defenderId.";
  }
  output->writeDouble(this->defenderId);
  output->writeBool(this->containsBoss);
}

void GameFightStartingMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightStartingMessage(input);
}

void GameFightStartingMessage::deserializeAs_GameFightStartingMessage(Reader *input)
{
  this->_fightTypeFunc(input);
  this->_fightIdFunc(input);
  this->_attackerIdFunc(input);
  this->_defenderIdFunc(input);
  this->_containsBossFunc(input);
}

void GameFightStartingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightStartingMessage(tree);
}

void GameFightStartingMessage::deserializeAsyncAs_GameFightStartingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightStartingMessage::_fightTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightStartingMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightStartingMessage::_attackerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightStartingMessage::_defenderIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightStartingMessage::_containsBossFunc, this, std::placeholders::_1));
}

void GameFightStartingMessage::_fightTypeFunc(Reader *input)
{
  this->fightType = input->readByte();
  if(this->fightType < 0)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->fightType << ") on element of GameFightStartingMessage.fightType.";
  }
}

void GameFightStartingMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->fightId << ") on element of GameFightStartingMessage.fightId.";
  }
}

void GameFightStartingMessage::_attackerIdFunc(Reader *input)
{
  this->attackerId = input->readDouble();
  if(this->attackerId < -9.007199254740992E15 || this->attackerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->attackerId << ") on element of GameFightStartingMessage.attackerId.";
  }
}

void GameFightStartingMessage::_defenderIdFunc(Reader *input)
{
  this->defenderId = input->readDouble();
  if(this->defenderId < -9.007199254740992E15 || this->defenderId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightStartingMessage -"<<"Forbidden value (" << this->defenderId << ") on element of GameFightStartingMessage.defenderId.";
  }
}

void GameFightStartingMessage::_containsBossFunc(Reader *input)
{
  this->containsBoss = input->readBool();
}

GameFightStartingMessage::GameFightStartingMessage()
{
  m_type = MessageEnum::GAMEFIGHTSTARTINGMESSAGE;
}

