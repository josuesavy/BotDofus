#include "AllianceFightPhaseUpdateMessage.h"

void AllianceFightPhaseUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightPhaseUpdateMessage(output);
}

void AllianceFightPhaseUpdateMessage::serializeAs_AllianceFightPhaseUpdateMessage(Writer *output)
{
  this->allianceFightInfo.serializeAs_SocialFightInfo(output);
  this->newPhase.serializeAs_FightPhase(output);
}

void AllianceFightPhaseUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightPhaseUpdateMessage(input);
}

void AllianceFightPhaseUpdateMessage::deserializeAs_AllianceFightPhaseUpdateMessage(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserialize(input);
  this->newPhase = FightPhase();
  this->newPhase.deserialize(input);
}

void AllianceFightPhaseUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightPhaseUpdateMessage(tree);
}

void AllianceFightPhaseUpdateMessage::deserializeAsyncAs_AllianceFightPhaseUpdateMessage(FuncTree tree)
{
  this->_allianceFightInfotree = tree.addChild(std::bind(&AllianceFightPhaseUpdateMessage::_allianceFightInfotreeFunc, this, std::placeholders::_1));
  this->_newPhasetree = tree.addChild(std::bind(&AllianceFightPhaseUpdateMessage::_newPhasetreeFunc, this, std::placeholders::_1));
}

void AllianceFightPhaseUpdateMessage::_allianceFightInfotreeFunc(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserializeAsync(this->_allianceFightInfotree);
}

void AllianceFightPhaseUpdateMessage::_newPhasetreeFunc(Reader *input)
{
  this->newPhase = FightPhase();
  this->newPhase.deserializeAsync(this->_newPhasetree);
}

AllianceFightPhaseUpdateMessage::AllianceFightPhaseUpdateMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTPHASEUPDATEMESSAGE;
}

