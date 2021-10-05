#include "PrismSetSabotagedRefusedMessage.h"

void PrismSetSabotagedRefusedMessage::serialize(Writer *output)
{
  this->serializeAs_PrismSetSabotagedRefusedMessage(output);
}

void PrismSetSabotagedRefusedMessage::serializeAs_PrismSetSabotagedRefusedMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRefusedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeByte(this->reason);
}

void PrismSetSabotagedRefusedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismSetSabotagedRefusedMessage(input);
}

void PrismSetSabotagedRefusedMessage::deserializeAs_PrismSetSabotagedRefusedMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
  this->_reasonFunc(input);
}

void PrismSetSabotagedRefusedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismSetSabotagedRefusedMessage(tree);
}

void PrismSetSabotagedRefusedMessage::deserializeAsyncAs_PrismSetSabotagedRefusedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismSetSabotagedRefusedMessage::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismSetSabotagedRefusedMessage::_reasonFunc, this, std::placeholders::_1));
}

void PrismSetSabotagedRefusedMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismSetSabotagedRefusedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismSetSabotagedRefusedMessage.subAreaId.";
  }
}

void PrismSetSabotagedRefusedMessage::_reasonFunc(Reader *input)
{
  this->reason = input->readByte();
}

PrismSetSabotagedRefusedMessage::PrismSetSabotagedRefusedMessage()
{
  m_type = MessageEnum::PRISMSETSABOTAGEDREFUSEDMESSAGE;
}

