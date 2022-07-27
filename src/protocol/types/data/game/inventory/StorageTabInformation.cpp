#include "StorageTabInformation.h"

void StorageTabInformation::serialize(Writer *output)
{
  this->serializeAs_StorageTabInformation(output);
}

void StorageTabInformation::serializeAs_StorageTabInformation(Writer *output)
{
  output->writeUTF(this->name);
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
  if(this->picto < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->picto << ") on element picto.";
  }
  output->writeVarInt((int)this->picto);
  if(this->openRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->openRight << ") on element openRight.";
  }
  output->writeVarInt((int)this->openRight);
  if(this->dropRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->dropRight << ") on element dropRight.";
  }
  output->writeVarInt((int)this->dropRight);
  if(this->takeRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->takeRight << ") on element takeRight.";
  }
  output->writeVarInt((int)this->takeRight);
  output->writeShort((short)this->dropTypeLimitation.size());
  for(uint _i7 = 0; _i7 < this->dropTypeLimitation.size(); _i7++)
  {
    if(this->dropTypeLimitation[_i7] < 0)
    {
      qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->dropTypeLimitation[_i7] << ") on element 7 (starting at 1) of dropTypeLimitation.";
    }
    output->writeVarInt((int)this->dropTypeLimitation[_i7]);
  }
}

void StorageTabInformation::deserialize(Reader *input)
{
  this->deserializeAs_StorageTabInformation(input);
}

void StorageTabInformation::deserializeAs_StorageTabInformation(Reader *input)
{
  uint _val7 = 0;
  this->_nameFunc(input);
  this->_tabNumberFunc(input);
  this->_pictoFunc(input);
  this->_openRightFunc(input);
  this->_dropRightFunc(input);
  this->_takeRightFunc(input);
  uint _dropTypeLimitationLen = input->readUShort();
  for(uint _i7 = 0; _i7 < _dropTypeLimitationLen; _i7++)
  {
    _val7 = input->readVarUhInt();
    if(_val7 < 0)
    {
      qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << _val7 << ") on elements of dropTypeLimitation.";
    }
    this->dropTypeLimitation.append(_val7);
  }
}

void StorageTabInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StorageTabInformation(tree);
}

void StorageTabInformation::deserializeAsyncAs_StorageTabInformation(FuncTree tree)
{
  tree.addChild(std::bind(&StorageTabInformation::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StorageTabInformation::_tabNumberFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StorageTabInformation::_pictoFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StorageTabInformation::_openRightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StorageTabInformation::_dropRightFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&StorageTabInformation::_takeRightFunc, this, std::placeholders::_1));
  this->_dropTypeLimitationtree = tree.addChild(std::bind(&StorageTabInformation::_dropTypeLimitationtreeFunc, this, std::placeholders::_1));
}

void StorageTabInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void StorageTabInformation::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->tabNumber << ") on element of StorageTabInformation.tabNumber.";
  }
}

void StorageTabInformation::_pictoFunc(Reader *input)
{
  this->picto = input->readVarUhInt();
  if(this->picto < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->picto << ") on element of StorageTabInformation.picto.";
  }
}

void StorageTabInformation::_openRightFunc(Reader *input)
{
  this->openRight = input->readVarUhInt();
  if(this->openRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->openRight << ") on element of StorageTabInformation.openRight.";
  }
}

void StorageTabInformation::_dropRightFunc(Reader *input)
{
  this->dropRight = input->readVarUhInt();
  if(this->dropRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->dropRight << ") on element of StorageTabInformation.dropRight.";
  }
}

void StorageTabInformation::_takeRightFunc(Reader *input)
{
  this->takeRight = input->readVarUhInt();
  if(this->takeRight < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << this->takeRight << ") on element of StorageTabInformation.takeRight.";
  }
}

void StorageTabInformation::_dropTypeLimitationtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dropTypeLimitationtree.addChild(std::bind(&StorageTabInformation::_dropTypeLimitationFunc, this, std::placeholders::_1));
  }
}

void StorageTabInformation::_dropTypeLimitationFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - StorageTabInformation -"<<"Forbidden value (" << _val << ") on elements of dropTypeLimitation.";
  }
  this->dropTypeLimitation.append(_val);
}

StorageTabInformation::StorageTabInformation()
{
  m_types<<ClassEnum::STORAGETABINFORMATION;
}

bool StorageTabInformation::operator==(const StorageTabInformation &compared)
{
  if(name == compared.name)
  if(tabNumber == compared.tabNumber)
  if(picto == compared.picto)
  if(openRight == compared.openRight)
  if(dropRight == compared.dropRight)
  if(takeRight == compared.takeRight)
  if(dropTypeLimitation == compared.dropTypeLimitation)
  if(_dropTypeLimitationtree == compared._dropTypeLimitationtree)
  return true;
  
  return false;
}

