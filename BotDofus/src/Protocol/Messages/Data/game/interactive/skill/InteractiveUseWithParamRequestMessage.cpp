#include "InteractiveUseWithParamRequestMessage.h"

void InteractiveUseWithParamRequestMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveUseWithParamRequestMessage(output);
}

void InteractiveUseWithParamRequestMessage::serializeAs_InteractiveUseWithParamRequestMessage(Writer *output)
{
  InteractiveUseRequestMessage::serializeAs_InteractiveUseRequestMessage(output);
  output->writeInt((int)this->id);
}

void InteractiveUseWithParamRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveUseWithParamRequestMessage(input);
}

void InteractiveUseWithParamRequestMessage::deserializeAs_InteractiveUseWithParamRequestMessage(Reader *input)
{
  InteractiveUseRequestMessage::deserialize(input);
  this->_idFunc(input);
}

void InteractiveUseWithParamRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveUseWithParamRequestMessage(tree);
}

void InteractiveUseWithParamRequestMessage::deserializeAsyncAs_InteractiveUseWithParamRequestMessage(FuncTree tree)
{
  InteractiveUseRequestMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&InteractiveUseWithParamRequestMessage::_idFunc, this, std::placeholders::_1));
}

void InteractiveUseWithParamRequestMessage::_idFunc(Reader *input)
{
  this->id = input->readInt();
}

InteractiveUseWithParamRequestMessage::InteractiveUseWithParamRequestMessage()
{
  m_type = MessageEnum::INTERACTIVEUSEWITHPARAMREQUESTMESSAGE;
  m_needsHash = true;
}

