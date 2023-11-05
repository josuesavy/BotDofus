#include "MapFightCountMessage.h"

void MapFightCountMessage::serialize(Writer *output)
{
  this->serializeAs_MapFightCountMessage(output);
}

void MapFightCountMessage::serializeAs_MapFightCountMessage(Writer *output)
{
  if(this->fightCount < 0)
  {
    qDebug()<<"ERREUR - MapFightCountMessage -"<<"Forbidden value (" << this->fightCount << ") on element fightCount.";
  }
  output->writeVarShort((int)this->fightCount);
}

void MapFightCountMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapFightCountMessage(input);
}

void MapFightCountMessage::deserializeAs_MapFightCountMessage(Reader *input)
{
  this->_fightCountFunc(input);
}

void MapFightCountMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapFightCountMessage(tree);
}

void MapFightCountMessage::deserializeAsyncAs_MapFightCountMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapFightCountMessage::_fightCountFunc, this, std::placeholders::_1));
}

void MapFightCountMessage::_fightCountFunc(Reader *input)
{
  this->fightCount = input->readVarUhShort();
  if(this->fightCount < 0)
  {
    qDebug()<<"ERREUR - MapFightCountMessage -"<<"Forbidden value (" << this->fightCount << ") on element of MapFightCountMessage.fightCount.";
  }
}

MapFightCountMessage::MapFightCountMessage()
{
  m_type = MessageEnum::MAPFIGHTCOUNTMESSAGE;
}

