#include "AllianceModificationStartedMessage.h"

void AllianceModificationStartedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceModificationStartedMessage(output);
}

void AllianceModificationStartedMessage::serializeAs_AllianceModificationStartedMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->canChangeName);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->canChangeTag);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->canChangeEmblem);
  output->writeByte(_box0);
}

void AllianceModificationStartedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceModificationStartedMessage(input);
}

void AllianceModificationStartedMessage::deserializeAs_AllianceModificationStartedMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void AllianceModificationStartedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceModificationStartedMessage(tree);
}

void AllianceModificationStartedMessage::deserializeAsyncAs_AllianceModificationStartedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&AllianceModificationStartedMessage::deserializeByteBoxes, this, std::placeholders::_1));
}

void AllianceModificationStartedMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = input->readByte();
  this->canChangeName = BooleanByteWrapper::getFlag(_box0, 0);
  this->canChangeTag = BooleanByteWrapper::getFlag(_box0, 1);
  this->canChangeEmblem = BooleanByteWrapper::getFlag(_box0, 2);
}

AllianceModificationStartedMessage::AllianceModificationStartedMessage()
{
  m_type = MessageEnum::ALLIANCEMODIFICATIONSTARTEDMESSAGE;
}

