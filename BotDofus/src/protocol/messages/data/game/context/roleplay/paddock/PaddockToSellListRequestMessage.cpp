#include "PaddockToSellListRequestMessage.h"

void PaddockToSellListRequestMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockToSellListRequestMessage(output);
}

void PaddockToSellListRequestMessage::serializeAs_PaddockToSellListRequestMessage(Writer *output)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  output->writeVarShort((int)this->pageIndex);
}

void PaddockToSellListRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockToSellListRequestMessage(input);
}

void PaddockToSellListRequestMessage::deserializeAs_PaddockToSellListRequestMessage(Reader *input)
{
  this->_pageIndexFunc(input);
}

void PaddockToSellListRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockToSellListRequestMessage(tree);
}

void PaddockToSellListRequestMessage::deserializeAsyncAs_PaddockToSellListRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockToSellListRequestMessage::_pageIndexFunc, this, std::placeholders::_1));
}

void PaddockToSellListRequestMessage::_pageIndexFunc(Reader *input)
{
  this->pageIndex = input->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListRequestMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of PaddockToSellListRequestMessage.pageIndex.";
  }
}

PaddockToSellListRequestMessage::PaddockToSellListRequestMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLLISTREQUESTMESSAGE;
}

