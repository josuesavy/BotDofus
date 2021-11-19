#include "BreachBranchesMessage.h"

void BreachBranchesMessage::serialize(Writer *output)
{
  this->serializeAs_BreachBranchesMessage(output);
}

void BreachBranchesMessage::serializeAs_BreachBranchesMessage(Writer *output)
{
  output->writeShort((short)this->branches.size());
  for(uint _i1 = 0; _i1 < this->branches.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<ExtendedBreachBranch>(this->branches[_i1])->getTypes().last());
    qSharedPointerCast<ExtendedBreachBranch>(this->branches[_i1])->serialize(output);
  }
}

void BreachBranchesMessage::deserialize(Reader *input)
{
  this->deserializeAs_BreachBranchesMessage(input);
}

void BreachBranchesMessage::deserializeAs_BreachBranchesMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<ExtendedBreachBranch> _item1 ;
  uint _branchesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _branchesLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<ExtendedBreachBranch>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->branches.append(_item1);
  }
}

void BreachBranchesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BreachBranchesMessage(tree);
}

void BreachBranchesMessage::deserializeAsyncAs_BreachBranchesMessage(FuncTree tree)
{
  this->_branchestree = tree.addChild(std::bind(&BreachBranchesMessage::_branchestreeFunc, this, std::placeholders::_1));
}

void BreachBranchesMessage::_branchestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_branchestree.addChild(std::bind(&BreachBranchesMessage::_branchesFunc, this, std::placeholders::_1));
  }
}

void BreachBranchesMessage::_branchesFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<ExtendedBreachBranch> _item = qSharedPointerCast<ExtendedBreachBranch>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->branches.append(_item);
}

BreachBranchesMessage::BreachBranchesMessage()
{
  m_type = MessageEnum::BREACHBRANCHESMESSAGE;
}

