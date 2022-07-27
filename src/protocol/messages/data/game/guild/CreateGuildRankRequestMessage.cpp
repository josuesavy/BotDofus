#include "CreateGuildRankRequestMessage.h"

void CreateGuildRankRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CreateGuildRankRequestMessage(output);
}

void CreateGuildRankRequestMessage::serializeAs_CreateGuildRankRequestMessage(Writer *output)
{
  if(this->parentRankId < 0)
  {
    qDebug()<<"ERREUR - CreateGuildRankRequestMessage -"<<"Forbidden value (" << this->parentRankId << ") on element parentRankId.";
  }
  output->writeVarInt((int)this->parentRankId);
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - CreateGuildRankRequestMessage -"<<"Forbidden value (" << this->gfxId << ") on element gfxId.";
  }
  output->writeVarInt((int)this->gfxId);
  output->writeUTF(this->name);
}

void CreateGuildRankRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CreateGuildRankRequestMessage(input);
}

void CreateGuildRankRequestMessage::deserializeAs_CreateGuildRankRequestMessage(Reader *input)
{
  this->_parentRankIdFunc(input);
  this->_gfxIdFunc(input);
  this->_nameFunc(input);
}

void CreateGuildRankRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CreateGuildRankRequestMessage(tree);
}

void CreateGuildRankRequestMessage::deserializeAsyncAs_CreateGuildRankRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CreateGuildRankRequestMessage::_parentRankIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CreateGuildRankRequestMessage::_gfxIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CreateGuildRankRequestMessage::_nameFunc, this, std::placeholders::_1));
}

void CreateGuildRankRequestMessage::_parentRankIdFunc(Reader *input)
{
  this->parentRankId = input->readVarUhInt();
  if(this->parentRankId < 0)
  {
    qDebug()<<"ERREUR - CreateGuildRankRequestMessage -"<<"Forbidden value (" << this->parentRankId << ") on element of CreateGuildRankRequestMessage.parentRankId.";
  }
}

void CreateGuildRankRequestMessage::_gfxIdFunc(Reader *input)
{
  this->gfxId = input->readVarUhInt();
  if(this->gfxId < 0)
  {
    qDebug()<<"ERREUR - CreateGuildRankRequestMessage -"<<"Forbidden value (" << this->gfxId << ") on element of CreateGuildRankRequestMessage.gfxId.";
  }
}

void CreateGuildRankRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

CreateGuildRankRequestMessage::CreateGuildRankRequestMessage()
{
  m_type = MessageEnum::CREATEGUILDRANKREQUESTMESSAGE;
}

