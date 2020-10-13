#include "InteractiveElement.h"

void InteractiveElement::serialize(Writer *output)
{
  this->serializeAs_InteractiveElement(output);
}

void InteractiveElement::serializeAs_InteractiveElement(Writer *output)
{
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElement -"<<"Forbidden value (" << this->elementId << ") on element elementId.";
  }
  output->writeInt((int)this->elementId);
  output->writeInt((int)this->elementTypeId);
  output->writeShort((short)this->enabledSkills.size());
  for(uint _i3 = 0; _i3 < this->enabledSkills.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<InteractiveElementSkill>(this->enabledSkills[_i3])->getTypes().last());
    qSharedPointerCast<InteractiveElementSkill>(this->enabledSkills[_i3])->serialize(output);
  }
  output->writeShort((short)this->disabledSkills.size());
  for(uint _i4 = 0; _i4 < this->disabledSkills.size(); _i4++)
  {
    output->writeShort((short)qSharedPointerCast<InteractiveElementSkill>(this->disabledSkills[_i4])->getTypes().last());
    qSharedPointerCast<InteractiveElementSkill>(this->disabledSkills[_i4])->serialize(output);
  }
  output->writeBool(this->onCurrentMap);
}

void InteractiveElement::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveElement(input);
}

void InteractiveElement::deserializeAs_InteractiveElement(Reader *input)
{
  uint _id3 = 0;
  QSharedPointer<InteractiveElementSkill> _item3 ;
  uint _id4 = 0;
  QSharedPointer<InteractiveElementSkill> _item4 ;
  this->_elementIdFunc(input);
  this->_elementTypeIdFunc(input);
  uint _enabledSkillsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _enabledSkillsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->enabledSkills.append(_item3);
  }
  uint _disabledSkillsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _disabledSkillsLen; _i4++)
  {
    _id4 = input->readUShort();
    _item4 = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_id4));
    _item4->deserialize(input);
    this->disabledSkills.append(_item4);
  }
  this->_onCurrentMapFunc(input);
}

void InteractiveElement::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveElement(tree);
}

void InteractiveElement::deserializeAsyncAs_InteractiveElement(FuncTree tree)
{
  tree.addChild(std::bind(&InteractiveElement::_elementIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveElement::_elementTypeIdFunc, this, std::placeholders::_1));
  this->_enabledSkillstree = tree.addChild(std::bind(&InteractiveElement::_enabledSkillstreeFunc, this, std::placeholders::_1));
  this->_disabledSkillstree = tree.addChild(std::bind(&InteractiveElement::_disabledSkillstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&InteractiveElement::_onCurrentMapFunc, this, std::placeholders::_1));
}

void InteractiveElement::_elementIdFunc(Reader *input)
{
  this->elementId = input->readInt();
  if(this->elementId < 0)
  {
    qDebug()<<"ERREUR - InteractiveElement -"<<"Forbidden value (" << this->elementId << ") on element of InteractiveElement.elementId.";
  }
}

void InteractiveElement::_elementTypeIdFunc(Reader *input)
{
  this->elementTypeId = input->readInt();
}

void InteractiveElement::_enabledSkillstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_enabledSkillstree.addChild(std::bind(&InteractiveElement::_enabledSkillsFunc, this, std::placeholders::_1));
  }
}

void InteractiveElement::_enabledSkillsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<InteractiveElementSkill> _item = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->enabledSkills.append(_item);
}

void InteractiveElement::_disabledSkillstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_disabledSkillstree.addChild(std::bind(&InteractiveElement::_disabledSkillsFunc, this, std::placeholders::_1));
  }
}

void InteractiveElement::_disabledSkillsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<InteractiveElementSkill> _item = qSharedPointerCast<InteractiveElementSkill>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->disabledSkills.append(_item);
}

void InteractiveElement::_onCurrentMapFunc(Reader *input)
{
  this->onCurrentMap = input->readBool();
}

InteractiveElement::InteractiveElement()
{
  m_types<<ClassEnum::INTERACTIVEELEMENT;
}

bool InteractiveElement::operator==(const InteractiveElement &compared)
{
  if(elementId == compared.elementId)
  if(elementTypeId == compared.elementTypeId)
  if(enabledSkills == compared.enabledSkills)
  if(disabledSkills == compared.disabledSkills)
  if(onCurrentMap == compared.onCurrentMap)
  if(_enabledSkillstree == compared._enabledSkillstree)
  if(_disabledSkillstree == compared._disabledSkillstree)
  return true;
  
  return false;
}

