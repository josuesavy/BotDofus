#include "GuildRankPublicInformation.h"

void GuildRankPublicInformation::serialize(Writer *output)
{
  this->serializeAs_GuildRankPublicInformation(output);
}

void GuildRankPublicInformation::serializeAs_GuildRankPublicInformation(Writer *output)
{
  GuildRankMinimalInformation::serializeAs_GuildRankMinimalInformation(output);
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - GuildRankPublicInformation -"<<"Forbidden value (" << this->order << ") on element order.";
  }
  output->writeVarInt((int)this->order);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - GuildRankPublicInformation -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
}

void GuildRankPublicInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildRankPublicInformation(input);
}

void GuildRankPublicInformation::deserializeAs_GuildRankPublicInformation(Reader *input)
{
  GuildRankMinimalInformation::deserialize(input);
  this->_orderFunc(input);
  this->_gfxIdFunc(input);
}

void GuildRankPublicInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRankPublicInformation(tree);
}

void GuildRankPublicInformation::deserializeAsyncAs_GuildRankPublicInformation(FuncTree tree)
{
  GuildRankMinimalInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildRankPublicInformation::_orderFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRankPublicInformation::_gfxIdFunc, this, std::placeholders::_1));
}

void GuildRankPublicInformation::_orderFunc(Reader *input)
{
  this->order = input->readVarUhInt();
  if(this->order < 0)
  {
    qDebug()<<"ERREUR - GuildRankPublicInformation -"<<"Forbidden value (" << this->order << ") on element of GuildRankPublicInformation.order.";
  }
}

void GuildRankPublicInformation::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - GuildRankPublicInformation -"<<"Forbidden value (" << this->gfxId << ") on element of GuildRankPublicInformation.gfxId.";
  }
}

GuildRankPublicInformation::GuildRankPublicInformation()
{
  m_types<<ClassEnum::GUILDRANKPUBLICINFORMATION;
}

bool GuildRankPublicInformation::operator==(const GuildRankPublicInformation &compared)
{
  if(order == compared.order)
  if(gfxId == compared.gfxId)
  return true;
  
  return false;
}

