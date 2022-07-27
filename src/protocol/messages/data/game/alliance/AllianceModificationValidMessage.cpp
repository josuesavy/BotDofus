#include "AllianceModificationValidMessage.h"

void AllianceModificationValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationValidMessage(output);
}

void AllianceModificationValidMessage::serializeAs_AllianceModificationValidMessage(Writer *output)
{
  output->writeUTF(this->allianceName);
  output->writeUTF(this->allianceTag);
  this->Alliancemblem.serializeAs_GuildEmblem(output);
}

void AllianceModificationValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationValidMessage(input);
}

void AllianceModificationValidMessage::deserializeAs_AllianceModificationValidMessage(Reader *input)
{
  this->_allianceNameFunc(input);
  this->_allianceTagFunc(input);
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserialize(input);
}

void AllianceModificationValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationValidMessage(tree);
}

void AllianceModificationValidMessage::deserializeAsyncAs_AllianceModificationValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceModificationValidMessage::_allianceNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceModificationValidMessage::_allianceTagFunc, this, std::placeholders::_1));
  this->_Alliancemblemtree = tree.addChild(std::bind(&AllianceModificationValidMessage::_AlliancemblemtreeFunc, this, std::placeholders::_1));
}

void AllianceModificationValidMessage::_allianceNameFunc(Reader *input)
{
  this->allianceName = input->readUTF();
}

void AllianceModificationValidMessage::_allianceTagFunc(Reader *input)
{
  this->allianceTag = input->readUTF();
}

void AllianceModificationValidMessage::_AlliancemblemtreeFunc(Reader *input)
{
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserializeAsync(this->_Alliancemblemtree);
}

AllianceModificationValidMessage::AllianceModificationValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONVALIDMESSAGE;
}

