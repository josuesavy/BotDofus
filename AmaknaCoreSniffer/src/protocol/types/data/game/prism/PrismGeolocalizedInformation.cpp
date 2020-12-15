#include "PrismGeolocalizedInformation.h"

void PrismGeolocalizedInformation::serialize(Writer *output)
{
  this->serializeAs_PrismGeolocalizedInformation(output);
}

void PrismGeolocalizedInformation::serializeAs_PrismGeolocalizedInformation(Writer *output)
{
  PrismSubareaEmptyInfo::serializeAs_PrismSubareaEmptyInfo(output);
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldX << ") on element worldX.";
  }
  output->writeShort((short)this->worldX);
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldY << ") on element worldY.";
  }
  output->writeShort((short)this->worldY);
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeShort((short)this->prism->getTypes().last());
  this->prism->serialize(output);
}

void PrismGeolocalizedInformation::deserialize(Reader *input)
{
  this->deserializeAs_PrismGeolocalizedInformation(input);
}

void PrismGeolocalizedInformation::deserializeAs_PrismGeolocalizedInformation(Reader *input)
{
  PrismSubareaEmptyInfo::deserialize(input);
  this->_worldXFunc(input);
  this->_worldYFunc(input);
  this->_mapIdFunc(input);
  uint _id4 = input->readUShort();
  this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_id4));
  this->prism->deserialize(input);
}

void PrismGeolocalizedInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PrismGeolocalizedInformation(tree);
}

void PrismGeolocalizedInformation::deserializeAsyncAs_PrismGeolocalizedInformation(FuncTree tree)
{
  PrismSubareaEmptyInfo::deserializeAsync(tree);
  tree.addChild(std::bind(&PrismGeolocalizedInformation::_worldXFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismGeolocalizedInformation::_worldYFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&PrismGeolocalizedInformation::_mapIdFunc, this, std::placeholders::_1));
  this->_prismtree = tree.addChild(std::bind(&PrismGeolocalizedInformation::_prismtreeFunc, this, std::placeholders::_1));
}

void PrismGeolocalizedInformation::_worldXFunc(Reader *input)
{
  this->worldX = input->readShort();
  if(this->worldX < -255 || this->worldX > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldX << ") on element of PrismGeolocalizedInformation.worldX.";
  }
}

void PrismGeolocalizedInformation::_worldYFunc(Reader *input)
{
  this->worldY = input->readShort();
  if(this->worldY < -255 || this->worldY > 255)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->worldY << ") on element of PrismGeolocalizedInformation.worldY.";
  }
}

void PrismGeolocalizedInformation::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - PrismGeolocalizedInformation -"<<"Forbidden value (" << this->mapId << ") on element of PrismGeolocalizedInformation.mapId.";
  }
}

void PrismGeolocalizedInformation::_prismtreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->prism = qSharedPointerCast<PrismInformation>(ClassManagerSingleton::get()->getClass(_id));
  this->prism->deserializeAsync(this->_prismtree);
}

PrismGeolocalizedInformation::PrismGeolocalizedInformation()
{
  m_types<<ClassEnum::PRISMGEOLOCALIZEDINFORMATION;
}

bool PrismGeolocalizedInformation::operator==(const PrismGeolocalizedInformation &compared)
{
  if(worldX == compared.worldX)
  if(worldY == compared.worldY)
  if(mapId == compared.mapId)
  if(prism == compared.prism)
  if(_prismtree == compared._prismtree)
  return true;
  
  return false;
}

