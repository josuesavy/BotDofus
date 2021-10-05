#include "MountHarnessColorsUpdateRequestMessage.h"

void MountHarnessColorsUpdateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_MountHarnessColorsUpdateRequestMessage(output);
}

void MountHarnessColorsUpdateRequestMessage::serializeAs_MountHarnessColorsUpdateRequestMessage(Writer *output)
{
  output->writeBool(this->useHarnessColors);
}

void MountHarnessColorsUpdateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_MountHarnessColorsUpdateRequestMessage(input);
}

void MountHarnessColorsUpdateRequestMessage::deserializeAs_MountHarnessColorsUpdateRequestMessage(Reader *input)
{
  this->_useHarnessColorsFunc(input);
}

void MountHarnessColorsUpdateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MountHarnessColorsUpdateRequestMessage(tree);
}

void MountHarnessColorsUpdateRequestMessage::deserializeAsyncAs_MountHarnessColorsUpdateRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&MountHarnessColorsUpdateRequestMessage::_useHarnessColorsFunc, this, std::placeholders::_1));
}

void MountHarnessColorsUpdateRequestMessage::_useHarnessColorsFunc(Reader *input)
{
  this->useHarnessColors = input->readBool();
}

MountHarnessColorsUpdateRequestMessage::MountHarnessColorsUpdateRequestMessage()
{
  m_type = MessageEnum::MOUNTHARNESSCOLORSUPDATEREQUESTMESSAGE;
}

