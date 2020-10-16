#include "ExchangeCraftInformationObjectMessage.h"

void ExchangeCraftInformationObjectMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftInformationObjectMessage(output);
}

void ExchangeCraftInformationObjectMessage::serializeAs_ExchangeCraftInformationObjectMessage(Writer *output)
{
  ExchangeCraftResultWithObjectIdMessage::serializeAs_ExchangeCraftResultWithObjectIdMessage(output);
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeCraftInformationObjectMessage -"<<"Forbidden value (" << this->playerId << ") on element playerId.";
  }
  output->writeVarLong((double)this->playerId);
}

void ExchangeCraftInformationObjectMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftInformationObjectMessage(input);
}

void ExchangeCraftInformationObjectMessage::deserializeAs_ExchangeCraftInformationObjectMessage(Reader *input)
{
  ExchangeCraftResultWithObjectIdMessage::deserialize(input);
  this->_playerIdFunc(input);
}

void ExchangeCraftInformationObjectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftInformationObjectMessage(tree);
}

void ExchangeCraftInformationObjectMessage::deserializeAsyncAs_ExchangeCraftInformationObjectMessage(FuncTree tree)
{
  ExchangeCraftResultWithObjectIdMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeCraftInformationObjectMessage::_playerIdFunc, this, std::placeholders::_1));
}

void ExchangeCraftInformationObjectMessage::_playerIdFunc(Reader *input)
{
  this->playerId = input->readVarUhLong();
  if(this->playerId < 0 || this->playerId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - ExchangeCraftInformationObjectMessage -"<<"Forbidden value (" << this->playerId << ") on element of ExchangeCraftInformationObjectMessage.playerId.";
  }
}

ExchangeCraftInformationObjectMessage::ExchangeCraftInformationObjectMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTINFORMATIONOBJECTMESSAGE;
}

