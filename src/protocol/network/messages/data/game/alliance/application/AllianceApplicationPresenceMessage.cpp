#include "AllianceApplicationPresenceMessage.h"

void AllianceApplicationPresenceMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceApplicationPresenceMessage(output);
}

void AllianceApplicationPresenceMessage::serializeAs_AllianceApplicationPresenceMessage(Writer *output)
{
  output->writeBool(this->isApplication);
}

void AllianceApplicationPresenceMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceApplicationPresenceMessage(input);
}

void AllianceApplicationPresenceMessage::deserializeAs_AllianceApplicationPresenceMessage(Reader *input)
{
  this->_isApplicationFunc(input);
}

void AllianceApplicationPresenceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceApplicationPresenceMessage(tree);
}

void AllianceApplicationPresenceMessage::deserializeAsyncAs_AllianceApplicationPresenceMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceApplicationPresenceMessage::_isApplicationFunc, this, std::placeholders::_1));
}

void AllianceApplicationPresenceMessage::_isApplicationFunc(Reader *input)
{
  this->isApplication = input->readBool();
}

AllianceApplicationPresenceMessage::AllianceApplicationPresenceMessage()
{
  m_type = MessageEnum::ALLIANCEAPPLICATIONPRESENCEMESSAGE;
}

