#include "MapInformationsRequestMessage.h"

void MapInformationsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MapInformationsRequestMessage(output);
}

void MapInformationsRequestMessage::serializeAs_MapInformationsRequestMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapInformationsRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void MapInformationsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapInformationsRequestMessage(input);
}

void MapInformationsRequestMessage::deserializeAs_MapInformationsRequestMessage(Reader *input)
{
  this->_mapIdFunc(input);
}

void MapInformationsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapInformationsRequestMessage(tree);
}

void MapInformationsRequestMessage::deserializeAsyncAs_MapInformationsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MapInformationsRequestMessage::_mapIdFunc, this, std::placeholders::_1));
}

void MapInformationsRequestMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - MapInformationsRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of MapInformationsRequestMessage.mapId.";
  }
}

MapInformationsRequestMessage::MapInformationsRequestMessage()
{
  m_type = MessageEnum::MAPINFORMATIONSREQUESTMESSAGE;
}

