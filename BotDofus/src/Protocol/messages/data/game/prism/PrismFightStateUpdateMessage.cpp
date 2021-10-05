#include "PrismFightStateUpdateMessage.h"

void PrismFightStateUpdateMessage::serialize(Writer *output)
{
  this->serializeAs_PrismFightStateUpdateMessage(output);
}

void PrismFightStateUpdateMessage::serializeAs_PrismFightStateUpdateMessage(Writer *output)
{
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismFightStateUpdateMessage -"<<"Forbidden value (" << this->state << ") on element state.";
  }
  output->writeByte(this->state);
}

void PrismFightStateUpdateMessage::deserialize(Reader *input)
{
  this->deserializeAs_PrismFightStateUpdateMessage(input);
}

void PrismFightStateUpdateMessage::deserializeAs_PrismFightStateUpdateMessage(Reader *input)
{
  this->_stateFunc(input);
}

void PrismFightStateUpdateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismFightStateUpdateMessage(tree);
}

void PrismFightStateUpdateMessage::deserializeAsyncAs_PrismFightStateUpdateMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PrismFightStateUpdateMessage::_stateFunc, this, std::placeholders::_1));
}

void PrismFightStateUpdateMessage::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - PrismFightStateUpdateMessage -"<<"Forbidden value (" << this->state << ") on element of PrismFightStateUpdateMessage.state.";
  }
}

PrismFightStateUpdateMessage::PrismFightStateUpdateMessage()
{
  m_type = MessageEnum::PRISMFIGHTSTATEUPDATEMESSAGE;
}

