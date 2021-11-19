#include "TaxCollectorMovementMessage.h"

void TaxCollectorMovementMessage::serialize(Writer *output)
{
  this->serializeAs_TaxCollectorMovementMessage(output);
}

void TaxCollectorMovementMessage::serializeAs_TaxCollectorMovementMessage(Writer *output)
{
  output->writeByte(this->movementType);
  this->basicInfos.serializeAs_TaxCollectorBasicInformations(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
  output->writeUTF(this->playerName);
}

void TaxCollectorMovementMessage::deserialize(Reader *input)
{
  this->deserializeAs_TaxCollectorMovementMessage(input);
}

void TaxCollectorMovementMessage::deserializeAs_TaxCollectorMovementMessage(Reader *input)
{
  this->_movementTypeFunc(input);
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserialize(input);
  this->_playerIdFunc(input);
  this->_playerNameFunc(input);
}

void TaxCollectorMovementMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_TaxCollectorMovementMessage(tree);
}

void TaxCollectorMovementMessage::deserializeAsyncAs_TaxCollectorMovementMessage(FuncTree tree)
{
  tree.addChild(std::bind(&TaxCollectorMovementMessage::_movementTypeFunc, this, std::placeholders::_1));
  this->_basicInfostree = tree.addChild(std::bind(&TaxCollectorMovementMessage::_basicInfostreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorMovementMessage::_playerIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&TaxCollectorMovementMessage::_playerNameFunc, this, std::placeholders::_1));
}

void TaxCollectorMovementMessage::_movementTypeFunc(Reader *input)
{
  this->movementType = input->readByte();
  if(this->movementType < 0)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->movementType << ") on element of TaxCollectorMovementMessage.movementType.";
  }
}

void TaxCollectorMovementMessage::_basicInfostreeFunc(Reader *input)
{
  this->basicInfos = TaxCollectorBasicInformations();
  this->basicInfos.deserializeAsync(this->_basicInfostree);
}

void TaxCollectorMovementMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - TaxCollectorMovementMessage -"<<"Forbidden value (" << this->playerId << ") on element of TaxCollectorMovementMessage.playerId.";
  }
}

void TaxCollectorMovementMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

TaxCollectorMovementMessage::TaxCollectorMovementMessage()
{
  m_type = MessageEnum::TAXCOLLECTORMOVEMENTMESSAGE;
}

