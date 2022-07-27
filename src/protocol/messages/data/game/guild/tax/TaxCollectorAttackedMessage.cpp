#include "TaxCollectorAttackedMessage.h"

void TaxCollectorAttackedMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorAttackedMessage(output);
}

void TaxCollectorAttackedMessage::serializeAs_TaxCollectorAttackedMessage(Writer *output)
{
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->firstNameId << ") on element firstNameId.";
  }
  output->writeVarShort((int)this->firstNameId);
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->lastNameId << ") on element lastNameId.";
  }
  output->writeVarShort((int)this->lastNameId);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  this->guild->serializeAs_BasicGuildInformations(output);
}

void TaxCollectorAttackedMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorAttackedMessage(input);
}

void TaxCollectorAttackedMessage::deserializeAs_TaxCollectorAttackedMessage(Reader *input)
{
  this->_firstNameIdFunc(input);
  this->_lastNameIdFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  this->_subAreaIdFunc(input);
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserialize(input);
}

void TaxCollectorAttackedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorAttackedMessage(tree);
}

void TaxCollectorAttackedMessage::deserializeAsyncAs_TaxCollectorAttackedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_firstNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_lastNameIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorAttackedMessage::_subAreaIdFunc, this, std::placeholders::_1));
  this->_guildtree = tree.addChild(std::bind(&TaxCollectorAttackedMessage::_guildtreeFunc, this, std::placeholders::_1));
}

void TaxCollectorAttackedMessage::_firstNameIdFunc(Reader *input)
{
  this->firstNameId = input->readVarUhShort();
  if(this->firstNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->firstNameId << ") on element of TaxCollectorAttackedMessage.firstNameId.";
  }
}

void TaxCollectorAttackedMessage::_lastNameIdFunc(Reader *input)
{
  this->lastNameId = input->readVarUhShort();
  if(this->lastNameId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->lastNameId << ") on element of TaxCollectorAttackedMessage.lastNameId.";
  }
}

void TaxCollectorAttackedMessage::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldX << ") on element of TaxCollectorAttackedMessage.worldX.";
  }
}

void TaxCollectorAttackedMessage::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->worldY << ") on element of TaxCollectorAttackedMessage.worldY.";
  }
}

void TaxCollectorAttackedMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->mapId << ") on element of TaxCollectorAttackedMessage.mapId.";
  }
}

void TaxCollectorAttackedMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorAttackedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of TaxCollectorAttackedMessage.subAreaId.";
  }
}

void TaxCollectorAttackedMessage::_guildtreeFunc(Reader *input)
{
  this->guild = QSharedPointer<BasicGuildInformations>(new BasicGuildInformations() );
  this->guild->deserializeAsync(this->_guildtree);
}

TaxCollectorAttackedMessage::TaxCollectorAttackedMessage()
{
  m_type = MessageEnum::TAXCOLLECTORATTACKEDMESSAGE;
}

