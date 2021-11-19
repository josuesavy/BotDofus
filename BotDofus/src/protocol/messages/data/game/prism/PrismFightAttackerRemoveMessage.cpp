#include "PrismFightAttackerRemoveMessage.h"

void PrismFightAttackerRemoveMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightAttackerRemoveMessage(output);
}

void PrismFightAttackerRemoveMessage::serializeAs_PrismFightAttackerRemoveMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element fighterToRemoveId.";
  }
  output->writeVarLong((double)this->fighterToRemoveId);
}

void PrismFightAttackerRemoveMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightAttackerRemoveMessage(input);
}

void PrismFightAttackerRemoveMessage::deserializeAs_PrismFightAttackerRemoveMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_fightIdFunc(input);
  this->_fighterToRemoveIdFunc(input);
}

void PrismFightAttackerRemoveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightAttackerRemoveMessage(tree);
}

void PrismFightAttackerRemoveMessage::deserializeAsyncAs_PrismFightAttackerRemoveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightAttackerRemoveMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightAttackerRemoveMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightAttackerRemoveMessage::_fighterToRemoveIdFunc, this, std::placeholders::_1));
}

void PrismFightAttackerRemoveMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightAttackerRemoveMessage.subAreaId.";
  }
}

void PrismFightAttackerRemoveMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightAttackerRemoveMessage.fightId.";
  }
}

void PrismFightAttackerRemoveMessage::_fighterToRemoveIdFunc(Reader *input)
{
  this->fighterToRemoveId = input->readVarUhLong();
  if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightAttackerRemoveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element of PrismFightAttackerRemoveMessage.fighterToRemoveId.";
  }
}

PrismFightAttackerRemoveMessage::PrismFightAttackerRemoveMessage()
{
  m_type = MessageEnum::PRISMFIGHTATTACKERREMOVEMESSAGE;
}

