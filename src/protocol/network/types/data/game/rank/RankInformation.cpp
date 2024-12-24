#include "RankInformation.h"

void RankInformation::serialize(Writer *output)
{
  this->serializeAs_RankInformation(output);
}

void RankInformation::serializeAs_RankInformation(Writer *output)
{
  RankMinimalInformation::serializeAs_RankMinimalInformation(output);
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << this->order << ") on element order.";
  }
  output->writeVarInt((int)this->order);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
  output->writeBool(this->modifiable);
  output->writeShort((short)this->rights.size());
  for(uint _i4 = 0; _i4 < this->rights.size(); _i4++)
  {
    if(this->rights[_i4] < 0)
    {
      qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << this->rights[_i4] << ") on element 4 (starting at 1) of rights.";
    }
    output->writeVarInt((int)this->rights[_i4]);
  }
}

void RankInformation::deserialize(Reader *input)
{
  this->deserializeAs_RankInformation(input);
}

void RankInformation::deserializeAs_RankInformation(Reader *input)
{
  uint _val4 = 0;
  RankMinimalInformation::deserialize(input);
  this->_orderFunc(input);
  this->_gfxIdFunc(input);
  this->_modifiableFunc(input);
  uint _rightsLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _rightsLen; _i4++)
  {
    _val4 = input->readVarUhInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << _val4 << ") on elements of rights.";
    }
    this->rights.append(_val4);
  }
}

void RankInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RankInformation(tree);
}

void RankInformation::deserializeAsyncAs_RankInformation(FuncTree tree)
{
  RankMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&RankInformation::_orderFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RankInformation::_gfxIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RankInformation::_modifiableFunc, this, std::placeholders::_1));
  this->_rightstree = tree.addChild(std::bind(&RankInformation::_rightstreeFunc, this, std::placeholders::_1));
}

void RankInformation::_orderFunc(Reader *input)
{
  this->order = input->readVarUhInt();
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << this->order << ") on element of RankInformation.order.";
  }
}

void RankInformation::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << this->gfxId << ") on element of RankInformation.gfxId.";
  }
}

void RankInformation::_modifiableFunc(Reader *input)
{
  this->modifiable = input->readBool();
}

void RankInformation::_rightstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_rightstree.addChild(std::bind(&RankInformation::_rightsFunc, this, std::placeholders::_1));
  }
}

void RankInformation::_rightsFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - RankInformation -"<<"Forbidden value (" << _val << ") on elements of rights.";
  }
  this->rights.append(_val);
}

RankInformation::RankInformation()
{
  m_types<<ClassEnum::RANKINFORMATION;
}

bool RankInformation::operator==(const RankInformation &compared)
{
  if(order == compared.order)
  if(gfxId == compared.gfxId)
  if(modifiable == compared.modifiable)
  if(rights == compared.rights)
  if(_rightstree == compared._rightstree)
  return true;
  
  return false;
}

