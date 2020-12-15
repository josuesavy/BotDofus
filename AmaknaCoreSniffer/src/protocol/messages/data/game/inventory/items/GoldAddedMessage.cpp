#include "GoldAddedMessage.h"

void GoldAddedMessage::serialize(Writer *output)
{
  this->serializeAs_GoldAddedMessage(output);
}

void GoldAddedMessage::serializeAs_GoldAddedMessage(Writer *output)
{
  this->gold.serializeAs_GoldItem(output);
}

void GoldAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_GoldAddedMessage(input);
}

void GoldAddedMessage::deserializeAs_GoldAddedMessage(Reader *input)
{
  this->gold = GoldItem();
  this->gold.deserialize(input);
}

void GoldAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GoldAddedMessage(tree);
}

void GoldAddedMessage::deserializeAsyncAs_GoldAddedMessage(FuncTree tree)
{
  this->_goldtree = tree.addChild(std::bind(&GoldAddedMessage::_goldtreeFunc, this, std::placeholders::_1));
}

void GoldAddedMessage::_goldtreeFunc(Reader *input)
{
  this->gold = GoldItem();
  this->gold.deserializeAsync(this->_goldtree);
}

GoldAddedMessage::GoldAddedMessage()
{
  m_type = MessageEnum::GOLDADDEDMESSAGE;
}

