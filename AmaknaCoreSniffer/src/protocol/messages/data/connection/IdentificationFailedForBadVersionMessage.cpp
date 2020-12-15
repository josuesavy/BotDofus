#include "IdentificationFailedForBadVersionMessage.h"

void IdentificationFailedForBadVersionMessage::serialize(Writer *output)
{
  this->serializeAs_IdentificationFailedForBadVersionMessage(output);
}

void IdentificationFailedForBadVersionMessage::serializeAs_IdentificationFailedForBadVersionMessage(Writer *output)
{
  IdentificationFailedMessage::serializeAs_IdentificationFailedMessage(output);
  this->requiredVersion.serializeAs_Version(output);
}

void IdentificationFailedForBadVersionMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdentificationFailedForBadVersionMessage(input);
}

void IdentificationFailedForBadVersionMessage::deserializeAs_IdentificationFailedForBadVersionMessage(Reader *input)
{
  IdentificationFailedMessage::deserialize(input);
  this->requiredVersion = Version();
  this->requiredVersion.deserialize(input);
}

void IdentificationFailedForBadVersionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdentificationFailedForBadVersionMessage(tree);
}

void IdentificationFailedForBadVersionMessage::deserializeAsyncAs_IdentificationFailedForBadVersionMessage(FuncTree tree)
{
  IdentificationFailedMessage::deserializeAsync(tree);
  this->_requiredVersiontree = tree.addChild(std::bind(&IdentificationFailedForBadVersionMessage::_requiredVersiontreeFunc, this, std::placeholders::_1));
}

void IdentificationFailedForBadVersionMessage::_requiredVersiontreeFunc(Reader *input)
{
  this->requiredVersion = Version();
  this->requiredVersion.deserializeAsync(this->_requiredVersiontree);
}

IdentificationFailedForBadVersionMessage::IdentificationFailedForBadVersionMessage()
{
  m_type = MessageEnum::IDENTIFICATIONFAILEDFORBADVERSIONMESSAGE;
}

