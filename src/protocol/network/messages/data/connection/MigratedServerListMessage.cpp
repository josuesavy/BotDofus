#include "MigratedServerListMessage.h"

void MigratedServerListMessage::serialize(Writer *output)
{
  this->serializeAs_MigratedServerListMessage(output);
}

void MigratedServerListMessage::serializeAs_MigratedServerListMessage(Writer *output)
{
  output->writeShort((short)this->migratedServerIds.size());
  for(uint _i1 = 0; _i1 < this->migratedServerIds.size(); _i1++)
  {
    if(this->migratedServerIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - MigratedServerListMessage -"<<"Forbidden value (" << this->migratedServerIds[_i1] << ") on element 1 (starting at 1) of migratedServerIds.";
    }
    output->writeVarShort((int)this->migratedServerIds[_i1]);
  }
}

void MigratedServerListMessage::deserialize(Reader *input)
{
  this->deserializeAs_MigratedServerListMessage(input);
}

void MigratedServerListMessage::deserializeAs_MigratedServerListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _migratedServerIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _migratedServerIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - MigratedServerListMessage -"<<"Forbidden value (" << _val1 << ") on elements of migratedServerIds.";
    }
    this->migratedServerIds.append(_val1);
  }
}

void MigratedServerListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MigratedServerListMessage(tree);
}

void MigratedServerListMessage::deserializeAsyncAs_MigratedServerListMessage(FuncTree tree)
{
  this->_migratedServerIdstree = tree.addChild(std::bind(&MigratedServerListMessage::_migratedServerIdstreeFunc, this, std::placeholders::_1));
}

void MigratedServerListMessage::_migratedServerIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_migratedServerIdstree.addChild(std::bind(&MigratedServerListMessage::_migratedServerIdsFunc, this, std::placeholders::_1));
  }
}

void MigratedServerListMessage::_migratedServerIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - MigratedServerListMessage -"<<"Forbidden value (" << _val << ") on elements of migratedServerIds.";
  }
  this->migratedServerIds.append(_val);
}

MigratedServerListMessage::MigratedServerListMessage()
{
  m_type = MessageEnum::MIGRATEDSERVERLISTMESSAGE;
}

