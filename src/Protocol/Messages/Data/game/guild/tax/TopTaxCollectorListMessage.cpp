#include "TopTaxCollectorListMessage.h"

void TopTaxCollectorListMessage::serialize(Writer *output)
{
  this->serializeAs_TopTaxCollectorListMessage(output);
}

void TopTaxCollectorListMessage::serializeAs_TopTaxCollectorListMessage(Writer *output)
{
  AbstractTaxCollectorListMessage::serializeAs_AbstractTaxCollectorListMessage(output);
  output->writeBool(this->isDungeon);
}

void TopTaxCollectorListMessage::deserialize(Reader *input)
{
  this->deserializeAs_TopTaxCollectorListMessage(input);
}

void TopTaxCollectorListMessage::deserializeAs_TopTaxCollectorListMessage(Reader *input)
{
  AbstractTaxCollectorListMessage::deserialize(input);
  this->_isDungeonFunc(input);
}

void TopTaxCollectorListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TopTaxCollectorListMessage(tree);
}

void TopTaxCollectorListMessage::deserializeAsyncAs_TopTaxCollectorListMessage(FuncTree tree)
{
  AbstractTaxCollectorListMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&TopTaxCollectorListMessage::_isDungeonFunc, this, std::placeholders::_1));
}

void TopTaxCollectorListMessage::_isDungeonFunc(Reader *input)
{
  this->isDungeon = input->readBool();
}

TopTaxCollectorListMessage::TopTaxCollectorListMessage()
{
  m_type = MessageEnum::TOPTAXCOLLECTORLISTMESSAGE;
}

