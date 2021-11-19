#include "TitlesAndOrnamentsListMessage.h"

void TitlesAndOrnamentsListMessage::serialize(Writer *output)
{
  this->serializeAs_TitlesAndOrnamentsListMessage(output);
}

void TitlesAndOrnamentsListMessage::serializeAs_TitlesAndOrnamentsListMessage(Writer *output)
{
  output->writeShort((short)this->titles.size());
  for(uint _i1 = 0; _i1 < this->titles.size(); _i1++)
  {
    if(this->titles[_i1] < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->titles[_i1] << ") on element 1 (starting at 1) of titles.";
    }
    output->writeVarShort((int)this->titles[_i1]);
  }
  output->writeShort((short)this->ornaments.size());
  for(uint _i2 = 0; _i2 < this->ornaments.size(); _i2++)
  {
    if(this->ornaments[_i2] < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->ornaments[_i2] << ") on element 2 (starting at 1) of ornaments.";
    }
    output->writeVarShort((int)this->ornaments[_i2]);
  }
  if(this->activeTitle < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeTitle << ") on element activeTitle.";
  }
  output->writeVarShort((int)this->activeTitle);
  if(this->activeOrnament < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeOrnament << ") on element activeOrnament.";
  }
  output->writeVarShort((int)this->activeOrnament);
}

void TitlesAndOrnamentsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_TitlesAndOrnamentsListMessage(input);
}

void TitlesAndOrnamentsListMessage::deserializeAs_TitlesAndOrnamentsListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _titlesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _titlesLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _val1 << ") on elements of titles.";
    }
    this->titles.append(_val1);
  }
  uint _ornamentsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _ornamentsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _val2 << ") on elements of ornaments.";
    }
    this->ornaments.append(_val2);
  }
  this->_activeTitleFunc(input);
  this->_activeOrnamentFunc(input);
}

void TitlesAndOrnamentsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TitlesAndOrnamentsListMessage(tree);
}

void TitlesAndOrnamentsListMessage::deserializeAsyncAs_TitlesAndOrnamentsListMessage(FuncTree tree)
{
  this->_titlestree = tree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_titlestreeFunc, this, std::placeholders::_1));
  this->_ornamentstree = tree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_ornamentstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_activeTitleFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_activeOrnamentFunc, this, std::placeholders::_1));
}

void TitlesAndOrnamentsListMessage::_titlestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_titlestree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_titlesFunc, this, std::placeholders::_1));
  }
}

void TitlesAndOrnamentsListMessage::_titlesFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _val << ") on elements of titles.";
  }
  this->titles.append(_val);
}

void TitlesAndOrnamentsListMessage::_ornamentstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_ornamentstree.addChild(std::bind(&TitlesAndOrnamentsListMessage::_ornamentsFunc, this, std::placeholders::_1));
  }
}

void TitlesAndOrnamentsListMessage::_ornamentsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << _val << ") on elements of ornaments.";
  }
  this->ornaments.append(_val);
}

void TitlesAndOrnamentsListMessage::_activeTitleFunc(Reader *input)
{
  this->activeTitle = input->readVarUhShort();
  if(this->activeTitle < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeTitle << ") on element of TitlesAndOrnamentsListMessage.activeTitle.";
  }
}

void TitlesAndOrnamentsListMessage::_activeOrnamentFunc(Reader *input)
{
  this->activeOrnament = input->readVarUhShort();
  if(this->activeOrnament < 0)
  {
    qDebug()<<"ERREUR - TitlesAndOrnamentsListMessage -"<<"Forbidden value (" << this->activeOrnament << ") on element of TitlesAndOrnamentsListMessage.activeOrnament.";
  }
}

TitlesAndOrnamentsListMessage::TitlesAndOrnamentsListMessage()
{
  m_type = MessageEnum::TITLESANDORNAMENTSLISTMESSAGE;
}

