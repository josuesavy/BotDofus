#include "AtlasPointInformationsMessage.h"

void AtlasPointInformationsMessage::serialize(Writer *output)
{
  this->serializeAs_AtlasPointInformationsMessage(output);
}

void AtlasPointInformationsMessage::serializeAs_AtlasPointInformationsMessage(Writer *output)
{
  this->type->serializeAs_AtlasPointsInformations(output);
}

void AtlasPointInformationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AtlasPointInformationsMessage(input);
}

void AtlasPointInformationsMessage::deserializeAs_AtlasPointInformationsMessage(Reader *input)
{
  this->type = QSharedPointer<AtlasPointsInformations>(new AtlasPointsInformations() );
  this->type->deserialize(input);
}

void AtlasPointInformationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AtlasPointInformationsMessage(tree);
}

void AtlasPointInformationsMessage::deserializeAsyncAs_AtlasPointInformationsMessage(FuncTree tree)
{
  this->_typetree = tree.addChild(std::bind(&AtlasPointInformationsMessage::_typetreeFunc, this, std::placeholders::_1));
}

void AtlasPointInformationsMessage::_typetreeFunc(Reader *input)
{
  this->type = QSharedPointer<AtlasPointsInformations>(new AtlasPointsInformations() );
  this->type->deserializeAsync(this->_typetree);
}

AtlasPointInformationsMessage::AtlasPointInformationsMessage()
{
  m_type = MessageEnum::ATLASPOINTINFORMATIONSMESSAGE;
}

