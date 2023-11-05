#include "DungeonPartyFinderListenErrorMessage.h"

void DungeonPartyFinderListenErrorMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderListenErrorMessage(output);
}

void DungeonPartyFinderListenErrorMessage::serializeAs_DungeonPartyFinderListenErrorMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenErrorMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
}

void DungeonPartyFinderListenErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderListenErrorMessage(input);
}

void DungeonPartyFinderListenErrorMessage::deserializeAs_DungeonPartyFinderListenErrorMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
}

void DungeonPartyFinderListenErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderListenErrorMessage(tree);
}

void DungeonPartyFinderListenErrorMessage::deserializeAsyncAs_DungeonPartyFinderListenErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonPartyFinderListenErrorMessage::_dungeonIdFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderListenErrorMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenErrorMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderListenErrorMessage.dungeonId.";
  }
}

DungeonPartyFinderListenErrorMessage::DungeonPartyFinderListenErrorMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERLISTENERRORMESSAGE;
}

