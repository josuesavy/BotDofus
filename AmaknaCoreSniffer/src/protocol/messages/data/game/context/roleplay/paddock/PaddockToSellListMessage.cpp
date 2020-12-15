#include "PaddockToSellListMessage.h"

void PaddockToSellListMessage::serialize(Writer *output)
{
  this->serializeAs_PaddockToSellListMessage(output);
}

void PaddockToSellListMessage::serializeAs_PaddockToSellListMessage(Writer *output)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  output->writeVarShort((int)this->pageIndex);
  if(this->totalPage < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element totalPage.";
  }
  output->writeVarShort((int)this->totalPage);
  output->writeShort((short)this->paddockList.size());
  for(uint _i3 = 0; _i3 < this->paddockList.size(); _i3++)
  {
    (this->paddockList[_i3]).serializeAs_PaddockInformationsForSell(output);
  }
}

void PaddockToSellListMessage::deserialize(Reader *input)
{
  this->deserializeAs_PaddockToSellListMessage(input);
}

void PaddockToSellListMessage::deserializeAs_PaddockToSellListMessage(Reader *input)
{
  PaddockInformationsForSell _item3 ;
  this->_pageIndexFunc(input);
  this->_totalPageFunc(input);
  uint _paddockListLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _paddockListLen; _i3++)
  {
    _item3 = PaddockInformationsForSell();
    _item3.deserialize(input);
    this->paddockList.append(_item3);
  }
}

void PaddockToSellListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockToSellListMessage(tree);
}

void PaddockToSellListMessage::deserializeAsyncAs_PaddockToSellListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockToSellListMessage::_pageIndexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockToSellListMessage::_totalPageFunc, this, std::placeholders::_1));
  this->_paddockListtree = tree.addChild(std::bind(&PaddockToSellListMessage::_paddockListtreeFunc, this, std::placeholders::_1));
}

void PaddockToSellListMessage::_pageIndexFunc(Reader *input)
{
  this->pageIndex = input->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of PaddockToSellListMessage.pageIndex.";
  }
}

void PaddockToSellListMessage::_totalPageFunc(Reader *input)
{
  this->totalPage = input->readVarUhShort();
  if(this->totalPage < 0)
  {
    qDebug()<<"ERREUR - PaddockToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element of PaddockToSellListMessage.totalPage.";
  }
}

void PaddockToSellListMessage::_paddockListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_paddockListtree.addChild(std::bind(&PaddockToSellListMessage::_paddockListFunc, this, std::placeholders::_1));
  }
}

void PaddockToSellListMessage::_paddockListFunc(Reader *input)
{
  PaddockInformationsForSell _item = PaddockInformationsForSell();
  _item.deserialize(input);
  this->paddockList.append(_item);
}

PaddockToSellListMessage::PaddockToSellListMessage()
{
  m_type = MessageEnum::PADDOCKTOSELLLISTMESSAGE;
}

