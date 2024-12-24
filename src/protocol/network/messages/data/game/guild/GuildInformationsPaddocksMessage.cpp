#include "GuildInformationsPaddocksMessage.h"

void GuildInformationsPaddocksMessage::serialize(Writer *output)
{
  this->serializeAs_GuildInformationsPaddocksMessage(output);
}

void GuildInformationsPaddocksMessage::serializeAs_GuildInformationsPaddocksMessage(Writer *output)
{
  if(this->nbPaddockMax < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsPaddocksMessage -"<<"Forbidden value (" << this->nbPaddockMax << ") on element nbPaddockMax.";
  }
  output->writeByte(this->nbPaddockMax);
  output->writeShort((short)this->paddocksInformations.size());
  for(uint _i2 = 0; _i2 < this->paddocksInformations.size(); _i2++)
  {
    (this->paddocksInformations[_i2]).serializeAs_PaddockContentInformations(output);
  }
}

void GuildInformationsPaddocksMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildInformationsPaddocksMessage(input);
}

void GuildInformationsPaddocksMessage::deserializeAs_GuildInformationsPaddocksMessage(Reader *input)
{
  PaddockContentInformations _item2 ;
  this->_nbPaddockMaxFunc(input);
  uint _paddocksInformationsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _paddocksInformationsLen; _i2++)
  {
    _item2 = PaddockContentInformations();
    _item2.deserialize(input);
    this->paddocksInformations.append(_item2);
  }
}

void GuildInformationsPaddocksMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInformationsPaddocksMessage(tree);
}

void GuildInformationsPaddocksMessage::deserializeAsyncAs_GuildInformationsPaddocksMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildInformationsPaddocksMessage::_nbPaddockMaxFunc, this, std::placeholders::_1));
  this->_paddocksInformationstree = tree.addChild(std::bind(&GuildInformationsPaddocksMessage::_paddocksInformationstreeFunc, this, std::placeholders::_1));
}

void GuildInformationsPaddocksMessage::_nbPaddockMaxFunc(Reader *input)
{
  this->nbPaddockMax = input->readByte();
  if(this->nbPaddockMax < 0)
  {
    qDebug()<<"ERREUR - GuildInformationsPaddocksMessage -"<<"Forbidden value (" << this->nbPaddockMax << ") on element of GuildInformationsPaddocksMessage.nbPaddockMax.";
  }
}

void GuildInformationsPaddocksMessage::_paddocksInformationstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_paddocksInformationstree.addChild(std::bind(&GuildInformationsPaddocksMessage::_paddocksInformationsFunc, this, std::placeholders::_1));
  }
}

void GuildInformationsPaddocksMessage::_paddocksInformationsFunc(Reader *input)
{
  PaddockContentInformations _item = PaddockContentInformations();
  _item.deserialize(input);
  this->paddocksInformations.append(_item);
}

GuildInformationsPaddocksMessage::GuildInformationsPaddocksMessage()
{
  m_type = MessageEnum::GUILDINFORMATIONSPADDOCKSMESSAGE;
}

