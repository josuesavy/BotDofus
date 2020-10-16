#include "GameFightEffectTriggerCount.h"

void GameFightEffectTriggerCount::serialize(Writer *output)
{
  this->serializeAs_GameFightEffectTriggerCount(output);
}

void GameFightEffectTriggerCount::serializeAs_GameFightEffectTriggerCount(Writer *output)
{
  if(this->effectId < 0)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->effectId << ") on element effectId.";
  }
  output->writeVarInt((int)this->effectId);
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->targetId << ") on element targetId.";
  }
  output->writeDouble(this->targetId);
  if(this->count < 0)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->count << ") on element count.";
  }
  output->writeByte(this->count);
}

void GameFightEffectTriggerCount::deserialize(Reader *input)
{
  this->deserializeAs_GameFightEffectTriggerCount(input);
}

void GameFightEffectTriggerCount::deserializeAs_GameFightEffectTriggerCount(Reader *input)
{
  this->_effectIdFunc(input);
  this->_targetIdFunc(input);
  this->_countFunc(input);
}

void GameFightEffectTriggerCount::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightEffectTriggerCount(tree);
}

void GameFightEffectTriggerCount::deserializeAsyncAs_GameFightEffectTriggerCount(FuncTree tree)
{
  tree.addChild(std::bind(&GameFightEffectTriggerCount::_effectIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEffectTriggerCount::_targetIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightEffectTriggerCount::_countFunc, this, std::placeholders::_1));
}

void GameFightEffectTriggerCount::_effectIdFunc(Reader *input)
{
  this->effectId = input->readVarUhInt();
  if(this->effectId < 0)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->effectId << ") on element of GameFightEffectTriggerCount.effectId.";
  }
}

void GameFightEffectTriggerCount::_targetIdFunc(Reader *input)
{
  this->targetId = input->readDouble();
  if(this->targetId < -9.007199254740992E15 || this->targetId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->targetId << ") on element of GameFightEffectTriggerCount.targetId.";
  }
}

void GameFightEffectTriggerCount::_countFunc(Reader *input)
{
  this->count = input->readByte();
  if(this->count < 0)
  {
    qDebug()<<"ERREUR - GameFightEffectTriggerCount -"<<"Forbidden value (" << this->count << ") on element of GameFightEffectTriggerCount.count.";
  }
}

GameFightEffectTriggerCount::GameFightEffectTriggerCount()
{
  m_types<<ClassEnum::GAMEFIGHTEFFECTTRIGGERCOUNT;
}

bool GameFightEffectTriggerCount::operator==(const GameFightEffectTriggerCount &compared)
{
  if(effectId == compared.effectId)
  if(targetId == compared.targetId)
  if(count == compared.count)
  return true;
  
  return false;
}

