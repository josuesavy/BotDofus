#include "RankPublicInformation.h"

void RankPublicInformation::serialize(Writer *output)
{
  this->serializeAs_RankPublicInformation(output);
}

void RankPublicInformation::serializeAs_RankPublicInformation(Writer *output)
{
  RankMinimalInformation::serializeAs_RankMinimalInformation(output);
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - RankPublicInformation -"<<"Forbidden value (" << this->order << ") on element order.";
  }
  output->writeVarInt((int)this->order);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - RankPublicInformation -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
}

void RankPublicInformation::deserialize(Reader *input)
{
  this->deserializeAs_RankPublicInformation(input);
}

void RankPublicInformation::deserializeAs_RankPublicInformation(Reader *input)
{
  RankMinimalInformation::deserialize(input);
  this->_orderFunc(input);
  this->_gfxIdFunc(input);
}

void RankPublicInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RankPublicInformation(tree);
}

void RankPublicInformation::deserializeAsyncAs_RankPublicInformation(FuncTree tree)
{
  RankMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&RankPublicInformation::_orderFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RankPublicInformation::_gfxIdFunc, this, std::placeholders::_1));
}

void RankPublicInformation::_orderFunc(Reader *input)
{
  this->order = input->readVarUhInt();
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - RankPublicInformation -"<<"Forbidden value (" << this->order << ") on element of RankPublicInformation.order.";
  }
}

void RankPublicInformation::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - RankPublicInformation -"<<"Forbidden value (" << this->gfxId << ") on element of RankPublicInformation.gfxId.";
  }
}

RankPublicInformation::RankPublicInformation()
{
  m_types<<ClassEnum::RANKPUBLICINFORMATION;
}

bool RankPublicInformation::operator==(const RankPublicInformation &compared)
{
  if(order == compared.order)
  if(gfxId == compared.gfxId)
  return true;
  
  return false;
}

