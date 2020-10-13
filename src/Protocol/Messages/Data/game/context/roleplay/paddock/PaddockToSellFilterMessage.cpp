#include "PaddockToSellFilterMessage.h"

void PaddockToSellFilterMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockToSellFilterMessage(output);
}

void PaddockToSellFilterMessage::serializeAs_PaddockToSellFilterMessage(Writer *output)
{
  output->writeInt((int)this->areaId);
  output->writeByte(this->atLeastNbMount);
  output->writeByte(this->atLeastNbMachine);
  if(this->maxPrice < 0 || this->maxPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element maxPrice.";
  }
  output->writeVarLong((double)this->maxPrice);
  output->writeByte(this->orderBy);
}

void PaddockToSellFilterMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockToSellFilterMessage(input);
}

void PaddockToSellFilterMessage::deserializeAs_PaddockToSellFilterMessage(Reader *input)
{
  this->_areaIdFunc(input);
  this->_atLeastNbMountFunc(input);
  this->_atLeastNbMachineFunc(input);
  this->_maxPriceFunc(input);
  this->_orderByFunc(input);
}

void PaddockToSellFilterMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockToSellFilterMessage(tree);
}

void PaddockToSellFilterMessage::deserializeAsyncAs_PaddockToSellFilterMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockToSellFilterMessage::_areaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockToSellFilterMessage::_atLeastNbMountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockToSellFilterMessage::_atLeastNbMachineFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockToSellFilterMessage::_maxPriceFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockToSellFilterMessage::_orderByFunc, this, std::placeholders::_1));
}

void PaddockToSellFilterMessage::_areaIdFunc(Reader *input)
{
  this->areaId = input->readInt();
}

void PaddockToSellFilterMessage::_atLeastNbMountFunc(Reader *input)
{
  this->atLeastNbMount = input->readByte();
}

void PaddockToSellFilterMessage::_atLeastNbMachineFunc(Reader *input)
{
  this->atLeastNbMachine = input->readByte();
}

void PaddockToSellFilterMessage::_maxPriceFunc(Reader *input)
{
  this->maxPrice = input->readVarUhLong();
  if(this->maxPrice < 0 || this->maxPrice > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockToSellFilterMessage -"<<"Forbidden value (" << this->maxPrice << ") on element of PaddockToSellFilterMessage.maxPrice.";
  }
}

void PaddockToSellFilterMessage::_orderByFunc(Reader *input)
{
  this->orderBy = input->readByte();
  if(this->orderBy < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellFilterMessage -"<<"Forbidden value (" << this->orderBy << ") on element of PaddockToSellFilterMessage.orderBy.";
  }
}

PaddockToSellFilterMessage::PaddockToSellFilterMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLFILTERMESSAGE;
}

