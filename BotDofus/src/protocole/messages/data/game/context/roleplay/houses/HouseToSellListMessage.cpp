#include "HouseToSellListMessage.h"

void HouseToSellListMessage::serialize(Writer *output)
{
  this->serializeAs_HouseToSellListMessage(output);
}

void HouseToSellListMessage::serializeAs_HouseToSellListMessage(Writer *output)
{
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element pageIndex.";
  }
  output->writeVarShort((int)this->pageIndex);
  if(this->totalPage < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element totalPage.";
  }
  output->writeVarShort((int)this->totalPage);
  output->writeShort((short)this->houseList.size());
  for(uint _i3 = 0; _i3 < this->houseList.size(); _i3++)
  {
    (this->houseList[_i3]).serializeAs_HouseInformationsForSell(output);
  }
}

void HouseToSellListMessage::deserialize(Reader *input)
{
  this->deserializeAs_HouseToSellListMessage(input);
}

void HouseToSellListMessage::deserializeAs_HouseToSellListMessage(Reader *input)
{
  HouseInformationsForSell _item3 ;
  this->_pageIndexFunc(input);
  this->_totalPageFunc(input);
  uint _houseListLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _houseListLen; _i3++)
  {
    _item3 = HouseInformationsForSell();
    _item3.deserialize(input);
    this->houseList.append(_item3);
  }
}

void HouseToSellListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_HouseToSellListMessage(tree);
}

void HouseToSellListMessage::deserializeAsyncAs_HouseToSellListMessage(FuncTree tree)
{
  tree.addChild(std::bind(&HouseToSellListMessage::_pageIndexFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&HouseToSellListMessage::_totalPageFunc, this, std::placeholders::_1));
  this->_houseListtree = tree.addChild(std::bind(&HouseToSellListMessage::_houseListtreeFunc, this, std::placeholders::_1));
}

void HouseToSellListMessage::_pageIndexFunc(Reader *input)
{
  this->pageIndex = input->readVarUhShort();
  if(this->pageIndex < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->pageIndex << ") on element of HouseToSellListMessage.pageIndex.";
  }
}

void HouseToSellListMessage::_totalPageFunc(Reader *input)
{
  this->totalPage = input->readVarUhShort();
  if(this->totalPage < 0)
  {
    qDebug()<<"ERREUR - HouseToSellListMessage -"<<"Forbidden value (" << this->totalPage << ") on element of HouseToSellListMessage.totalPage.";
  }
}

void HouseToSellListMessage::_houseListtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_houseListtree.addChild(std::bind(&HouseToSellListMessage::_houseListFunc, this, std::placeholders::_1));
  }
}

void HouseToSellListMessage::_houseListFunc(Reader *input)
{
  HouseInformationsForSell _item = HouseInformationsForSell();
  _item.deserialize(input);
  this->houseList.append(_item);
}

HouseToSellListMessage::HouseToSellListMessage()
{
  m_type = MessageEnum::HOUSETOSELLLISTMESSAGE;
}

