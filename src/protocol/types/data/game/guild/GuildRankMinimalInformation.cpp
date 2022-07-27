#include "GuildRankMinimalInformation.h"

void GuildRankMinimalInformation::serialize(Writer *output)
{
  this->serializeAs_GuildRankMinimalInformation(output);
}

void GuildRankMinimalInformation::serializeAs_GuildRankMinimalInformation(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GuildRankMinimalInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  output->writeUTF(this->name);
}

void GuildRankMinimalInformation::deserialize(Reader *input)
{
  this->deserializeAs_GuildRankMinimalInformation(input);
}

void GuildRankMinimalInformation::deserializeAs_GuildRankMinimalInformation(Reader *input)
{
  this->_idFunc(input);
  this->_nameFunc(input);
}

void GuildRankMinimalInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildRankMinimalInformation(tree);
}

void GuildRankMinimalInformation::deserializeAsyncAs_GuildRankMinimalInformation(FuncTree tree)
{
  tree.addChild(std::bind(&GuildRankMinimalInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildRankMinimalInformation::_nameFunc, this, std::placeholders::_1));
}

void GuildRankMinimalInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - GuildRankMinimalInformation -"<<"Forbidden value (" << this->id << ") on element of GuildRankMinimalInformation.id.";
  }
}

void GuildRankMinimalInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

GuildRankMinimalInformation::GuildRankMinimalInformation()
{
  m_types<<ClassEnum::GUILDRANKMINIMALINFORMATION;
}

bool GuildRankMinimalInformation::operator==(const GuildRankMinimalInformation &compared)
{
  if(id == compared.id)
  if(name == compared.name)
  return true;
  
  return false;
}

