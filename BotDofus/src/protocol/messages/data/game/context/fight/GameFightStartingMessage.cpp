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
  output->writeShort((short)this->monsters.size());
  for(uint _i6 = 0; _i6 < this->monsters.size(); _i6++)
  {
    output->writeInt((int)this->monsters[_i6]);
  }
}

void GameFightStartingMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightStartingMessage(input);
}

void GameFightStartingMessage::deserializeAs_GameFightStartingMessage(Reader *input)
{
  auto _val6 = 0;
  this->_fightTypeFunc(input);
  this->_fightIdFunc(input);
  this->_attackerIdFunc(input);
  this->_defenderIdFunc(input);
  this->_containsBossFunc(input);
  uint _monstersLen = input->readUShort();
  for(uint _i6 = 0; _i6 < _monstersLen; _i6++)
  {
    _val6 = input->readInt();
    this->monsters.append(_val6);
  }
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
  this->_monsterstree = tree.addChild(std::bind(&GameFightStartingMessage::_monsterstreeFunc, this, std::placeholders::_1));
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

void GameFightStartingMessage::_monsterstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_monsterstree.addChild(std::bind(&GameFightStartingMessage::_monstersFunc, this, std::placeholders::_1));
  }
}

void GameFightStartingMessage::_monstersFunc(Reader *input)
{
  int _val = input->readInt();
  this->monsters.append(_val);
}

GameFightStartingMessage::GameFightStartingMessage()
{
  m_type = MessageEnum::GAMEFIGHTSTARTINGMESSAGE;
}

