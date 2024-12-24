#include "AlterationsMessage.h"

void AlterationsMessage::serialize(Writer *output)
{
  this->serializeAs_AlterationsMessage(output);
}

void AlterationsMessage::serializeAs_AlterationsMessage(Writer *output)
{
  output->writeShort((short)this->alterations.size());
  for(uint _i1 = 0; _i1 < this->alterations.size(); _i1++)
  {
    qSharedPointerCast<AlterationInfo>(this->alterations[_i1])->serializeAs_AlterationInfo(output);
  }
}

void AlterationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_AlterationsMessage(input);
}

void AlterationsMessage::deserializeAs_AlterationsMessage(Reader *input)
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

void AlterationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AlterationsMessage(tree);
}

void AlterationsMessage::deserializeAsyncAs_AlterationsMessage(FuncTree tree)
{
  this->_alterationstree = tree.addChild(std::bind(&AlterationsMessage::_alterationstreeFunc, this, std::placeholders::_1));
}

void AlterationsMessage::_alterationstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_alterationstree.addChild(std::bind(&AlterationsMessage::_alterationsFunc, this, std::placeholders::_1));
  }
}

void AlterationsMessage::_alterationsFunc(Reader *input)
{
  QSharedPointer<AlterationInfo> _item = QSharedPointer<AlterationInfo>(new AlterationInfo() );
  _item->deserialize(input);
  this->alterations.append(_item);
}

AlterationsMessage::AlterationsMessage()
{
  m_type = MessageEnum::ALTERATIONSMESSAGE;
}

