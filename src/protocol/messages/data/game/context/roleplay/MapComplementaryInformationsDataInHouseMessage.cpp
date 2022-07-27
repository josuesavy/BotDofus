#include "MapComplementaryInformationsDataInHouseMessage.h"

void MapComplementaryInformationsDataInHouseMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsDataInHouseMessage(output);
}

void MapComplementaryInformationsDataInHouseMessage::serializeAs_MapComplementaryInformationsDataInHouseMessage(Writer *output)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(output);
  this->currentHouse->serializeAs_HouseInformationsInside(output);
}

void MapComplementaryInformationsDataInHouseMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsDataInHouseMessage(input);
}

void MapComplementaryInformationsDataInHouseMessage::deserializeAs_MapComplementaryInformationsDataInHouseMessage(Reader *input)
{
  MapComplementaryInformationsDataMessage::deserialize(input);
  this->currentHouse = QSharedPointer<HouseInformationsInside>(new HouseInformationsInside() );
  this->currentHouse->deserialize(input);
}

void MapComplementaryInformationsDataInHouseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsDataInHouseMessage(tree);
}

void MapComplementaryInformationsDataInHouseMessage::deserializeAsyncAs_MapComplementaryInformationsDataInHouseMessage(FuncTree tree)
{
  MapComplementaryInformationsDataMessage::deserializeAsync(tree);
  this->_currentHousetree = tree.addChild(std::bind(&MapComplementaryInformationsDataInHouseMessage::_currentHousetreeFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsDataInHouseMessage::_currentHousetreeFunc(Reader *input)
{
  this->currentHouse = QSharedPointer<HouseInformationsInside>(new HouseInformationsInside() );
  this->currentHouse->deserializeAsync(this->_currentHousetree);
}

MapComplementaryInformationsDataInHouseMessage::MapComplementaryInformationsDataInHouseMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHOUSEMESSAGE;
}

