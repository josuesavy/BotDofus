#include "InteractiveMapUpdateMessage.h"

void InteractiveMapUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_InteractiveMapUpdateMessage(output);
}

void InteractiveMapUpdateMessage::serializeAs_InteractiveMapUpdateMessage(Writer *output)
{
  output->writeShort((short)this->interactiveElements.size());
  for(uint _i1 = 0; _i1 < this->interactiveElements.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<InteractiveElement>(this->interactiveElements[_i1])->getTypes().last());
    qSharedPointerCast<InteractiveElement>(this->interactiveElements[_i1])->serialize(output);
  }
}

void InteractiveMapUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_InteractiveMapUpdateMessage(input);
}

void InteractiveMapUpdateMessage::deserializeAs_InteractiveMapUpdateMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<InteractiveElement> _item1 ;
  uint _interactiveElementsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _interactiveElementsLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->interactiveElements.append(_item1);
  }
}

void InteractiveMapUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_InteractiveMapUpdateMessage(tree);
}

void InteractiveMapUpdateMessage::deserializeAsyncAs_InteractiveMapUpdateMessage(FuncTree tree)
{
  this->_interactiveElementstree = tree.addChild(std::bind(&InteractiveMapUpdateMessage::_interactiveElementstreeFunc, this, std::placeholders::_1));
}

void InteractiveMapUpdateMessage::_interactiveElementstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_interactiveElementstree.addChild(std::bind(&InteractiveMapUpdateMessage::_interactiveElementsFunc, this, std::placeholders::_1));
  }
}

void InteractiveMapUpdateMessage::_interactiveElementsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<InteractiveElement> _item = qSharedPointerCast<InteractiveElement>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->interactiveElements.append(_item);
}

InteractiveMapUpdateMessage::InteractiveMapUpdateMessage()
{
  m_type = MessageEnum::INTERACTIVEMAPUPDATEMESSAGE;
}

