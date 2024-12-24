#include "AllianceModificationEmblemValidMessage.h"

void AllianceModificationEmblemValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationEmblemValidMessage(output);
}

void AllianceModificationEmblemValidMessage::serializeAs_AllianceModificationEmblemValidMessage(Writer *output)
{
  this->allianceEmblem.serializeAs_SocialEmblem(output);
}

void AllianceModificationEmblemValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationEmblemValidMessage(input);
}

void AllianceModificationEmblemValidMessage::deserializeAs_AllianceModificationEmblemValidMessage(Reader *input)
{
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserialize(input);
}

void AllianceModificationEmblemValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationEmblemValidMessage(tree);
}

void AllianceModificationEmblemValidMessage::deserializeAsyncAs_AllianceModificationEmblemValidMessage(FuncTree tree)
{
  this->_allianceEmblemtree = tree.addChild(std::bind(&AllianceModificationEmblemValidMessage::_allianceEmblemtreeFunc, this, std::placeholders::_1));
}

void AllianceModificationEmblemValidMessage::_allianceEmblemtreeFunc(Reader *input)
{
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserializeAsync(this->_allianceEmblemtree);
}

AllianceModificationEmblemValidMessage::AllianceModificationEmblemValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONEMBLEMVALIDMESSAGE;
}

