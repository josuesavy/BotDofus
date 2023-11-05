#include "AllianceFightFinishedMessage.h"

void AllianceFightFinishedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightFinishedMessage(output);
}

void AllianceFightFinishedMessage::serializeAs_AllianceFightFinishedMessage(Writer *output)
{
  this->allianceFightInfo.serializeAs_SocialFightInfo(output);
}

void AllianceFightFinishedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightFinishedMessage(input);
}

void AllianceFightFinishedMessage::deserializeAs_AllianceFightFinishedMessage(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserialize(input);
}

void AllianceFightFinishedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightFinishedMessage(tree);
}

void AllianceFightFinishedMessage::deserializeAsyncAs_AllianceFightFinishedMessage(FuncTree tree)
{
  this->_allianceFightInfotree = tree.addChild(std::bind(&AllianceFightFinishedMessage::_allianceFightInfotreeFunc, this, std::placeholders::_1));
}

void AllianceFightFinishedMessage::_allianceFightInfotreeFunc(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserializeAsync(this->_allianceFightInfotree);
}

AllianceFightFinishedMessage::AllianceFightFinishedMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTFINISHEDMESSAGE;
}

