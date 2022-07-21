#include "UpdatedStorageTabInformation.h"

void UpdatedStorageTabInformation::serialize(Writer *output)
{
  this->serializeAs_UpdatedStorageTabInformation(output);
}

void UpdatedStorageTabInformation::serializeAs_UpdatedStorageTabInformation(Writer *output)
{
  output->writeUTF(this->name);
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << this->tabNumber << ") on element tabNumber.";
  }
  output->writeVarInt((int)this->tabNumber);
  if(this->picto < 0)
  {
    qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << this->picto << ") on element picto.";
  }
  output->writeVarInt((int)this->picto);
  output->writeShort((short)this->dropTypeLimitation.size());
  for(uint _i4 = 0; _i4 < this->dropTypeLimitation.size(); _i4++)
  {
    if(this->dropTypeLimitation[_i4] < 0)
    {
      qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << this->dropTypeLimitation[_i4] << ") on element 4 (starting at 1) of dropTypeLimitation.";
    }
    output->writeVarInt((int)this->dropTypeLimitation[_i4]);
  }
}

void UpdatedStorageTabInformation::deserialize(Reader *input)
{
  this->deserializeAs_UpdatedStorageTabInformation(input);
}

void UpdatedStorageTabInformation::deserializeAs_UpdatedStorageTabInformation(Reader *input)
{
  uint _val4 = 0;
  this->_nameFunc(input);
  this->_tabNumberFunc(input);
  this->_pictoFunc(input);
  uint _dropTypeLimitationLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _dropTypeLimitationLen; _i4++)
  {
    _val4 = input->readVarUhInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << _val4 << ") on elements of dropTypeLimitation.";
    }
    this->dropTypeLimitation.append(_val4);
  }
}

void UpdatedStorageTabInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdatedStorageTabInformation(tree);
}

void UpdatedStorageTabInformation::deserializeAsyncAs_UpdatedStorageTabInformation(FuncTree tree)
{
  tree.addChild(std::bind(&UpdatedStorageTabInformation::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdatedStorageTabInformation::_tabNumberFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&UpdatedStorageTabInformation::_pictoFunc, this, std::placeholders::_1));
  this->_dropTypeLimitationtree = tree.addChild(std::bind(&UpdatedStorageTabInformation::_dropTypeLimitationtreeFunc, this, std::placeholders::_1));
}

void UpdatedStorageTabInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void UpdatedStorageTabInformation::_tabNumberFunc(Reader *input)
{
  this->tabNumber = input->readVarUhInt();
  if(this->tabNumber < 0)
  {
    qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << this->tabNumber << ") on element of UpdatedStorageTabInformation.tabNumber.";
  }
}

void UpdatedStorageTabInformation::_pictoFunc(Reader *input)
{
  this->picto = input->readVarUhInt();
  if(this->picto < 0)
  {
    qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << this->picto << ") on element of UpdatedStorageTabInformation.picto.";
  }
}

void UpdatedStorageTabInformation::_dropTypeLimitationtreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dropTypeLimitationtree.addChild(std::bind(&UpdatedStorageTabInformation::_dropTypeLimitationFunc, this, std::placeholders::_1));
  }
}

void UpdatedStorageTabInformation::_dropTypeLimitationFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - UpdatedStorageTabInformation -"<<"Forbidden value (" << _val << ") on elements of dropTypeLimitation.";
  }
  this->dropTypeLimitation.append(_val);
}

UpdatedStorageTabInformation::UpdatedStorageTabInformation()
{
  m_types<<ClassEnum::UPDATEDSTORAGETABINFORMATION;
}

bool UpdatedStorageTabInformation::operator==(const UpdatedStorageTabInformation &compared)
{
  if(name == compared.name)
  if(tabNumber == compared.tabNumber)
  if(picto == compared.picto)
  if(dropTypeLimitation == compared.dropTypeLimitation)
  if(_dropTypeLimitationtree == compared._dropTypeLimitationtree)
  return true;
  
  return false;
}

