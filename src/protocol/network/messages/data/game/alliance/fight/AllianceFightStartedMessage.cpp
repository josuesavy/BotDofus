#include "AllianceFightStartedMessage.h"

void AllianceFightStartedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightStartedMessage(output);
}

void AllianceFightStartedMessage::serializeAs_AllianceFightStartedMessage(Writer *output)
{
  this->allianceFightInfo.serializeAs_SocialFightInfo(output);
  this->phase.serializeAs_FightPhase(output);
}

void AllianceFightStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightStartedMessage(input);
}

void AllianceFightStartedMessage::deserializeAs_AllianceFightStartedMessage(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserialize(input);
  this->phase = FightPhase();
  this->phase.deserialize(input);
}

void AllianceFightStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightStartedMessage(tree);
}

void AllianceFightStartedMessage::deserializeAsyncAs_AllianceFightStartedMessage(FuncTree tree)
{
  this->_allianceFightInfotree = tree.addChild(std::bind(&AllianceFightStartedMessage::_allianceFightInfotreeFunc, this, std::placeholders::_1));
  this->_phasetree = tree.addChild(std::bind(&AllianceFightStartedMessage::_phasetreeFunc, this, std::placeholders::_1));
}

void AllianceFightStartedMessage::_allianceFightInfotreeFunc(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserializeAsync(this->_allianceFightInfotree);
}

void AllianceFightStartedMessage::_phasetreeFunc(Reader *input)
{
  this->phase = FightPhase();
  this->phase.deserializeAsync(this->_phasetree);
}

AllianceFightStartedMessage::AllianceFightStartedMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTSTARTEDMESSAGE;
}

