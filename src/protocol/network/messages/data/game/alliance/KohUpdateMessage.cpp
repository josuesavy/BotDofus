#include "KohUpdateMessage.h"

void KohUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_KohUpdateMessage(output);
}

void KohUpdateMessage::serializeAs_KohUpdateMessage(Writer *output)
{
  output->writeShort((short)this->kohAllianceInfo.size());
  for(uint _i1 = 0; _i1 < this->kohAllianceInfo.size(); _i1++)
  {
    qSharedPointerCast<KohAllianceInfo>(this->kohAllianceInfo[_i1])->serializeAs_KohAllianceInfo(output);
  }
  if(this->startingAvaTimestamp < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->startingAvaTimestamp << ") on element startingAvaTimestamp.";
  }
  output->writeInt((int)this->startingAvaTimestamp);
  if(this->nextTickTime < 0 || this->nextTickTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element nextTickTime.";
  }
  output->writeDouble(this->nextTickTime);
}

void KohUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_KohUpdateMessage(input);
}

void KohUpdateMessage::deserializeAs_KohUpdateMessage(Reader *input)
{
  QSharedPointer<KohAllianceInfo> _item1 ;
  uint _kohAllianceInfoLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _kohAllianceInfoLen; _i1++)
  {
    _item1 = QSharedPointer<KohAllianceInfo>(new KohAllianceInfo() );
    _item1->deserialize(input);
    this->kohAllianceInfo.append(_item1);
  }
  this->_startingAvaTimestampFunc(input);
  this->_nextTickTimeFunc(input);
}

void KohUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_KohUpdateMessage(tree);
}

void KohUpdateMessage::deserializeAsyncAs_KohUpdateMessage(FuncTree tree)
{
  this->_kohAllianceInfotree = tree.addChild(std::bind(&KohUpdateMessage::_kohAllianceInfotreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohUpdateMessage::_startingAvaTimestampFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&KohUpdateMessage::_nextTickTimeFunc, this, std::placeholders::_1));
}

void KohUpdateMessage::_kohAllianceInfotreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_kohAllianceInfotree.addChild(std::bind(&KohUpdateMessage::_kohAllianceInfoFunc, this, std::placeholders::_1));
  }
}

void KohUpdateMessage::_kohAllianceInfoFunc(Reader *input)
{
  QSharedPointer<KohAllianceInfo> _item = QSharedPointer<KohAllianceInfo>(new KohAllianceInfo() );
  _item->deserialize(input);
  this->kohAllianceInfo.append(_item);
}

void KohUpdateMessage::_startingAvaTimestampFunc(Reader *input)
{
  this->startingAvaTimestamp = input->readInt();
  if(this->startingAvaTimestamp < 0)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->startingAvaTimestamp << ") on element of KohUpdateMessage.startingAvaTimestamp.";
  }
}

void KohUpdateMessage::_nextTickTimeFunc(Reader *input)
{
  this->nextTickTime = input->readDouble();
  if(this->nextTickTime < 0 || this->nextTickTime > 9007199254740992)
  {
    qDebug()<<"ERREUR - KohUpdateMessage -"<<"Forbidden value (" << this->nextTickTime << ") on element of KohUpdateMessage.nextTickTime.";
  }
}

KohUpdateMessage::KohUpdateMessage()
{
  m_type = MessageEnum::KOHUPDATEMESSAGE;
}

