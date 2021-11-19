#include "EntityInformationMessage.h"

void EntityInformationMessage::serialize(Writer *output)
{
  this->serializeAs_EntityInformationMessage(output);
}

void EntityInformationMessage::serializeAs_EntityInformationMessage(Writer *output)
{
  this->entity.serializeAs_EntityInformation(output);
}

void EntityInformationMessage::deserialize(Reader *input)
{
  this->deserializeAs_EntityInformationMessage(input);
}

void EntityInformationMessage::deserializeAs_EntityInformationMessage(Reader *input)
{
  this->entity = EntityInformation();
  this->entity.deserialize(input);
}

void EntityInformationMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EntityInformationMessage(tree);
}

void EntityInformationMessage::deserializeAsyncAs_EntityInformationMessage(FuncTree tree)
{
  this->_entitytree = tree.addChild(std::bind(&EntityInformationMessage::_entitytreeFunc, this, std::placeholders::_1));
}

void EntityInformationMessage::_entitytreeFunc(Reader *input)
{
  this->entity = EntityInformation();
  this->entity.deserializeAsync(this->_entitytree);
}

EntityInformationMessage::EntityInformationMessage()
{
  m_type = MessageEnum::ENTITYINFORMATIONMESSAGE;
}

