#include "PaddockInformationsForSell.h"

void PaddockInformationsForSell::serialize(Writer *output)
{
  this->serializeAs_PaddockInformationsForSell(output);
}

void PaddockInformationsForSell::serializeAs_PaddockInformationsForSell(Writer *output)
{
  output->writeUTF(this->guildOwner);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element subAreaId.";
  }
  output->writeVarShort((int)this->subAreaId);
  output->writeByte(this->nbMount);
  output->writeByte(this->nbObject);
  if(this->price < 0 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->price << ") on element price.";
  }
  output->writeVarLong((double)this->price);
}

void PaddockInformationsForSell::deserialize(Reader *input)
{
  this->deserializeAs_PaddockInformationsForSell(input);
}

void PaddockInformationsForSell::deserializeAs_PaddockInformationsForSell(Reader *input)
{
  this->_guildOwnerFunc(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_subAreaIdFunc(input);
  this->_nbMountFunc(input);
  this->_nbObjectFunc(input);
  this->_priceFunc(input);
}

void PaddockInformationsForSell::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PaddockInformationsForSell(tree);
}

void PaddockInformationsForSell::deserializeAsyncAs_PaddockInformationsForSell(FuncTree tree)
{
  tree.addChild(std::bind(&PaddockInformationsForSell::_guildOwnerFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_subAreaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_nbMountFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_nbObjectFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PaddockInformationsForSell::_priceFunc, this, std::placeholders::_1));
}

void PaddockInformationsForSell::_guildOwnerFunc(Reader *input)
{
  this->guildOwner = input->readUTF();
}

void PaddockInformationsForSell::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldX << ") on element of PaddockInformationsForSell.worldX.";
  }
}

void PaddockInformationsForSell::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->worldY << ") on element of PaddockInformationsForSell.worldY.";
  }
}

void PaddockInformationsForSell::_subAreaIdFunc(Reader *input)
{
  this->subAreaId = input->readVarUhShort();
  if(this->subAreaId < 0)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->subAreaId << ") on element of PaddockInformationsForSell.subAreaId.";
  }
}

void PaddockInformationsForSell::_nbMountFunc(Reader *input)
{
  this->nbMount = input->readByte();
}

void PaddockInformationsForSell::_nbObjectFunc(Reader *input)
{
  this->nbObject = input->readByte();
}

void PaddockInformationsForSell::_priceFunc(Reader *input)
{
  this->price = input->readVarUhLong();
  if(this->price < 0 || this->price > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PaddockInformationsForSell -"<<"Forbidden value (" << this->price << ") on element of PaddockInformationsForSell.price.";
  }
}

PaddockInformationsForSell::PaddockInformationsForSell()
{
  m_types<<ClassEnum::PADDOCKINFORMATIONSFORSELL;
}

bool PaddockInformationsForSell::operator==(const PaddockInformationsForSell &compared)
{
  if(guildOwner == compared.guildOwner)
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(subAreaId == compared.subAreaId)
  if(nbMount == compared.nbMount)
  if(nbObject == compared.nbObject)
  if(price == compared.price)
  return true;
  
  return false;
}

