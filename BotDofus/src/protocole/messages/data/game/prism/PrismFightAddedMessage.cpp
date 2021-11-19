#include "PrismFightAddedMessage.h"

void PrismFightAddedMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightAddedMessage(output);
}

void PrismFightAddedMessage::serializeAs_PrismFightAddedMessage(Writer *output)
{
  this->fight->serializeAs_PrismFightersInformation(output);
}

void PrismFightAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightAddedMessage(input);
}

void PrismFightAddedMessage::deserializeAs_PrismFightAddedMessage(Reader *input)
{
  this->fight = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
  this->fight->deserialize(input);
}

void PrismFightAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightAddedMessage(tree);
}

void PrismFightAddedMessage::deserializeAsyncAs_PrismFightAddedMessage(FuncTree tree)
{
  this->_fighttree = tree.addChild(std::bind(&PrismFightAddedMessage::_fighttreeFunc, this, std::placeholders::_1));
}

void PrismFightAddedMessage::_fighttreeFunc(Reader *input)
{
  this->fight = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
  this->fight->deserializeAsync(this->_fighttree);
}

PrismFightAddedMessage::PrismFightAddedMessage()
{
  m_type = MessageEnum::PRISMFIGHTADDEDMESSAGE;
}

