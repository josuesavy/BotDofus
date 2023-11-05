#include "TreasureHuntFlag.h"

void TreasureHuntFlag::serialize(Writer *output)
{
  this->serializeAs_TreasureHuntFlag(output);
}

void TreasureHuntFlag::serializeAs_TreasureHuntFlag(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TreasureHuntFlag -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
  output->writeByte(this->state);
}

void TreasureHuntFlag::deserialize(Reader *input)
{
  this->deserializeAs_TreasureHuntFlag(input);
}

void TreasureHuntFlag::deserializeAs_TreasureHuntFlag(Reader *input)
{
  this->_mapIdFunc(input);
  this->_stateFunc(input);
}

void TreasureHuntFlag::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TreasureHuntFlag(tree);
}

void TreasureHuntFlag::deserializeAsyncAs_TreasureHuntFlag(FuncTree tree)
{
  tree.addChild(std::bind(&TreasureHuntFlag::_mapIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TreasureHuntFlag::_stateFunc, this, std::placeholders::_1));
}

void TreasureHuntFlag::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TreasureHuntFlag -"<<"Forbidden value (" << this->mapId << ") on element of TreasureHuntFlag.mapId.";
  }
}

void TreasureHuntFlag::_stateFunc(Reader *input)
{
  this->state = input->readByte();
  if(this->state < 0)
  {
    qDebug()<<"ERREUR - TreasureHuntFlag -"<<"Forbidden value (" << this->state << ") on element of TreasureHuntFlag.state.";
  }
}

TreasureHuntFlag::TreasureHuntFlag()
{
  m_types<<ClassEnum::TREASUREHUNTFLAG;
}

bool TreasureHuntFlag::operator==(const TreasureHuntFlag &compared)
{
  if(mapId == compared.mapId)
  if(state == compared.state)
  return true;
  
  return false;
}

