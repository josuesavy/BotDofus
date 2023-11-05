#include "IdolListMessage.h"

void IdolListMessage::serialize(Writer *output)
{
  this->serializeAs_IdolListMessage(output);
}

void IdolListMessage::serializeAs_IdolListMessage(Writer *output)
{
  output->writeShort((short)this->chosenIdols.size());
  for(uint _i1 = 0; _i1 < this->chosenIdols.size(); _i1++)
  {
    if(this->chosenIdols[_i1] < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << this->chosenIdols[_i1] << ") on element 1 (starting at 1) of chosenIdols.";
    }
    output->writeVarShort((int)this->chosenIdols[_i1]);
  }
  output->writeShort((short)this->partyChosenIdols.size());
  for(uint _i2 = 0; _i2 < this->partyChosenIdols.size(); _i2++)
  {
    if(this->partyChosenIdols[_i2] < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << this->partyChosenIdols[_i2] << ") on element 2 (starting at 1) of partyChosenIdols.";
    }
    output->writeVarShort((int)this->partyChosenIdols[_i2]);
  }
  output->writeShort((short)this->partyIdols.size());
  for(uint _i3 = 0; _i3 < this->partyIdols.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<PartyIdol>(this->partyIdols[_i3])->getTypes().last());
    qSharedPointerCast<PartyIdol>(this->partyIdols[_i3])->serialize(output);
  }
}

void IdolListMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolListMessage(input);
}

void IdolListMessage::deserializeAs_IdolListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _id3 = 0;
  QSharedPointer<PartyIdol> _item3 ;
  uint _chosenIdolsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _chosenIdolsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _val1 << ") on elements of chosenIdols.";
    }
    this->chosenIdols.append(_val1);
  }
  uint _partyChosenIdolsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _partyChosenIdolsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _val2 << ") on elements of partyChosenIdols.";
    }
    this->partyChosenIdols.append(_val2);
  }
  uint _partyIdolsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _partyIdolsLen; _i3++)
  {
    _id3 = uint(input->readUShort());
    _item3 = qSharedPointerCast<PartyIdol>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->partyIdols.append(_item3);
  }
}

void IdolListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolListMessage(tree);
}

void IdolListMessage::deserializeAsyncAs_IdolListMessage(FuncTree tree)
{
  this->_chosenIdolstree = tree.addChild(std::bind(&IdolListMessage::_chosenIdolstreeFunc, this, std::placeholders::_1));
  this->_partyChosenIdolstree = tree.addChild(std::bind(&IdolListMessage::_partyChosenIdolstreeFunc, this, std::placeholders::_1));
  this->_partyIdolstree = tree.addChild(std::bind(&IdolListMessage::_partyIdolstreeFunc, this, std::placeholders::_1));
}

void IdolListMessage::_chosenIdolstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_chosenIdolstree.addChild(std::bind(&IdolListMessage::_chosenIdolsFunc, this, std::placeholders::_1));
  }
}

void IdolListMessage::_chosenIdolsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _val << ") on elements of chosenIdols.";
  }
  this->chosenIdols.append(_val);
}

void IdolListMessage::_partyChosenIdolstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_partyChosenIdolstree.addChild(std::bind(&IdolListMessage::_partyChosenIdolsFunc, this, std::placeholders::_1));
  }
}

void IdolListMessage::_partyChosenIdolsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - IdolListMessage -"<<"Forbidden value (" << _val << ") on elements of partyChosenIdols.";
  }
  this->partyChosenIdols.append(_val);
}

void IdolListMessage::_partyIdolstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_partyIdolstree.addChild(std::bind(&IdolListMessage::_partyIdolsFunc, this, std::placeholders::_1));
  }
}

void IdolListMessage::_partyIdolsFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<PartyIdol> _item = qSharedPointerCast<PartyIdol>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->partyIdols.append(_item);
}

IdolListMessage::IdolListMessage()
{
  m_type = MessageEnum::IDOLLISTMESSAGE;
}

