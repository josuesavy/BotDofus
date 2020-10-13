#include "IdolFightPreparationUpdateMessage.h"

void IdolFightPreparationUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_IdolFightPreparationUpdateMessage(output);
}

void IdolFightPreparationUpdateMessage::serializeAs_IdolFightPreparationUpdateMessage(Writer *output)
{
  output->writeByte(this->idolSource);
  output->writeShort((short)this->idols.size());
  for(uint _i2 = 0; _i2 < this->idols.size(); _i2++)
  {
    output->writeShort((short)qSharedPointerCast<Idol>(this->idols[_i2])->getTypes().last());
    qSharedPointerCast<Idol>(this->idols[_i2])->serialize(output);
  }
}

void IdolFightPreparationUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_IdolFightPreparationUpdateMessage(input);
}

void IdolFightPreparationUpdateMessage::deserializeAs_IdolFightPreparationUpdateMessage(Reader *input)
{
  uint _id2 = 0;
  QSharedPointer<Idol> _item2 ;
  this->_idolSourceFunc(input);
  uint _idolsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _idolsLen; _i2++)
  {
    _id2 = input->readUShort();
    _item2 = qSharedPointerCast<Idol>(ClassManagerSingleton::get()->getClass(_id2));
    _item2->deserialize(input);
    this->idols.append(_item2);
  }
}

void IdolFightPreparationUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_IdolFightPreparationUpdateMessage(tree);
}

void IdolFightPreparationUpdateMessage::deserializeAsyncAs_IdolFightPreparationUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&IdolFightPreparationUpdateMessage::_idolSourceFunc, this, std::placeholders::_1));
  this->_idolstree = tree.addChild(std::bind(&IdolFightPreparationUpdateMessage::_idolstreeFunc, this, std::placeholders::_1));
}

void IdolFightPreparationUpdateMessage::_idolSourceFunc(Reader *input)
{
  this->idolSource = input->readByte();
  if(this->idolSource < 0)
  {
    qDebug()<<"ERREUR - IdolFightPreparationUpdateMessage -"<<"Forbidden value (" << this->idolSource << ") on element of IdolFightPreparationUpdateMessage.idolSource.";
  }
}

void IdolFightPreparationUpdateMessage::_idolstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idolstree.addChild(std::bind(&IdolFightPreparationUpdateMessage::_idolsFunc, this, std::placeholders::_1));
  }
}

void IdolFightPreparationUpdateMessage::_idolsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<Idol> _item = qSharedPointerCast<Idol>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->idols.append(_item);
}

IdolFightPreparationUpdateMessage::IdolFightPreparationUpdateMessage()
{
  m_type = MessageEnum::IDOLFIGHTPREPARATIONUPDATEMESSAGE;
}

