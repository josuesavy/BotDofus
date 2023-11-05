#include "HumanOptionFollowers.h"

void HumanOptionFollowers::serialize(Writer *output)
{
  this->serializeAs_HumanOptionFollowers(output);
}

void HumanOptionFollowers::serializeAs_HumanOptionFollowers(Writer *output)
{
  HumanOption::serializeAs_HumanOption(output);
  output->writeShort((short)this->followingCharactersLook.size());
  for(uint _i1 = 0; _i1 < this->followingCharactersLook.size(); _i1++)
  {
    (this->followingCharactersLook[_i1]).serializeAs_IndexedEntityLook(output);
  }
}

void HumanOptionFollowers::deserialize(Reader *input)
{
  this->deserializeAs_HumanOptionFollowers(input);
}

void HumanOptionFollowers::deserializeAs_HumanOptionFollowers(Reader *input)
{
  IndexedEntityLook _item1 ;
  HumanOption::deserialize(input);
  uint _followingCharactersLookLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _followingCharactersLookLen; _i1++)
  {
    _item1 = IndexedEntityLook();
    _item1.deserialize(input);
    this->followingCharactersLook.append(_item1);
  }
}

void HumanOptionFollowers::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanOptionFollowers(tree);
}

void HumanOptionFollowers::deserializeAsyncAs_HumanOptionFollowers(FuncTree tree)
{
  HumanOption::deserializeAsync(tree);
  this->_followingCharactersLooktree = tree.addChild(std::bind(&HumanOptionFollowers::_followingCharactersLooktreeFunc, this, std::placeholders::_1));
}

void HumanOptionFollowers::_followingCharactersLooktreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_followingCharactersLooktree.addChild(std::bind(&HumanOptionFollowers::_followingCharactersLookFunc, this, std::placeholders::_1));
  }
}

void HumanOptionFollowers::_followingCharactersLookFunc(Reader *input)
{
  IndexedEntityLook _item = IndexedEntityLook();
  _item.deserialize(input);
  this->followingCharactersLook.append(_item);
}

HumanOptionFollowers::HumanOptionFollowers()
{
  m_types<<ClassEnum::HUMANOPTIONFOLLOWERS;
}

bool HumanOptionFollowers::operator==(const HumanOptionFollowers &compared)
{
  if(followingCharactersLook == compared.followingCharactersLook)
  if(_followingCharactersLooktree == compared._followingCharactersLooktree)
  return true;
  
  return false;
}

