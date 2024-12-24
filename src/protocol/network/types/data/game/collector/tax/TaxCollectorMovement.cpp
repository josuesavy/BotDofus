#include "TaxCollectorMovement.h"

void TaxCollectorMovement::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorMovement(output);
}

void TaxCollectorMovement::serializeAs_TaxCollectorMovement(Writer *output)
{
  output->writeByte(this->movementType);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(output);
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
}

void TaxCollectorMovement::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorMovement(input);
}

void TaxCollectorMovement::deserializeAs_TaxCollectorMovement(Reader *input)
{
  this->_movementTypeFunc(input);
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
}

void TaxCollectorMovement::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorMovement(tree);
}

void TaxCollectorMovement::deserializeAsyncAs_TaxCollectorMovement(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorMovement::_movementTypeFunc, this, std::placeholders::_1));
  this->_basicInfostree = tree.addChild(std::bind(&TaxCollectorMovement::_basicInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorMovement::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorMovement::_playerNameFunc, this, std::placeholders::_1));
}

void TaxCollectorMovement::_movementTypeFunc(Reader *input)
{
  this->movementType = input->readByte();
  if(this->movementType < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->movementType << ") on element of TaxCollectorMovement.movementType.";
  }
}

void TaxCollectorMovement::_basicInfostreeFunc(Reader *input)
{
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserializeAsync(this->_basicInfostree);
}

void TaxCollectorMovement::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9007199254740992)
  {
    qDebug()<<"ERREUR - TaxCollectorMovement -"<<"Forbidden value (" << this->playerId << ") on element of TaxCollectorMovement.playerId.";
  }
}

void TaxCollectorMovement::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

TaxCollectorMovement::TaxCollectorMovement()
{
  m_types<<ClassEnum::TAXCOLLECTORMOVEMENT;
}

bool TaxCollectorMovement::operator==(const TaxCollectorMovement &compared)
{
  if(movementType == compared.movementType)
  if(basicInfos == compared.basicInfos)
  if(playerId == compared.playerId)
  if(playerName == compared.playerName)
  if(_basicInfostree == compared._basicInfostree)
  return true;
  
  return false;
}

