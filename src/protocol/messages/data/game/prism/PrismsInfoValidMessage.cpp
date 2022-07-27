#include "PrismsInfoValidMessage.h"

void PrismsInfoValidMessage::serialize(Writer *output)
{
  this->serializeAs_PrismsInfoValidMessage(output);
}

void PrismsInfoValidMessage::serializeAs_PrismsInfoValidMessage(Writer *output)
{
  output->writeShort((short)this->fights.size());
  for(uint _i1 = 0; _i1 < this->fights.size(); _i1++)
  {
    qSharedPointerCast<PrismFightersInformation>(this->fights[_i1])->serializeAs_PrismFightersInformation(output);
  }
}

void PrismsInfoValidMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismsInfoValidMessage(input);
}

void PrismsInfoValidMessage::deserializeAs_PrismsInfoValidMessage(Reader *input)
{
  QSharedPointer<PrismFightersInformation> _item1 ;
  uint _fightsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _fightsLen; _i1++)
  {
    _item1 = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
    _item1->deserialize(input);
    this->fights.append(_item1);
  }
}

void PrismsInfoValidMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismsInfoValidMessage(tree);
}

void PrismsInfoValidMessage::deserializeAsyncAs_PrismsInfoValidMessage(FuncTree tree)
{
  this->_fightstree = tree.addChild(std::bind(&PrismsInfoValidMessage::_fightstreeFunc, this, std::placeholders::_1));
}

void PrismsInfoValidMessage::_fightstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_fightstree.addChild(std::bind(&PrismsInfoValidMessage::_fightsFunc, this, std::placeholders::_1));
  }
}

void PrismsInfoValidMessage::_fightsFunc(Reader *input)
{
  QSharedPointer<PrismFightersInformation> _item = QSharedPointer<PrismFightersInformation>(new PrismFightersInformation() );
  _item->deserialize(input);
  this->fights.append(_item);
}

PrismsInfoValidMessage::PrismsInfoValidMessage()
{
  m_type = MessageEnum::PRISMSINFOVALIDMESSAGE;
}

