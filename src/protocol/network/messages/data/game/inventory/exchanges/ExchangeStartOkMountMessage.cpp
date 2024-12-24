#include "ExchangeStartOkMountMessage.h"

void ExchangeStartOkMountMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkMountMessage(output);
}

void ExchangeStartOkMountMessage::serializeAs_ExchangeStartOkMountMessage(Writer *output)
{
  ExchangeStartOkMountWithOutPaddockMessage::serializeAs_ExchangeStartOkMountWithOutPaddockMessage(output);
  output->writeShort((short)this->paddockedMountsDescription.size());
  for(uint _i1 = 0; _i1 < this->paddockedMountsDescription.size(); _i1++)
  {
    qSharedPointerCast<MountClientData>(this->paddockedMountsDescription[_i1])->serializeAs_MountClientData(output);
  }
}

void ExchangeStartOkMountMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkMountMessage(input);
}

void ExchangeStartOkMountMessage::deserializeAs_ExchangeStartOkMountMessage(Reader *input)
{
  QSharedPointer<MountClientData> _item1 ;
  ExchangeStartOkMountWithOutPaddockMessage::deserialize(input);
  uint _paddockedMountsDescriptionLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _paddockedMountsDescriptionLen; _i1++)
  {
    _item1 = QSharedPointer<MountClientData>(new MountClientData() );
    _item1->deserialize(input);
    this->paddockedMountsDescription.append(_item1);
  }
}

void ExchangeStartOkMountMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkMountMessage(tree);
}

void ExchangeStartOkMountMessage::deserializeAsyncAs_ExchangeStartOkMountMessage(FuncTree tree)
{
  ExchangeStartOkMountWithOutPaddockMessage::deserializeAsync(tree);
  this->_paddockedMountsDescriptiontree = tree.addChild(std::bind(&ExchangeStartOkMountMessage::_paddockedMountsDescriptiontreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkMountMessage::_paddockedMountsDescriptiontreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_paddockedMountsDescriptiontree.addChild(std::bind(&ExchangeStartOkMountMessage::_paddockedMountsDescriptionFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkMountMessage::_paddockedMountsDescriptionFunc(Reader *input)
{
  QSharedPointer<MountClientData> _item = QSharedPointer<MountClientData>(new MountClientData() );
  _item->deserialize(input);
  this->paddockedMountsDescription.append(_item);
}

ExchangeStartOkMountMessage::ExchangeStartOkMountMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMOUNTMESSAGE;
}

