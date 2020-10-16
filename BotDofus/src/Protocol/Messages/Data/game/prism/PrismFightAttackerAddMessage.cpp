#include "PrismFightAttackerAddMessage.h"

void PrismFightAttackerAddMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightAttackerAddMessage(output);
}

void PrismFightAttackerAddMessage::serializeAs_PrismFightAttackerAddMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  output->writeShort((short)this->attacker->getTypes().last());
  this->attacker->serialize(output);
}

void PrismFightAttackerAddMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightAttackerAddMessage(input);
}

void PrismFightAttackerAddMessage::deserializeAs_PrismFightAttackerAddMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_fightIdFunc(input);
  uint _id3 = input->readUShort();
  this->attacker = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id3));
  this->attacker->deserialize(input);
}

void PrismFightAttackerAddMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightAttackerAddMessage(tree);
}

void PrismFightAttackerAddMessage::deserializeAsyncAs_PrismFightAttackerAddMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightAttackerAddMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightAttackerAddMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_attackertree = tree.addChild(std::bind(&PrismFightAttackerAddMessage::_attackertreeFunc, this, std::placeholders::_1));
}

void PrismFightAttackerAddMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightAttackerAddMessage.subAreaId.";
  }
}

void PrismFightAttackerAddMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerAddMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightAttackerAddMessage.fightId.";
  }
}

void PrismFightAttackerAddMessage::_attackertreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->attacker = qSharedPointerCast<CharacterMinimalPlusLookInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->attacker->deserializeAsync(this->_attackertree);
}

PrismFightAttackerAddMessage::PrismFightAttackerAddMessage()
{
  m_type = MessageEnum::PRISMFIGHTATTACKERADDMESSAGE;
}

