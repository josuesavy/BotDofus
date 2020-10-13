#include "ZaapDestinationsMessage.h"

void ZaapDestinationsMessage::serialize(Writer *output)
{
  this->serializeAs_ZaapDestinationsMessage(output);
}

void ZaapDestinationsMessage::serializeAs_ZaapDestinationsMessage(Writer *output)
{
  TeleportDestinationsMessage::serializeAs_TeleportDestinationsMessage(output);
  if(this->spawnMapId < 0 || this->spawnMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ZaapDestinationsMessage -"<<"Forbidden value (" << this->spawnMapId << ") on element spawnMapId.";
  }
  output->writeDouble(this->spawnMapId);
}

void ZaapDestinationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ZaapDestinationsMessage(input);
}

void ZaapDestinationsMessage::deserializeAs_ZaapDestinationsMessage(Reader *input)
{
  TeleportDestinationsMessage::deserialize(input);
  this->_spawnMapIdFunc(input);
}

void ZaapDestinationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ZaapDestinationsMessage(tree);
}

void ZaapDestinationsMessage::deserializeAsyncAs_ZaapDestinationsMessage(FuncTree tree)
{
  TeleportDestinationsMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ZaapDestinationsMessage::_spawnMapIdFunc, this, std::placeholders::_1));
}

void ZaapDestinationsMessage::_spawnMapIdFunc(Reader *input)
{
  this->spawnMapId = input->readDouble();
  if(this->spawnMapId < 0 || this->spawnMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ZaapDestinationsMessage -"<<"Forbidden value (" << this->spawnMapId << ") on element of ZaapDestinationsMessage.spawnMapId.";
  }
}

ZaapDestinationsMessage::ZaapDestinationsMessage()
{
  m_type = MessageEnum::ZAAPDESTINATIONSMESSAGE;
}

