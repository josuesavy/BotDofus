#include "ObjectErrorMessage.h"

void ObjectErrorMessage::serialize(Writer *output)
{
  this->serializeAs_ObjectErrorMessage(output);
}

void ObjectErrorMessage::serializeAs_ObjectErrorMessage(Writer *output)
{
  output->writeByte(this->reason);
}

void ObjectErrorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ObjectErrorMessage(input);
}

void ObjectErrorMessage::deserializeAs_ObjectErrorMessage(Reader *input)
{
  this->_reasonFunc(input);
}

void ObjectErrorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ObjectErrorMessage(tree);
}

void ObjectErrorMessage::deserializeAsyncAs_ObjectErrorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ObjectErrorMessage::_reasonFunc, this, std::placeholders::_1));
}

void ObjectErrorMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
}

ObjectErrorMessage::ObjectErrorMessage()
{
  m_type = MessageEnum::OBJECTERRORMESSAGE;
}

