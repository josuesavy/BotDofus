#include "ExchangeMountsStableAddMessage.h"

void ExchangeMountsStableAddMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeMountsStableAddMessage(output);
}

void ExchangeMountsStableAddMessage::serializeAs_ExchangeMountsStableAddMessage(Writer *output)
{
  output->writeShort((short)this->mountDescription.size());
  for(uint _i1 = 0; _i1 < this->mountDescription.size(); _i1++)
  {
    qSharedPointerCast<MountClientData>(this->mountDescription[_i1])->serializeAs_MountClientData(output);
  }
}

void ExchangeMountsStableAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeMountsStableAddMessage(input);
}

void ExchangeMountsStableAddMessage::deserializeAs_ExchangeMountsStableAddMessage(Reader *input)
{
  QSharedPointer<MountClientData> _item1 ;
  uint _mountDescriptionLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _mountDescriptionLen; _i1++)
  {
    _item1 = QSharedPointer<MountClientData>(new MountClientData() );
    _item1->deserialize(input);
    this->mountDescription.append(_item1);
  }
}

void ExchangeMountsStableAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeMountsStableAddMessage(tree);
}

void ExchangeMountsStableAddMessage::deserializeAsyncAs_ExchangeMountsStableAddMessage(FuncTree tree)
{
  this->_mountDescriptiontree = tree.addChild(std::bind(&ExchangeMountsStableAddMessage::_mountDescriptiontreeFunc, this, std::placeholders::_1));
}

void ExchangeMountsStableAddMessage::_mountDescriptiontreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_mountDescriptiontree.addChild(std::bind(&ExchangeMountsStableAddMessage::_mountDescriptionFunc, this, std::placeholders::_1));
  }
}

void ExchangeMountsStableAddMessage::_mountDescriptionFunc(Reader *input)
{
  QSharedPointer<MountClientData> _item = QSharedPointer<MountClientData>(new MountClientData() );
  _item->deserialize(input);
  this->mountDescription.append(_item);
}

ExchangeMountsStableAddMessage::ExchangeMountsStableAddMessage()
{
  m_type = MessageEnum::EXCHANGEMOUNTSSTABLEADDMESSAGE;
}

