#include "TeleportRequestMessage.h"

void TeleportRequestMessage::serialize(Writer *output)
{
  this->serializeAs_TeleportRequestMessage(output);
}

void TeleportRequestMessage::serializeAs_TeleportRequestMessage(Writer *output)
{
  output->writeByte(this->sourceType);
  output->writeByte(this->destinationType);
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void TeleportRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_TeleportRequestMessage(input);
}

void TeleportRequestMessage::deserializeAs_TeleportRequestMessage(Reader *input)
{
  this->_sourceTypeFunc(input);
  this->_destinationTypeFunc(input);
  this->_mapIdFunc(input);
}

void TeleportRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TeleportRequestMessage(tree);
}

void TeleportRequestMessage::deserializeAsyncAs_TeleportRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TeleportRequestMessage::_sourceTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportRequestMessage::_destinationTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TeleportRequestMessage::_mapIdFunc, this, std::placeholders::_1));
}

void TeleportRequestMessage::_sourceTypeFunc(Reader *input)
{
  this->sourceType = input->readByte();
  if(this->sourceType < 0)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->sourceType << ") on element of TeleportRequestMessage.sourceType.";
  }
}

void TeleportRequestMessage::_destinationTypeFunc(Reader *input)
{
  this->destinationType = input->readByte();
  if(this->destinationType < 0)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->destinationType << ") on element of TeleportRequestMessage.destinationType.";
  }
}

void TeleportRequestMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TeleportRequestMessage -"<<"Forbidden value (" << this->mapId << ") on element of TeleportRequestMessage.mapId.";
  }
}

TeleportRequestMessage::TeleportRequestMessage()
{
  m_type = MessageEnum::TELEPORTREQUESTMESSAGE;
}

