#include "MapRunningFightDetailsRequestMessage.h"

void MapRunningFightDetailsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MapRunningFightDetailsRequestMessage(output);
}

void MapRunningFightDetailsRequestMessage::serializeAs_MapRunningFightDetailsRequestMessage(Writer *output)
{
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
}

void MapRunningFightDetailsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapRunningFightDetailsRequestMessage(input);
}

void MapRunningFightDetailsRequestMessage::deserializeAs_MapRunningFightDetailsRequestMessage(Reader *input)
{
  this->_fightIdFunc(input);
}

void MapRunningFightDetailsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapRunningFightDetailsRequestMessage(tree);
}

void MapRunningFightDetailsRequestMessage::deserializeAsyncAs_MapRunningFightDetailsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapRunningFightDetailsRequestMessage::_fightIdFunc, this, std::placeholders::_1));
}

void MapRunningFightDetailsRequestMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - MapRunningFightDetailsRequestMessage -"<<"Forbidden value (" << this->fightId << ") on element of MapRunningFightDetailsRequestMessage.fightId.";
  }
}

MapRunningFightDetailsRequestMessage::MapRunningFightDetailsRequestMessage()
{
  m_type = MessageEnum::MAPRUNNINGFIGHTDETAILSREQUESTMESSAGE;
}

