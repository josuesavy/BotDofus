#include "AlterationsUpdatedMessage.h"

void AlterationsUpdatedMessage::serialize(Writer *output)
{
  this->serializeAs_AlterationsUpdatedMessage(output);
}

void AlterationsUpdatedMessage::serializeAs_AlterationsUpdatedMessage(Writer *output)
{
  output->writeShort((short)this->alterations.size());
  for(uint _i1 = 0; _i1 < this->alterations.size(); _i1++)
  {
    qSharedPointerCast<AlterationInfo>(this->alterations[_i1])->serializeAs_AlterationInfo(output);
  }
}

void AlterationsUpdatedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlterationsUpdatedMessage(input);
}

void AlterationsUpdatedMessage::deserializeAs_AlterationsUpdatedMessage(Reader *input)
{
  QSharedPointer<AlterationInfo> _item1 ;
  uint _alterationsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _alterationsLen; _i1++)
  {
    _item1 = QSharedPointer<AlterationInfo>(new AlterationInfo() );
    _item1->deserialize(input);
    this->alterations.append(_item1);
  }
}

void AlterationsUpdatedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlterationsUpdatedMessage(tree);
}

void AlterationsUpdatedMessage::deserializeAsyncAs_AlterationsUpdatedMessage(FuncTree tree)
{
  this->_alterationstree = tree.addChild(std::bind(&AlterationsUpdatedMessage::_alterationstreeFunc, this, std::placeholders::_1));
}

void AlterationsUpdatedMessage::_alterationstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_alterationstree.addChild(std::bind(&AlterationsUpdatedMessage::_alterationsFunc, this, std::placeholders::_1));
  }
}

void AlterationsUpdatedMessage::_alterationsFunc(Reader *input)
{
  QSharedPointer<AlterationInfo> _item = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  _item->deserialize(input);
  this->alterations.append(_item);
}

AlterationsUpdatedMessage::AlterationsUpdatedMessage()
{
  m_type = MessageEnum::ALTERATIONSUPDATEDMESSAGE;
}

