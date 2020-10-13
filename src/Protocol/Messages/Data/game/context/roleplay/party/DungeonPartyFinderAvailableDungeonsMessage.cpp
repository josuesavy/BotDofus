#include "DungeonPartyFinderAvailableDungeonsMessage.h"

void DungeonPartyFinderAvailableDungeonsMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderAvailableDungeonsMessage(output);
}

void DungeonPartyFinderAvailableDungeonsMessage::serializeAs_DungeonPartyFinderAvailableDungeonsMessage(Writer *output)
{
  output->writeShort((short)this->dungeonIds.size());
  for(uint _i1 = 0; _i1 < this->dungeonIds.size(); _i1++)
  {
    if(this->dungeonIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderAvailableDungeonsMessage -"<<"Forbidden value (" << this->dungeonIds[_i1] << ") on element 1 (starting at 1) of dungeonIds.";
    }
    output->writeVarShort((int)this->dungeonIds[_i1]);
  }
}

void DungeonPartyFinderAvailableDungeonsMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(input);
}

void DungeonPartyFinderAvailableDungeonsMessage::deserializeAs_DungeonPartyFinderAvailableDungeonsMessage(Reader *input)
{
  uint _val1 = 0;
  uint _dungeonIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _dungeonIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderAvailableDungeonsMessage -"<<"Forbidden value (" << _val1 << ") on elements of dungeonIds.";
    }
    this->dungeonIds.append(_val1);
  }
}

void DungeonPartyFinderAvailableDungeonsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderAvailableDungeonsMessage(tree);
}

void DungeonPartyFinderAvailableDungeonsMessage::deserializeAsyncAs_DungeonPartyFinderAvailableDungeonsMessage(FuncTree tree)
{
  this->_dungeonIdstree = tree.addChild(std::bind(&DungeonPartyFinderAvailableDungeonsMessage::_dungeonIdstreeFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderAvailableDungeonsMessage::_dungeonIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dungeonIdstree.addChild(std::bind(&DungeonPartyFinderAvailableDungeonsMessage::_dungeonIdsFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderAvailableDungeonsMessage::_dungeonIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderAvailableDungeonsMessage -"<<"Forbidden value (" << _val << ") on elements of dungeonIds.";
  }
  this->dungeonIds.append(_val);
}

DungeonPartyFinderAvailableDungeonsMessage::DungeonPartyFinderAvailableDungeonsMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERAVAILABLEDUNGEONSMESSAGE;
}

