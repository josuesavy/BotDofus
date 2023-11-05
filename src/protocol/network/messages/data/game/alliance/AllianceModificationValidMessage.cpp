#include "AllianceModificationValidMessage.h"

void AllianceModificationValidMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationValidMessage(output);
}

void AllianceModificationValidMessage::serializeAs_AllianceModificationValidMessage(Writer *output)
{
  output->writeUTF(this->allianceName);
  output->writeUTF(this->allianceTag);
  this->allianceEmblem.serializeAs_SocialEmblem(output);
}

void AllianceModificationValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationValidMessage(input);
}

void AllianceModificationValidMessage::deserializeAs_AllianceModificationValidMessage(Reader *input)
{
  this->_allianceNameFunc(input);
  this->_allianceTagFunc(input);
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserialize(input);
}

void AllianceModificationValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationValidMessage(tree);
}

void AllianceModificationValidMessage::deserializeAsyncAs_AllianceModificationValidMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceModificationValidMessage::_allianceNameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceModificationValidMessage::_allianceTagFunc, this, std::placeholders::_1));
  this->_allianceEmblemtree = tree.addChild(std::bind(&AllianceModificationValidMessage::_allianceEmblemtreeFunc, this, std::placeholders::_1));
}

void AllianceModificationValidMessage::_allianceNameFunc(Reader *input)
{
  this->allianceName = input->readUTF();
}

void AllianceModificationValidMessage::_allianceTagFunc(Reader *input)
{
  this->allianceTag = input->readUTF();
}

void AllianceModificationValidMessage::_allianceEmblemtreeFunc(Reader *input)
{
  this->allianceEmblem = SocialEmblem();
  this->allianceEmblem.deserializeAsync(this->_allianceEmblemtree);
}

AllianceModificationValidMessage::AllianceModificationValidMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONVALIDMESSAGE;
}

