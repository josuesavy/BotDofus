#include "DungeonPartyFinderRegisterRequestMessage.h"

void DungeonPartyFinderRegisterRequestMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderRegisterRequestMessage(output);
}

void DungeonPartyFinderRegisterRequestMessage::serializeAs_DungeonPartyFinderRegisterRequestMessage(Writer *output)
{
  output->writeShort((short)this->dungeonIds.size());
  for(uint _i1 = 0; _i1 < this->dungeonIds.size(); _i1++)
  {
    if(this->dungeonIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterRequestMessage -"<<"Forbidden value (" << this->dungeonIds[_i1] << ") on element 1 (starting at 1) of dungeonIds.";
    }
    output->writeVarShort((int)this->dungeonIds[_i1]);
  }
}

void DungeonPartyFinderRegisterRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderRegisterRequestMessage(input);
}

void DungeonPartyFinderRegisterRequestMessage::deserializeAs_DungeonPartyFinderRegisterRequestMessage(Reader *input)
{
  uint _val1 = 0;
  uint _dungeonIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _dungeonIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterRequestMessage -"<<"Forbidden value (" << _val1 << ") on elements of dungeonIds.";
    }
    this->dungeonIds.append(_val1);
  }
}

void DungeonPartyFinderRegisterRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderRegisterRequestMessage(tree);
}

void DungeonPartyFinderRegisterRequestMessage::deserializeAsyncAs_DungeonPartyFinderRegisterRequestMessage(FuncTree tree)
{
  this->_dungeonIdstree = tree.addChild(std::bind(&DungeonPartyFinderRegisterRequestMessage::_dungeonIdstreeFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderRegisterRequestMessage::_dungeonIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dungeonIdstree.addChild(std::bind(&DungeonPartyFinderRegisterRequestMessage::_dungeonIdsFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderRegisterRequestMessage::_dungeonIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRegisterRequestMessage -"<<"Forbidden value (" << _val << ") on elements of dungeonIds.";
  }
  this->dungeonIds.append(_val);
}

DungeonPartyFinderRegisterRequestMessage::DungeonPartyFinderRegisterRequestMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERREGISTERREQUESTMESSAGE;
}

