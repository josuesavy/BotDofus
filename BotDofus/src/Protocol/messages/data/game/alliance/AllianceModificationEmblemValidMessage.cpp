#include "AllianceModificationEmblemValidMessage.h"

void AllianceModificationEmblemValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationEmblemValidMessage(output);
}

void AllianceModificationEmblemValidMessage::serializeAs_AllianceModificationEmblemValidMessage(Writer *output)
{
  this->Alliancemblem.serializeAs_GuildEmblem(output);
}

void AllianceModificationEmblemValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationEmblemValidMessage(input);
}

void AllianceModificationEmblemValidMessage::deserializeAs_AllianceModificationEmblemValidMessage(Reader *input)
{
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserialize(input);
}

void AllianceModificationEmblemValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationEmblemValidMessage(tree);
}

void AllianceModificationEmblemValidMessage::deserializeAsyncAs_AllianceModificationEmblemValidMessage(FuncTree tree)
{
  this->_Alliancemblemtree = tree.addChild(std::bind(&AllianceModificationEmblemValidMessage::_AlliancemblemtreeFunc, this, std::placeholders::_1));
}

void AllianceModificationEmblemValidMessage::_AlliancemblemtreeFunc(Reader *input)
{
  this->Alliancemblem = GuildEmblem();
  this->Alliancemblem.deserializeAsync(this->_Alliancemblemtree);
}

AllianceModificationEmblemValidMessage::AllianceModificationEmblemValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE;
}

