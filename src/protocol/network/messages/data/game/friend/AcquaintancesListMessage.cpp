#include "AcquaintancesListMessage.h"

void AcquaintancesListMessage::serialize(Writer *output)
{
  this->serializeAs_AcquaintancesListMessage(output);
}

void AcquaintancesListMessage::serializeAs_AcquaintancesListMessage(Writer *output)
{
  output->writeShort((short)this->acquaintanceList.size());
  for(uint _i1 = 0; _i1 < this->acquaintanceList.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<AcquaintanceInformation>(this->acquaintanceList[_i1])->getTypes().last());
    qSharedPointerCast<AcquaintanceInformation>(this->acquaintanceList[_i1])->serialize(output);
  }
}

void AcquaintancesListMessage::deserialize(Reader *input)
{
  this->deserializeAs_AcquaintancesListMessage(input);
}

void AcquaintancesListMessage::deserializeAs_AcquaintancesListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<AcquaintanceInformation> _item1 ;
  uint _acquaintanceListLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _acquaintanceListLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<AcquaintanceInformation>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->acquaintanceList.append(_item1);
  }
}

void AcquaintancesListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AcquaintancesListMessage(tree);
}

void AcquaintancesListMessage::deserializeAsyncAs_AcquaintancesListMessage(FuncTree tree)
{
  this->_acquaintanceListtree = tree.addChild(std::bind(&AcquaintancesListMessage::_acquaintanceListtreeFunc, this, std::placeholders::_1));
}

void AcquaintancesListMessage::_acquaintanceListtreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_acquaintanceListtree.addChild(std::bind(&AcquaintancesListMessage::_acquaintanceListFunc, this, std::placeholders::_1));
  }
}

void AcquaintancesListMessage::_acquaintanceListFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<AcquaintanceInformation> _item = qSharedPointerCast<AcquaintanceInformation>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->acquaintanceList.append(_item);
}

AcquaintancesListMessage::AcquaintancesListMessage()
{
  m_type = MessageEnum::ACQUAINTANCESLISTMESSAGE;
}

