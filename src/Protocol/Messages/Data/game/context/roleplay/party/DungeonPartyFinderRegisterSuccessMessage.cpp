#include "DungeonPartyFinderRegisterSuccessMessage.h"

void DungeonPartyFinderRegisterSuccessMessage::serialize(Writer *output)
{
  this->serializeAs_DungeonPartyFinderRegisterSuccessMessage(output);
}

void DungeonPartyFinderRegisterSuccessMessage::serializeAs_DungeonPartyFinderRegisterSuccessMessage(Writer *output)
{
  output->writeShort((short)this->dungeonIds.size());
  for(uint _i1 = 0; _i1 < this->dungeonIds.size(); _i1++)
  {
    if(this->dungeonIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterSuccessMessage -"<<"Forbidden value (" << this->dungeonIds[_i1] << ") on element 1 (starting at 1) of dungeonIds.";
    }
    output->writeVarShort((int)this->dungeonIds[_i1]);
  }
}

void DungeonPartyFinderRegisterSuccessMessage::deserialize(Reader *input)
{
  this->deserializeAs_DungeonPartyFinderRegisterSuccessMessage(input);
}

void DungeonPartyFinderRegisterSuccessMessage::deserializeAs_DungeonPartyFinderRegisterSuccessMessage(Reader *input)
{
  uint _val1 = 0;
  uint _dungeonIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _dungeonIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - DungeonPartyFinderRegisterSuccessMessage -"<<"Forbidden value (" << _val1 << ") on elements of dungeonIds.";
    }
    this->dungeonIds.append(_val1);
  }
}

void DungeonPartyFinderRegisterSuccessMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_DungeonPartyFinderRegisterSuccessMessage(tree);
}

void DungeonPartyFinderRegisterSuccessMessage::deserializeAsyncAs_DungeonPartyFinderRegisterSuccessMessage(FuncTree tree)
{
  this->_dungeonIdstree = tree.addChild(std::bind(&DungeonPartyFinderRegisterSuccessMessage::_dungeonIdstreeFunc, this, std::placeholders::_1));
}

void DungeonPartyFinderRegisterSuccessMessage::_dungeonIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dungeonIdstree.addChild(std::bind(&DungeonPartyFinderRegisterSuccessMessage::_dungeonIdsFunc, this, std::placeholders::_1));
  }
}

void DungeonPartyFinderRegisterSuccessMessage::_dungeonIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - DungeonPartyFinderRegisterSuccessMessage -"<<"Forbidden value (" << _val << ") on elements of dungeonIds.";
  }
  this->dungeonIds.append(_val);
}

DungeonPartyFinderRegisterSuccessMessage::DungeonPartyFinderRegisterSuccessMessage()
{
  m_type = MessageEnum::DUNGEONPARTYFINDERREGISTERSUCCESSMESSAGE;
}

