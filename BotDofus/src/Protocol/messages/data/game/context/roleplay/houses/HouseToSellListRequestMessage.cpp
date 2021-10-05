#include "HouseToSellListRequestMessage.h"

void HouseToSellListRequestMessage::serialize(Writer *output)
{
  this->serializeAs_HouseToSellListRequestMessage(output);
}

void HouseToSellListRequestMessage::serializeAs_HouseToSellListRequestMessage(Writer *output)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  output->writeVarShort((int)this->pageIndex);
}

void HouseToSellListRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseToSellListRequestMessage(input);
}

void HouseToSellListRequestMessage::deserializeAs_HouseToSellListRequestMessage(Reader *input)
{
  this->_pageIndexFunc(input);
}

void HouseToSellListRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseToSellListRequestMessage(tree);
}

void HouseToSellListRequestMessage::deserializeAsyncAs_HouseToSellListRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseToSellListRequestMessage::_pageIndexFunc, this, std::placeholders::_1));
}

void HouseToSellListRequestMessage::_pageIndexFunc(Reader *input)
{
  this->pageIndex = input->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of HouseToSellListRequestMessage.pageIndex.";
  }
}

HouseToSellListRequestMessage::HouseToSellListRequestMessage()
{
  m_type = MessageEnum::HOUSETOSELLLISTREQUESTMESSAGE;
}

