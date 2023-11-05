#include "HumanInformations.h"

void HumanInformations::serialize(Writer *output)
{
  this->serializeAs_HumanInformations(output);
}

void HumanInformations::serializeAs_HumanInformations(Writer *output)
{
  this->restrictions.serializeAs_ActorRestrictionsInformations(output);
  output->writeBool(this->sex);
  output->writeShort((short)this->options.size());
  for(uint _i3 = 0; _i3 < this->options.size(); _i3++)
  {
    output->writeShort((short)(this->options[_i3]).getTypeId());
    (this->options[_i3]).serialize(output);
  }
}

void HumanInformations::deserialize(Reader *input)
{
  this->deserializeAs_HumanInformations(input);
}

void HumanInformations::deserializeAs_HumanInformations(Reader *input)
{
  uint _id3 = 0;
   _item3 ;
  this->restrictions = ActorRestrictionsInformations();
  this->restrictions.deserialize(input);
  this->_sexFunc(input);
  uint _optionsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _optionsLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id3));
    _item3.deserialize(input);
    this->options.append(_item3);
  }
}

void HumanInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HumanInformations(tree);
}

void HumanInformations::deserializeAsyncAs_HumanInformations(FuncTree tree)
{
  this->_restrictionstree = tree.addChild(std::bind(&HumanInformations::_restrictionstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HumanInformations::_sexFunc, this, std::placeholders::_1));
  this->_optionstree = tree.addChild(std::bind(&HumanInformations::_optionstreeFunc, this, std::placeholders::_1));
}

void HumanInformations::_restrictionstreeFunc(Reader *input)
{
  this->restrictions = ActorRestrictionsInformations();
  this->restrictions.deserializeAsync(this->_restrictionstree);
}

void HumanInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void HumanInformations::_optionstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_optionstree.addChild(std::bind(&HumanInformations::_optionsFunc, this, std::placeholders::_1));
  }
}

void HumanInformations::_optionsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
   _item = qSharedPointerCast<>(ClassManagerSingleton::get()->getClass(_id));
  _item.deserialize(input);
  this->options.append(_item);
}

HumanInformations::HumanInformations()
{
  m_types<<ClassEnum::HUMANINFORMATIONS;
}

bool HumanInformations::operator==(const HumanInformations &compared)
{
  if(restrictions == compared.restrictions)
  if(sex == compared.sex)
  if(options == compared.options)
  if(_restrictionstree == compared._restrictionstree)
  if(_optionstree == compared._optionstree)
  return true;
  
  return false;
}

