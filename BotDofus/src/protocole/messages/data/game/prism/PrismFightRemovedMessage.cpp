#include "PrismFightRemovedMessage.h"

void PrismFightRemovedMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightRemovedMessage(output);
}

void PrismFightRemovedMessage::serializeAs_PrismFightRemovedMessage(Writer *output)
{
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightRemovedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
}

void PrismFightRemovedMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightRemovedMessage(input);
}

void PrismFightRemovedMessage::deserializeAs_PrismFightRemovedMessage(Reader *input)
{
  this->_subAreaIdFunc(input);
}

void PrismFightRemovedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightRemovedMessage(tree);
}

void PrismFightRemovedMessage::deserializeAsyncAs_PrismFightRemovedMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightRemovedMessage::_subAreaIdFunc, this, std::placeholders::_1));
}

void PrismFightRemovedMessage::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PrismFightRemovedMessage -"<<"Forbidden value (" << this->subAreaId << ") on element of PrismFightRemovedMessage.subAreaId.";
  }
}

PrismFightRemovedMessage::PrismFightRemovedMessage()
{
  m_type = MessageEnum::PRISMFIGHTREMOVEDMESSAGE;
}

