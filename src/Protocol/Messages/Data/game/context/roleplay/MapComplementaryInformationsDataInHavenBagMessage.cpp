#include "MapComplementaryInformationsDataInHavenBagMessage.h"

void MapComplementaryInformationsDataInHavenBagMessage::serialize(Writer *output)
{
  this->serializeAs_MapComplementaryInformationsDataInHavenBagMessage(output);
}

void MapComplementaryInformationsDataInHavenBagMessage::serializeAs_MapComplementaryInformationsDataInHavenBagMessage(Writer *output)
{
  MapComplementaryInformationsDataMessage::serializeAs_MapComplementaryInformationsDataMessage(output);
  this->ownerInformations.serializeAs_CharacterMinimalInformations(output);
  output->writeByte(this->theme);
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->roomId << ") on element roomId.";
  }
  output->writeByte(this->roomId);
  if(this->maxRoomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->maxRoomId << ") on element maxRoomId.";
  }
  output->writeByte(this->maxRoomId);
}

void MapComplementaryInformationsDataInHavenBagMessage::deserialize(Reader *input)
{
  this->deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(input);
}

void MapComplementaryInformationsDataInHavenBagMessage::deserializeAs_MapComplementaryInformationsDataInHavenBagMessage(Reader *input)
{
  MapComplementaryInformationsDataMessage::deserialize(input);
  this->ownerInformations = CharacterMinimalInformations();
  this->ownerInformations.deserialize(input);
  this->_themeFunc(input);
  this->_roomIdFunc(input);
  this->_maxRoomIdFunc(input);
}

void MapComplementaryInformationsDataInHavenBagMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MapComplementaryInformationsDataInHavenBagMessage(tree);
}

void MapComplementaryInformationsDataInHavenBagMessage::deserializeAsyncAs_MapComplementaryInformationsDataInHavenBagMessage(FuncTree tree)
{
  MapComplementaryInformationsDataMessage::deserializeAsync(tree);
  this->_ownerInformationstree = tree.addChild(std::bind(&MapComplementaryInformationsDataInHavenBagMessage::_ownerInformationstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsDataInHavenBagMessage::_themeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsDataInHavenBagMessage::_roomIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&MapComplementaryInformationsDataInHavenBagMessage::_maxRoomIdFunc, this, std::placeholders::_1));
}

void MapComplementaryInformationsDataInHavenBagMessage::_ownerInformationstreeFunc(Reader *input)
{
  this->ownerInformations = CharacterMinimalInformations();
  this->ownerInformations.deserializeAsync(this->_ownerInformationstree);
}

void MapComplementaryInformationsDataInHavenBagMessage::_themeFunc(Reader *input)
{
  this->theme = input->readByte();
}

void MapComplementaryInformationsDataInHavenBagMessage::_roomIdFunc(Reader *input)
{
  this->roomId = input->readByte();
  if(this->roomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->roomId << ") on element of MapComplementaryInformationsDataInHavenBagMessage.roomId.";
  }
}

void MapComplementaryInformationsDataInHavenBagMessage::_maxRoomIdFunc(Reader *input)
{
  this->maxRoomId = input->readByte();
  if(this->maxRoomId < 0)
  {
    qDebug()<<"ERREUR - MapComplementaryInformationsDataInHavenBagMessage -"<<"Forbidden value (" << this->maxRoomId << ") on element of MapComplementaryInformationsDataInHavenBagMessage.maxRoomId.";
  }
}

MapComplementaryInformationsDataInHavenBagMessage::MapComplementaryInformationsDataInHavenBagMessage()
{
  m_type = MessageEnum::MAPCOMPLEMENTARYINFORMATIONSDATAINHAVENBAGMESSAGE;
}

