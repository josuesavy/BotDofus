#include "AllianceRankCreateRequestMessage.h"

void AllianceRankCreateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRankCreateRequestMessage(output);
}

void AllianceRankCreateRequestMessage::serializeAs_AllianceRankCreateRequestMessage(Writer *output)
{
  if(this->parentRankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankCreateRequestMessage -"<<"Forbidden value (" << this->parentRankId << ") on element parentRankId.";
  }
  output->writeVarInt((int)this->parentRankId);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankCreateRequestMessage -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
  output->writeUTF(this->name);
}

void AllianceRankCreateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRankCreateRequestMessage(input);
}

void AllianceRankCreateRequestMessage::deserializeAs_AllianceRankCreateRequestMessage(Reader *input)
{
  this->_parentRankIdFunc(input);
  this->_gfxIdFunc(input);
  this->_nameFunc(input);
}

void AllianceRankCreateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRankCreateRequestMessage(tree);
}

void AllianceRankCreateRequestMessage::deserializeAsyncAs_AllianceRankCreateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceRankCreateRequestMessage::_parentRankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceRankCreateRequestMessage::_gfxIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceRankCreateRequestMessage::_nameFunc, this, std::placeholders::_1));
}

void AllianceRankCreateRequestMessage::_parentRankIdFunc(Reader *input)
{
  this->parentRankId = input->readVarUhInt();
  if(this->parentRankId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankCreateRequestMessage -"<<"Forbidden value (" << this->parentRankId << ") on element of AllianceRankCreateRequestMessage.parentRankId.";
  }
}

void AllianceRankCreateRequestMessage::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - AllianceRankCreateRequestMessage -"<<"Forbidden value (" << this->gfxId << ") on element of AllianceRankCreateRequestMessage.gfxId.";
  }
}

void AllianceRankCreateRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

AllianceRankCreateRequestMessage::AllianceRankCreateRequestMessage()
{
  m_type = MessageEnum::ALLIANCERANKCREATEREQUESTMESSAGE;
}

