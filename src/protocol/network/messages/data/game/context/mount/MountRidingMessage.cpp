#include "MountRidingMessage.h"

void MountRidingMessage::serialize(Writer *output)
{
  this->serializeAs_MountRidingMessage(output);
}

void MountRidingMessage::serializeAs_MountRidingMessage(Writer *output)
{
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->isRiding);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->isAutopilot);
  output->writeByte(_box0);
}

void MountRidingMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountRidingMessage(input);
}

void MountRidingMessage::deserializeAs_MountRidingMessage(Reader *input)
{
  this->deserializeByteBoxes(input);
}

void MountRidingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountRidingMessage(tree);
}

void MountRidingMessage::deserializeAsyncAs_MountRidingMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountRidingMessage::deserializeByteBoxes, this, std::placeholders::_1));
}

void MountRidingMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->isRiding = BooleanByteWrapper::getFlag(_box0, 0);
  this->isAutopilot = BooleanByteWrapper::getFlag(_box0, 1);
}

MountRidingMessage::MountRidingMessage()
{
  m_type = MessageEnum::MOUNTRIDINGMESSAGE;
}

