#include "KothEndMessage.h"

void KothEndMessage::serialize(Writer *output)
{
  this->serializeAs_KothEndMessage(output);
}

void KothEndMessage::serializeAs_KothEndMessage(Writer *output)
{
  this->winner.serializeAs_KothWinner(output);
}

void KothEndMessage::deserialize(Reader *input)
{
  this->deserializeAs_KothEndMessage(input);
}

void KothEndMessage::deserializeAs_KothEndMessage(Reader *input)
{
  this->winner = KothWinner();
  this->winner.deserialize(input);
}

void KothEndMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KothEndMessage(tree);
}

void KothEndMessage::deserializeAsyncAs_KothEndMessage(FuncTree tree)
{
  this->_winnertree = tree.addChild(std::bind(&KothEndMessage::_winnertreeFunc, this, std::placeholders::_1));
}

void KothEndMessage::_winnertreeFunc(Reader *input)
{
  this->winner = KothWinner();
  this->winner.deserializeAsync(this->_winnertree);
}

KothEndMessage::KothEndMessage()
{
  m_type = MessageEnum::KOTHENDMESSAGE;
}

