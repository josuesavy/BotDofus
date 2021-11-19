#include "SymbioticObjectErrorMessage.h"

void SymbioticObjectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_SymbioticObjectErrorMessage(output);
}

void SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(Writer *output)
{
  ObjectErrorMessage::serializeAs_ObjectErrorMessage(output);
  output->writeByte(this->errorCode);
}

void SymbioticObjectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_SymbioticObjectErrorMessage(input);
}

void SymbioticObjectErrorMessage::deserializeAs_SymbioticObjectErrorMessage(Reader *input)
{
  ObjectErrorMessage::deserialize(input);
  this->_errorCodeFunc(input);
}

void SymbioticObjectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SymbioticObjectErrorMessage(tree);
}

void SymbioticObjectErrorMessage::deserializeAsyncAs_SymbioticObjectErrorMessage(FuncTree tree)
{
  ObjectErrorMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&SymbioticObjectErrorMessage::_errorCodeFunc, this, std::placeholders::_1));
}

void SymbioticObjectErrorMessage::_errorCodeFunc(Reader *input)
{
  this->errorCode = input->readByte();
}

SymbioticObjectErrorMessage::SymbioticObjectErrorMessage()
{
  m_type = MessageEnum::SYMBIOTICOBJECTERRORMESSAGE;
}

