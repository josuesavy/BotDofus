#include "PartyGuestInformations.h"

void PartyGuestInformations::serialize(Writer *output)
{
  this->serializeAs_PartyGuestInformations(output);
}

void PartyGuestInformations::serializeAs_PartyGuestInformations(Writer *output)
{
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->guestId << ") on element guestId.";
  }
  output->writeVarLong((double)this->guestId);
  if(this->hostId < 0 || this->hostId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->hostId << ") on element hostId.";
  }
  output->writeVarLong((double)this->hostId);
  output->writeUTF(this->name);
  this->guestLook.serializeAs_EntityLook(output);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  output->writeShort((short)this->status->getTypes().last());
  this->status->serialize(output);
  output->writeShort((short)this->entities.size());
  for(uint _i8 = 0; _i8 < this->entities.size(); _i8++)
  {
    qSharedPointerCast<PartyEntityBaseInformation>(this->entities[_i8])->serializeAs_PartyEntityBaseInformation(output);
  }
}

void PartyGuestInformations::deserialize(Reader *input)
{
  this->deserializeAs_PartyGuestInformations(input);
}

void PartyGuestInformations::deserializeAs_PartyGuestInformations(Reader *input)
{
  QSharedPointer<PartyEntityBaseInformation> _item8 ;
  this->_guestIdFunc(input);
  this->_hostIdFunc(input);
  this->_nameFunc(input);
  this->guestLook = EntityLook();
  this->guestLook.deserialize(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  uint _id7 = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id7));
  this->status->deserialize(input);
  uint _entitiesLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _entitiesLen; _i8++)
  {
    _item8 = QSharedPointer<PartyEntityBaseInformation>(new PartyEntityBaseInformation() );
    _item8->deserialize(input);
    this->entities.append(_item8);
  }
}

void PartyGuestInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PartyGuestInformations(tree);
}

void PartyGuestInformations::deserializeAsyncAs_PartyGuestInformations(FuncTree tree)
{
  tree.addChild(std::bind(&PartyGuestInformations::_guestIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyGuestInformations::_hostIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyGuestInformations::_nameFunc, this, std::placeholders::_1));
  this->_guestLooktree = tree.addChild(std::bind(&PartyGuestInformations::_guestLooktreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyGuestInformations::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PartyGuestInformations::_sexFunc, this, std::placeholders::_1));
  this->_statustree = tree.addChild(std::bind(&PartyGuestInformations::_statustreeFunc, this, std::placeholders::_1));
  this->_entitiestree = tree.addChild(std::bind(&PartyGuestInformations::_entitiestreeFunc, this, std::placeholders::_1));
}

void PartyGuestInformations::_guestIdFunc(Reader *input)
{
  this->guestId = input->readVarUhLong();
  if(this->guestId < 0 || this->guestId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->guestId << ") on element of PartyGuestInformations.guestId.";
  }
}

void PartyGuestInformations::_hostIdFunc(Reader *input)
{
  this->hostId = input->readVarUhLong();
  if(this->hostId < 0 || this->hostId > 9007199254740992)
  {
    qDebug()<<"ERREUR - PartyGuestInformations -"<<"Forbidden value (" << this->hostId << ") on element of PartyGuestInformations.hostId.";
  }
}

void PartyGuestInformations::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void PartyGuestInformations::_guestLooktreeFunc(Reader *input)
{
  this->guestLook = EntityLook();
  this->guestLook.deserializeAsync(this->_guestLooktree);
}

void PartyGuestInformations::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
}

void PartyGuestInformations::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void PartyGuestInformations::_statustreeFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  this->status = qSharedPointerCast<PlayerStatus>(ClassManagerSingleton::get()->getClass(_id));
  this->status->deserializeAsync(this->_statustree);
}

void PartyGuestInformations::_entitiestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_entitiestree.addChild(std::bind(&PartyGuestInformations::_entitiesFunc, this, std::placeholders::_1));
  }
}

void PartyGuestInformations::_entitiesFunc(Reader *input)
{
  QSharedPointer<PartyEntityBaseInformation> _item = QSharedPointer<PartyEntityBaseInformation>(new PartyEntityBaseInformation() );
  _item->deserialize(input);
  this->entities.append(_item);
}

PartyGuestInformations::PartyGuestInformations()
{
  m_types<<ClassEnum::PARTYGUESTINFORMATIONS;
}

bool PartyGuestInformations::operator==(const PartyGuestInformations &compared)
{
  if(guestId == compared.guestId)
  if(hostId == compared.hostId)
  if(name == compared.name)
  if(guestLook == compared.guestLook)
  if(breed == compared.breed)
  if(sex == compared.sex)
  if(status == compared.status)
  if(entities == compared.entities)
  if(_guestLooktree == compared._guestLooktree)
  if(_statustree == compared._statustree)
  if(_entitiestree == compared._entitiestree)
  return true;
  
  return false;
}

