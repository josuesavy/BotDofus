#include "AllianceInsiderPrismInformation.h"

void AllianceInsiderPrismInformation::serialize(Writer *output)
{
  this->serializeAs_AllianceInsiderPrismInformation(output);
}

void AllianceInsiderPrismInformation::serializeAs_AllianceInsiderPrismInformation(Writer *output)
{
  PrismInformation::serializeAs_PrismInformation(output);
  if(this->lastTimeSlotModificationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationDate << ") on element lastTimeSlotModificationDate.";
  }
  output->writeInt((int)this->lastTimeSlotModificationDate);
  if(this->lastTimeSlotModificationAuthorGuildId < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorGuildId << ") on element lastTimeSlotModificationAuthorGuildId.";
  }
  output->writeVarInt((int)this->lastTimeSlotModificationAuthorGuildId);
  if(this->lastTimeSlotModificationAuthorId < 0 || this->lastTimeSlotModificationAuthorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorId << ") on element lastTimeSlotModificationAuthorId.";
  }
  output->writeVarLong((double)this->lastTimeSlotModificationAuthorId);
  output->writeUTF(this->lastTimeSlotModificationAuthorName);
  output->writeShort((short)this->modulesObjects.size());
  for(uint _i5 = 0; _i5 < this->modulesObjects.size(); _i5++)
  {
    qSharedPointerCast<ObjectItem>(this->modulesObjects[_i5])->serializeAs_ObjectItem(output);
  }
}

void AllianceInsiderPrismInformation::deserialize(Reader *input)
{
  this->deserializeAs_AllianceInsiderPrismInformation(input);
}

void AllianceInsiderPrismInformation::deserializeAs_AllianceInsiderPrismInformation(Reader *input)
{
  QSharedPointer<ObjectItem> _item5 ;
  PrismInformation::deserialize(input);
  this->_lastTimeSlotModificationDateFunc(input);
  this->_lastTimeSlotModificationAuthorGuildIdFunc(input);
  this->_lastTimeSlotModificationAuthorIdFunc(input);
  this->_lastTimeSlotModificationAuthorNameFunc(input);
  uint _modulesObjectsLen = input->readUShort();
  for(uint _i5 = 0; _i5 < _modulesObjectsLen; _i5++)
  {
    _item5 = QSharedPointer<ObjectItem>(new ObjectItem() );
    _item5->deserialize(input);
    this->modulesObjects.append(_item5);
  }
}

void AllianceInsiderPrismInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceInsiderPrismInformation(tree);
}

void AllianceInsiderPrismInformation::deserializeAsyncAs_AllianceInsiderPrismInformation(FuncTree tree)
{
  PrismInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_lastTimeSlotModificationDateFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorGuildIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorNameFunc, this, std::placeholders::_1));
  this->_modulesObjectstree = tree.addChild(std::bind(&AllianceInsiderPrismInformation::_modulesObjectstreeFunc, this, std::placeholders::_1));
}

void AllianceInsiderPrismInformation::_lastTimeSlotModificationDateFunc(Reader *input)
{
  this->lastTimeSlotModificationDate = input->readInt();
  if(this->lastTimeSlotModificationDate < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationDate << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationDate.";
  }
}

void AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorGuildIdFunc(Reader *input)
{
  this->lastTimeSlotModificationAuthorGuildId = input->readVarUhInt();
  if(this->lastTimeSlotModificationAuthorGuildId < 0)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorGuildId << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationAuthorGuildId.";
  }
}

void AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorIdFunc(Reader *input)
{
  this->lastTimeSlotModificationAuthorId = input->readVarUhLong();
  if(this->lastTimeSlotModificationAuthorId < 0 || this->lastTimeSlotModificationAuthorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - AllianceInsiderPrismInformation -"<<"Forbidden value (" << this->lastTimeSlotModificationAuthorId << ") on element of AllianceInsiderPrismInformation.lastTimeSlotModificationAuthorId.";
  }
}

void AllianceInsiderPrismInformation::_lastTimeSlotModificationAuthorNameFunc(Reader *input)
{
  this->lastTimeSlotModificationAuthorName = input->readUTF();
}

void AllianceInsiderPrismInformation::_modulesObjectstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_modulesObjectstree.addChild(std::bind(&AllianceInsiderPrismInformation::_modulesObjectsFunc, this, std::placeholders::_1));
  }
}

void AllianceInsiderPrismInformation::_modulesObjectsFunc(Reader *input)
{
  QSharedPointer<ObjectItem> _item = QSharedPointer<ObjectItem>(new ObjectItem() );
  _item->deserialize(input);
  this->modulesObjects.append(_item);
}

AllianceInsiderPrismInformation::AllianceInsiderPrismInformation()
{
  m_types<<ClassEnum::ALLIANCEINSIDERPRISMINFORMATION;
}

bool AllianceInsiderPrismInformation::operator==(const AllianceInsiderPrismInformation &compared)
{
  if(lastTimeSlotModificationDate == compared.lastTimeSlotModificationDate)
  if(lastTimeSlotModificationAuthorGuildId == compared.lastTimeSlotModificationAuthorGuildId)
  if(lastTimeSlotModificationAuthorId == compared.lastTimeSlotModificationAuthorId)
  if(lastTimeSlotModificationAuthorName == compared.lastTimeSlotModificationAuthorName)
  if(modulesObjects == compared.modulesObjects)
  if(_modulesObjectstree == compared._modulesObjectstree)
  return true;
  
  return false;
}

