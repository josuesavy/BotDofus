#include "AccountHouseMessage.h"

void AccountHouseMessage::serialize(Writer *output)
{
  this->serializeAs_AccountHouseMessage(output);
}

void AccountHouseMessage::serializeAs_AccountHouseMessage(Writer *output)
{
  output->writeShort((short)this->houses.size());
  for(uint _i1 = 0; _i1 < this->houses.size(); _i1++)
  {
    qSharedPointerCast<AccountHouseInformations>(this->houses[_i1])->serializeAs_AccountHouseInformations(output);
  }
}

void AccountHouseMessage::deserialize(Reader *input)
{
  this->deserializeAs_AccountHouseMessage(input);
}

void AccountHouseMessage::deserializeAs_AccountHouseMessage(Reader *input)
{
  QSharedPointer<AccountHouseInformations> _item1 ;
  uint _housesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _housesLen; _i1++)
  {
    _item1 = QSharedPointer<AccountHouseInformations>(new AccountHouseInformations() );
    _item1->deserialize(input);
    this->houses.append(_item1);
  }
}

void AccountHouseMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountHouseMessage(tree);
}

void AccountHouseMessage::deserializeAsyncAs_AccountHouseMessage(FuncTree tree)
{
  this->_housestree = tree.addChild(std::bind(&AccountHouseMessage::_housestreeFunc, this, std::placeholders::_1));
}

void AccountHouseMessage::_housestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_housestree.addChild(std::bind(&AccountHouseMessage::_housesFunc, this, std::placeholders::_1));
  }
}

void AccountHouseMessage::_housesFunc(Reader *input)
{
  QSharedPointer<AccountHouseInformations> _item = QSharedPointer<AccountHouseInformations>(new AccountHouseInformations() );
  _item->deserialize(input);
  this->houses.append(_item);
}

AccountHouseMessage::AccountHouseMessage()
{
  m_type = MessageEnum::ACCOUNTHOUSEMESSAGE;
}

