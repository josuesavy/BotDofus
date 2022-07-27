#include "GuildRankInformation.h"

void GuildRankInformation::serialize(Writer *output)
{
  this->serializeAs_GuildRankInformation(output);
}

void GuildRankInformation::serializeAs_GuildRankInformation(Writer *output)
{
  GuildRankMinimalInformation::serializeAs_GuildRankMinimalInformation(output);
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << this->order << ") on element order.";
  }
  output->writeVarInt((int)this->order);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
  output->writeBool(this->modifiable);
  output->writeShort((short)this->rights.size());
  for(uint _i4 = 0; _i4 < this->rights.size(); _i4++)
  {
    if(this->rights[_i4] < 0)
    {
      qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << this->rights[_i4] << ") on element 4 (starting at 1) of rights.";
    }
    output->writeVarInt((int)this->rights[_i4]);
  }
}

void GuildRankInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildRankInformation(input);
}

void GuildRankInformation::deserializeAs_GuildRankInformation(Reader *input)
{
  uint _val4 = 0;
  GuildRankMinimalInformation::deserialize(input);
  this->_orderFunc(input);
  this->_gfxIdFunc(input);
  this->_modifiableFunc(input);
  uint _rightsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _rightsLen; _i4++)
  {
    _val4 = input->readVarUhInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << _val4 << ") on elements of rights.";
    }
    this->rights.append(_val4);
  }
}

void GuildRankInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRankInformation(tree);
}

void GuildRankInformation::deserializeAsyncAs_GuildRankInformation(FuncTree tree)
{
  GuildRankMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildRankInformation::_orderFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRankInformation::_gfxIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRankInformation::_modifiableFunc, this, std::placeholders::_1));
  this->_rightstree = tree.addChild(std::bind(&GuildRankInformation::_rightstreeFunc, this, std::placeholders::_1));
}

void GuildRankInformation::_orderFunc(Reader *input)
{
  this->order = input->readVarUhInt();
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << this->order << ") on element of GuildRankInformation.order.";
  }
}

void GuildRankInformation::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << this->gfxId << ") on element of GuildRankInformation.gfxId.";
  }
}

void GuildRankInformation::_modifiableFunc(Reader *input)
{
  this->modifiable = input->readBool();
}

void GuildRankInformation::_rightstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_rightstree.addChild(std::bind(&GuildRankInformation::_rightsFunc, this, std::placeholders::_1));
  }
}

void GuildRankInformation::_rightsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildRankInformation -"<<"Forbidden value (" << _val << ") on elements of rights.";
  }
  this->rights.append(_val);
}

GuildRankInformation::GuildRankInformation()
{
  m_types<<ClassEnum::GUILDRANKINFORMATION;
}

bool GuildRankInformation::operator==(const GuildRankInformation &compared)
{
  if(order == compared.order)
  if(gfxId == compared.gfxId)
  if(modifiable == compared.modifiable)
  if(rights == compared.rights)
  if(_rightstree == compared._rightstree)
  return true;
  
  return false;
}

