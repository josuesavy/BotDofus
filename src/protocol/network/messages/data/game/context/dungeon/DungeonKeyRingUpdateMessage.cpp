#include "DungeonKeyRingUpdateMessage.h"

void DungeonKeyRingUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonKeyRingUpdateMessage(output);
}

void DungeonKeyRingUpdateMessage::serializeAs_DungeonKeyRingUpdateMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
  output->writeBool(this->available);
}

void DungeonKeyRingUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonKeyRingUpdateMessage(input);
}

void DungeonKeyRingUpdateMessage::deserializeAs_DungeonKeyRingUpdateMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
  this->_availableFunc(input);
}

void DungeonKeyRingUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonKeyRingUpdateMessage(tree);
}

void DungeonKeyRingUpdateMessage::deserializeAsyncAs_DungeonKeyRingUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonKeyRingUpdateMessage::_dungeonIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&DungeonKeyRingUpdateMessage::_availableFunc, this, std::placeholders::_1));
}

void DungeonKeyRingUpdateMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonKeyRingUpdateMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonKeyRingUpdateMessage.dungeonId.";
  }
}

void DungeonKeyRingUpdateMessage::_availableFunc(Reader *input)
{
  this->available = input->readBool();
}

DungeonKeyRingUpdateMessage::DungeonKeyRingUpdateMessage()
{
  m_type = MessageEnum::DUNGEONKEYRINGUPDATEMESSAGE;
}

