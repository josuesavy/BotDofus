#include "ZaapRespawnUpdatedMessage.h"

void ZaapRespawnUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_ZaapRespawnUpdatedMessage(output);
}

void ZaapRespawnUpdatedMessage::serializeAs_ZaapRespawnUpdatedMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ZaapRespawnUpdatedMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void ZaapRespawnUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_ZaapRespawnUpdatedMessage(input);
}

void ZaapRespawnUpdatedMessage::deserializeAs_ZaapRespawnUpdatedMessage(Reader *input)
{
  this->_mapIdFunc(input);
}

void ZaapRespawnUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ZaapRespawnUpdatedMessage(tree);
}

void ZaapRespawnUpdatedMessage::deserializeAsyncAs_ZaapRespawnUpdatedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ZaapRespawnUpdatedMessage::_mapIdFunc, this, std::placeholders::_1));
}

void ZaapRespawnUpdatedMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ZaapRespawnUpdatedMessage -"<<"Forbidden value (" << this->mapId << ") on element of ZaapRespawnUpdatedMessage.mapId.";
  }
}

ZaapRespawnUpdatedMessage::ZaapRespawnUpdatedMessage()
{
  m_type = MessageEnum::ZAAPRESPAWNUPDATEDMESSAGE;
}

