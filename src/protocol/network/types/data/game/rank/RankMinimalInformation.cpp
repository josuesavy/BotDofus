#include "RankMinimalInformation.h"

void RankMinimalInformation::serialize(Writer *output)
{
  this->serializeAs_RankMinimalInformation(output);
}

void RankMinimalInformation::serializeAs_RankMinimalInformation(Writer *output)
{
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - RankMinimalInformation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeVarInt((int)this->id);
  output->writeUTF(this->name);
}

void RankMinimalInformation::deserialize(Reader *input)
{
  this->deserializeAs_RankMinimalInformation(input);
}

void RankMinimalInformation::deserializeAs_RankMinimalInformation(Reader *input)
{
  this->_idFunc(input);
  this->_nameFunc(input);
}

void RankMinimalInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_RankMinimalInformation(tree);
}

void RankMinimalInformation::deserializeAsyncAs_RankMinimalInformation(FuncTree tree)
{
  tree.addChild(std::bind(&RankMinimalInformation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&RankMinimalInformation::_nameFunc, this, std::placeholders::_1));
}

void RankMinimalInformation::_idFunc(Reader *input)
{
  this->id = input->readVarUhInt();
  if(this->id < 0)
  {
    qDebug()<<"ERREUR - RankMinimalInformation -"<<"Forbidden value (" << this->id << ") on element of RankMinimalInformation.id.";
  }
}

void RankMinimalInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

RankMinimalInformation::RankMinimalInformation()
{
  m_types<<ClassEnum::RANKMINIMALINFORMATION;
}

bool RankMinimalInformation::operator==(const RankMinimalInformation &compared)
{
  if(id == compared.id)
  if(name == compared.name)
  return true;
  
  return false;
}

