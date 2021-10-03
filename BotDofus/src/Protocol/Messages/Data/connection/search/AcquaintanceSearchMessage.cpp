#include "AcquaintanceSearchMessage.h"

void AcquaintanceSearchMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintanceSearchMessage(output);
}

void AcquaintanceSearchMessage::serializeAs_AcquaintanceSearchMessage(Writer *output)
{
  this->tag.serializeAs_AccountTagInformation(output);
}

void AcquaintanceSearchMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintanceSearchMessage(input);
}

void AcquaintanceSearchMessage::deserializeAs_AcquaintanceSearchMessage(Reader *input)
{
  this->tag = AccountTagInformation();
  this->tag.deserialize(input);
}

void AcquaintanceSearchMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintanceSearchMessage(tree);
}

void AcquaintanceSearchMessage::deserializeAsyncAs_AcquaintanceSearchMessage(FuncTree tree)
{
  this->_tagtree = tree.addChild(std::bind(&AcquaintanceSearchMessage::_tagtreeFunc, this, std::placeholders::_1));
}

void AcquaintanceSearchMessage::_tagtreeFunc(Reader *input)
{
  this->tag = AccountTagInformation();
  this->tag.deserializeAsync(this->_tagtree);
}

AcquaintanceSearchMessage::AcquaintanceSearchMessage()
{
  m_type = MessageEnum::ACQUAINTANCESEARCHMESSAGE;
}

