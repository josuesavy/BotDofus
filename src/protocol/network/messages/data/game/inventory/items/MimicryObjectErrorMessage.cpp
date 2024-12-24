#include "MimicryObjectErrorMessage.h"

void MimicryObjectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_MimicryObjectErrorMessage(output);
}

void MimicryObjectErrorMessage::serializeAs_MimicryObjectErrorMessage(Writer *output)
{
  SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(output);
  output->writeBool(this->preview);
}

void MimicryObjectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_MimicryObjectErrorMessage(input);
}

void MimicryObjectErrorMessage::deserializeAs_MimicryObjectErrorMessage(Reader *input)
{
  SymbioticObjectErrorMessage::deserialize(input);
  this->_previewFunc(input);
}

void MimicryObjectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_MimicryObjectErrorMessage(tree);
}

void MimicryObjectErrorMessage::deserializeAsyncAs_MimicryObjectErrorMessage(FuncTree tree)
{
  SymbioticObjectErrorMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&MimicryObjectErrorMessage::_previewFunc, this, std::placeholders::_1));
}

void MimicryObjectErrorMessage::_previewFunc(Reader *input)
{
  this->preview = input->readBool();
}

MimicryObjectErrorMessage::MimicryObjectErrorMessage()
{
  m_type = MessageEnum::MIMICRYOBJECTERRORMESSAGE;
}

