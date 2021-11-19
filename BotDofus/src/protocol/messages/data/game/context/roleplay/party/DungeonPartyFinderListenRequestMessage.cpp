#include "DungeonPartyFinderListenRequestMessage.h"

void DungeonPartyFinderListenRequestMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderListenRequestMessage(output);
}

void DungeonPartyFinderListenRequestMessage::serializeAs_DungeonPartyFinderListenRequestMessage(Writer *output)
{
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element dungeonId.";
  }
  output->writeVarShort((int)this->dungeonId);
}

void DungeonPartyFinderListenRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderListenRequestMessage(input);
}

void DungeonPartyFinderListenRequestMessage::deserializeAs_DungeonPartyFinderListenRequestMessage(Reader *input)
{
  this->_dungeonIdFunc(input);
}

void DungeonPartyFinderListenRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderListenRequestMessage(tree);
}

void DungeonPartyFinderListenRequestMessage::deserializeAsyncAs_DungeonPartyFinderListenRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&DungeonPartyFinderListenRequestMessage::_dungeonIdFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderListenRequestMessage::_dungeonIdFunc(Reader *input)
{
  this->dungeonId = input->readVarUhShort();
  if(this->dungeonId < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderListenRequestMessage -"<<"Forbidden value (" << this->dungeonId << ") on element of DungeonPartyFinderListenRequestMessage.dungeonId.";
  }
}

DungeonPartyFinderListenRequestMessage::DungeonPartyFinderListenRequestMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERLISTENREQUESTMESSAGE;
}

