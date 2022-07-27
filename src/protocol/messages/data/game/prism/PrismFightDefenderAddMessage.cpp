#include "PrismFightDefenderAddMessage.h"

void PrismFightDefenderAddMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightDefenderAddMessage(output);
}

void PrismFightDefenderAddMessage::serializeAs_PrismFightDefenderAddMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeShort((short)this->defender->getTypes().last());
  this->defender->serialize(output);
}

void PrismFightDefenderAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightDefenderAddMessage(input);
}

void PrismFightDefenderAddMessage::deserializeAs_PrismFightDefenderAddMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_fightIdFunc(input);
  uint _id3 = input->readUShort();
  this->defender = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id3));
  this->defender->deserialize(input);
}

void PrismFightDefenderAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightDefenderAddMessage(tree);
}

void PrismFightDefenderAddMessage::deserializeAsyncAs_PrismFightDefenderAddMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightDefenderAddMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightDefenderAddMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_defendertree = tree.addChild(std::bind(&PrismFightDefenderAddMessage::_defendertreeFunc, this, std::placeholders::_1));
}

void PrismFightDefenderAddMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightDefenderAddMessage.subAreaId.";
  }
}

void PrismFightDefenderAddMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderAddMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightDefenderAddMessage.fightId.";
  }
}

void PrismFightDefenderAddMessage::_defendertreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->defender = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->defender->deserializeAsync(this->_defendertree);
}

PrismFightDefenderAddMessage::PrismFightDefenderAddMessage()
{
  m_type = MessageEnum::PRISMFIGHTDEFENDERADDMESSAGE;
}

