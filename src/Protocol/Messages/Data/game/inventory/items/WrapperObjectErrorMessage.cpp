#include "WrapperObjectErrorMessage.h"

void WrapperObjectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_WrapperObjectErrorMessage(output);
}

void WrapperObjectErrorMessage::serializeAs_WrapperObjectErrorMessage(Writer *output)
{
  SymbioticObjectErrorMessage::serializeAs_SymbioticObjectErrorMessage(output);
}

void WrapperObjectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_WrapperObjectErrorMessage(input);
}

void WrapperObjectErrorMessage::deserializeAs_WrapperObjectErrorMessage(Reader *input)
{
  SymbioticObjectErrorMessage::deserialize(input);
}

void WrapperObjectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_WrapperObjectErrorMessage(tree);
}

void WrapperObjectErrorMessage::deserializeAsyncAs_WrapperObjectErrorMessage(FuncTree tree)
{
  SymbioticObjectErrorMessage::deserializeAsync(tree);
}

WrapperObjectErrorMessage::WrapperObjectErrorMessage()
{
  m_type = MessageEnum::WRAPPEROBJECTERRORMESSAGE;
}

