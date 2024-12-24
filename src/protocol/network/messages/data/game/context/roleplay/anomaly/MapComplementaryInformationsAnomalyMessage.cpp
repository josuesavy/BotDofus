#include "MapComplementaryInformationsAnomalyMessage.h"

void MapComplementaryInformationsAnomalyMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsAnomalyMessage(output);
}

void MapComplementaryInformationsAnomalyMessage::serializeAs_MapComplementaryInformationsAnomalyMessage(Writer *output)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(output);
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsAnomalyMessage -"<<"Forbidden value (" << this->level << ") on element level.";
  }
  output->writeVarShort((int)this->level);
  if(this->closingTime < 0 || this->closingTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsAnomalyMessage -"<<"Forbidden value (" << this->closingTime << ") on element closingTime.";
  }
  output->writeVarLong((double)this->closingTime);
}

void MapComplementaryInformationsAnomalyMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsAnomalyMessage(input);
}

void MapComplementaryInformationsAnomalyMessage::deserializeAs_MapComplementaryInformationsAnomalyMessage(Reader *input)
{
  MapComplementaryInformationsDataMessage::deserialize(input);
  this->_levelFunc(input);
  this->_closingTimeFunc(input);
}

void MapComplementaryInformationsAnomalyMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsAnomalyMessage(tree);
}

void MapComplementaryInformationsAnomalyMessage::deserializeAsyncAs_MapComplementaryInformationsAnomalyMessage(FuncTree tree)
{
  MapComplementaryInformationsDataMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&MapComplementaryInformationsAnomalyMessage::_levelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsAnomalyMessage::_closingTimeFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsAnomalyMessage::_levelFunc(Reader *input)
{
  this->level = input->readVarUhShort();
  if(this->level < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsAnomalyMessage -"<<"Forbidden value (" << this->level << ") on element of MapComplementaryInformationsAnomalyMessage.level.";
  }
}

void MapComplementaryInformationsAnomalyMessage::_closingTimeFunc(Reader *input)
{
  this->closingTime = input->readVarUhLong();
  if(this->closingTime < 0 || this->closingTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsAnomalyMessage -"<<"Forbidden value (" << this->closingTime << ") on element of MapComplementaryInformationsAnomalyMessage.closingTime.";
  }
}

MapComplementaryInformationsAnomalyMessage::MapComplementaryInformationsAnomalyMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSANOMALYMESSAGE;
}

