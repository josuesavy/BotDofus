#include "PlayerSearchTagInformation.h"

void PlayerSearchTagInformation::serialize(Writer *output)
{
  this->serializeAs_PlayerSearchTagInformation(output);
}

void PlayerSearchTagInformation::serializeAs_PlayerSearchTagInformation(Writer *output)
{
  AbstractPlayerSearchInformation::serializeAs_AbstractPlayerSearchInformation(output);
  this->tag.serializeAs_AccountTagInformation(output);
}

void PlayerSearchTagInformation::deserialize(Reader *input)
{
  this->deserializeAs_PlayerSearchTagInformation(input);
}

void PlayerSearchTagInformation::deserializeAs_PlayerSearchTagInformation(Reader *input)
{
  AbstractPlayerSearchInformation::deserialize(input);
  this->tag = AccountTagInformation();
  this->tag.deserialize(input);
}

void PlayerSearchTagInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerSearchTagInformation(tree);
}

void PlayerSearchTagInformation::deserializeAsyncAs_PlayerSearchTagInformation(FuncTree tree)
{
  AbstractPlayerSearchInformation::deserializeAsync(tree);
  this->_tagtree = tree.addChild(std::bind(&PlayerSearchTagInformation::_tagtreeFunc, this, std::placeholders::_1));
}

void PlayerSearchTagInformation::_tagtreeFunc(Reader *input)
{
  this->tag = AccountTagInformation();
  this->tag.deserializeAsync(this->_tagtree);
}

PlayerSearchTagInformation::PlayerSearchTagInformation()
{
  m_types<<ClassEnum::PLAYERSEARCHTAGINFORMATION;
}

bool PlayerSearchTagInformation::operator==(const PlayerSearchTagInformation &compared)
{
  if(tag == compared.tag)
  if(_tagtree == compared._tagtree)
  return true;
  
  return false;
}

