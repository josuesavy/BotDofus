#include "MapComplementaryInformationsWithCoordsMessage.h"

void MapComplementaryInformationsWithCoordsMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsWithCoordsMessage(output);
}

void MapComplementaryInformationsWithCoordsMessage::serializeAs_MapComplementaryInformationsWithCoordsMessage(Writer *output)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
}

void MapComplementaryInformationsWithCoordsMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsWithCoordsMessage(input);
}

void MapComplementaryInformationsWithCoordsMessage::deserializeAs_MapComplementaryInformationsWithCoordsMessage(Reader *input)
{
  MapComplementaryInformationsDataMessage::deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
}

void MapComplementaryInformationsWithCoordsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsWithCoordsMessage(tree);
}

void MapComplementaryInformationsWithCoordsMessage::deserializeAsyncAs_MapComplementaryInformationsWithCoordsMessage(FuncTree tree)
{
  MapComplementaryInformationsDataMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&MapComplementaryInformationsWithCoordsMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsWithCoordsMessage::_worldYFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsWithCoordsMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldX << ") on element of MapComplementaryInformationsWithCoordsMessage.worldX.";
  }
}

void MapComplementaryInformationsWithCoordsMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsWithCoordsMessage -"<<"Forbidden value (" << this->worldY << ") on element of MapComplementaryInformationsWithCoordsMessage.worldY.";
  }
}

MapComplementaryInformationsWithCoordsMessage::MapComplementaryInformationsWithCoordsMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSWITHCOORDSMESSAGE;
}

