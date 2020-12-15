#include "PrismFightDefenderLeaveMessage.h"

void PrismFightDefenderLeaveMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightDefenderLeaveMessage(output);
}

void PrismFightDefenderLeaveMessage::serializeAs_PrismFightDefenderLeaveMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeVarShort((int)this->fightId);
  if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element fighterToRemoveId.";
  }
  output->writeVarLong((double)this->fighterToRemoveId);
}

void PrismFightDefenderLeaveMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightDefenderLeaveMessage(input);
}

void PrismFightDefenderLeaveMessage::deserializeAs_PrismFightDefenderLeaveMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_fightIdFunc(input);
  this->_fighterToRemoveIdFunc(input);
}

void PrismFightDefenderLeaveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightDefenderLeaveMessage(tree);
}

void PrismFightDefenderLeaveMessage::deserializeAsyncAs_PrismFightDefenderLeaveMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightDefenderLeaveMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightDefenderLeaveMessage::_fightIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismFightDefenderLeaveMessage::_fighterToRemoveIdFunc, this, std::placeholders::_1));
}

void PrismFightDefenderLeaveMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightDefenderLeaveMessage.subAreaId.";
  }
}

void PrismFightDefenderLeaveMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readVarUhShort();
  if(this->fightId < 0)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fightId << ") on element of PrismFightDefenderLeaveMessage.fightId.";
  }
}

void PrismFightDefenderLeaveMessage::_fighterToRemoveIdFunc(Reader *input)
{
  this->fighterToRemoveId = input->readVarUhLong();
  if(this->fighterToRemoveId < 0 || this->fighterToRemoveId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismFightDefenderLeaveMessage -"<<"Forbidden value (" << this->fighterToRemoveId << ") on element of PrismFightDefenderLeaveMessage.fighterToRemoveId.";
  }
}

PrismFightDefenderLeaveMessage::PrismFightDefenderLeaveMessage()
{
  m_type = MessageEnum::PRISMFIGHTDEFENDERLEAVEMESSAGE;
}

