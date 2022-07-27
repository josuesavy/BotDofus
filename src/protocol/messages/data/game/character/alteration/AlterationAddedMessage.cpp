#include "AlterationAddedMessage.h"

void AlterationAddedMessage::serialize(Writer *output)
{
  this->serializeAs_AlterationAddedMessage(output);
}

void AlterationAddedMessage::serializeAs_AlterationAddedMessage(Writer *output)
{
  this->alteration->serializeAs_AlterationInfo(output);
}

void AlterationAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlterationAddedMessage(input);
}

void AlterationAddedMessage::deserializeAs_AlterationAddedMessage(Reader *input)
{
  this->alteration = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  this->alteration->deserialize(input);
}

void AlterationAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlterationAddedMessage(tree);
}

void AlterationAddedMessage::deserializeAsyncAs_AlterationAddedMessage(FuncTree tree)
{
  this->_alterationtree = tree.addChild(std::bind(&AlterationAddedMessage::_alterationtreeFunc, this, std::placeholders::_1));
}

void AlterationAddedMessage::_alterationtreeFunc(Reader *input)
{
  this->alteration = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  this->alteration->deserializeAsync(this->_alterationtree);
}

AlterationAddedMessage::AlterationAddedMessage()
{
  m_type = MessageEnum::ALTERATIONADDEDMESSAGE;
}

