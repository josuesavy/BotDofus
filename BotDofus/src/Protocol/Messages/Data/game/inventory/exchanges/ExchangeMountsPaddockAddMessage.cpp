#include "ExchangeMountsPaddockAddMessage.h"

void ExchangeMountsPaddockAddMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsPaddockAddMessage(output);
}

void ExchangeMountsPaddockAddMessage::serializeAs_ExchangeMountsPaddockAddMessage(Writer *output)
{
  output->writeShort((short)this->mountDescription.size());
  for(uint _i1 = 0; _i1 < this->mountDescription.size(); _i1++)
  {
    qSharedPointerCast<MountClientData>(this->mountDescription[_i1])->serializeAs_MountClientData(output);
  }
}

void ExchangeMountsPaddockAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsPaddockAddMessage(input);
}

void ExchangeMountsPaddockAddMessage::deserializeAs_ExchangeMountsPaddockAddMessage(Reader *input)
{
  QSharedPointer<MountClientData> _item1 ;
  uint _mountDescriptionLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _mountDescriptionLen; _i1++)
  {
    _item1 = QSharedPointer<MountClientData>(new MountClientData() );
    _item1->deserialize(input);
    this->mountDescription.append(_item1);
  }
}

void ExchangeMountsPaddockAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsPaddockAddMessage(tree);
}

void ExchangeMountsPaddockAddMessage::deserializeAsyncAs_ExchangeMountsPaddockAddMessage(FuncTree tree)
{
  this->_mountDescriptiontree = tree.addChild(std::bind(&ExchangeMountsPaddockAddMessage::_mountDescriptiontreeFunc, this, std::placeholders::_1));
}

void ExchangeMountsPaddockAddMessage::_mountDescriptiontreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_mountDescriptiontree.addChild(std::bind(&ExchangeMountsPaddockAddMessage::_mountDescriptionFunc, this, std::placeholders::_1));
  }
}

void ExchangeMountsPaddockAddMessage::_mountDescriptionFunc(Reader *input)
{
  QSharedPointer<MountClientData> _item = QSharedPointer<MountClientData>(new MountClientData() );
  _item->deserialize(input);
  this->mountDescription.append(_item);
}

ExchangeMountsPaddockAddMessage::ExchangeMountsPaddockAddMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSPADDOCKADDMESSAGE;
}

