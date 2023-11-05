#include "PaddockPropertiesMessage.h"

void PaddockPropertiesMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockPropertiesMessage(output);
}

void PaddockPropertiesMessage::serializeAs_PaddockPropertiesMessage(Writer *output)
{
  this->properties.serializeAs_PaddockInstancesInformations(output);
}

void PaddockPropertiesMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockPropertiesMessage(input);
}

void PaddockPropertiesMessage::deserializeAs_PaddockPropertiesMessage(Reader *input)
{
  this->properties = PaddockInstancesInformations();
  this->properties.deserialize(input);
}

void PaddockPropertiesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockPropertiesMessage(tree);
}

void PaddockPropertiesMessage::deserializeAsyncAs_PaddockPropertiesMessage(FuncTree tree)
{
  this->_propertiestree = tree.addChild(std::bind(&PaddockPropertiesMessage::_propertiestreeFunc, this, std::placeholders::_1));
}

void PaddockPropertiesMessage::_propertiestreeFunc(Reader *input)
{
  this->properties = PaddockInstancesInformations();
  this->properties.deserializeAsync(this->_propertiestree);
}

PaddockPropertiesMessage::PaddockPropertiesMessage()
{
  m_type = MessageEnum::PADDOCKPROPERTIESMESSAGE;
}

