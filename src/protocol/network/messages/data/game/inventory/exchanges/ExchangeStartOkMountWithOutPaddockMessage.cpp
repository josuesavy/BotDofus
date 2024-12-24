#include "ExchangeStartOkMountWithOutPaddockMessage.h"

void ExchangeStartOkMountWithOutPaddockMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeStartOkMountWithOutPaddockMessage(output);
}

void ExchangeStartOkMountWithOutPaddockMessage::serializeAs_ExchangeStartOkMountWithOutPaddockMessage(Writer *output)
{
  output->writeShort((short)this->stabledMountsDescription.size());
  for(uint _i1 = 0; _i1 < this->stabledMountsDescription.size(); _i1++)
  {
    qSharedPointerCast<MountClientData>(this->stabledMountsDescription[_i1])->serializeAs_MountClientData(output);
  }
}

void ExchangeStartOkMountWithOutPaddockMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(input);
}

void ExchangeStartOkMountWithOutPaddockMessage::deserializeAs_ExchangeStartOkMountWithOutPaddockMessage(Reader *input)
{
  QSharedPointer<MountClientData> _item1 ;
  uint _stabledMountsDescriptionLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _stabledMountsDescriptionLen; _i1++)
  {
    _item1 = QSharedPointer<MountClientData>(new MountClientData() );
    _item1->deserialize(input);
    this->stabledMountsDescription.append(_item1);
  }
}

void ExchangeStartOkMountWithOutPaddockMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeStartOkMountWithOutPaddockMessage(tree);
}

void ExchangeStartOkMountWithOutPaddockMessage::deserializeAsyncAs_ExchangeStartOkMountWithOutPaddockMessage(FuncTree tree)
{
  this->_stabledMountsDescriptiontree = tree.addChild(std::bind(&ExchangeStartOkMountWithOutPaddockMessage::_stabledMountsDescriptiontreeFunc, this, std::placeholders::_1));
}

void ExchangeStartOkMountWithOutPaddockMessage::_stabledMountsDescriptiontreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_stabledMountsDescriptiontree.addChild(std::bind(&ExchangeStartOkMountWithOutPaddockMessage::_stabledMountsDescriptionFunc, this, std::placeholders::_1));
  }
}

void ExchangeStartOkMountWithOutPaddockMessage::_stabledMountsDescriptionFunc(Reader *input)
{
  QSharedPointer<MountClientData> _item = QSharedPointer<MountClientData>(new MountClientData() );
  _item->deserialize(input);
  this->stabledMountsDescription.append(_item);
}

ExchangeStartOkMountWithOutPaddockMessage::ExchangeStartOkMountWithOutPaddockMessage()
{
  m_type = MessageEnum::EXCHANGESTARTOKMOUNTWITHOUTPADDOCKMESSAGE;
}

