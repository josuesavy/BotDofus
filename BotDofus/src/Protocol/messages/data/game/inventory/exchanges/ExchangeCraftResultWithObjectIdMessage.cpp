#include "ExchangeCraftResultWithObjectIdMessage.h"

void ExchangeCraftResultWithObjectIdMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftResultWithObjectIdMessage(output);
}

void ExchangeCraftResultWithObjectIdMessage::serializeAs_ExchangeCraftResultWithObjectIdMessage(Writer *output)
{
  ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(output);
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultWithObjectIdMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element objectGenericId.";
  }
  output->writeVarShort((int)this->objectGenericId);
}

void ExchangeCraftResultWithObjectIdMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftResultWithObjectIdMessage(input);
}

void ExchangeCraftResultWithObjectIdMessage::deserializeAs_ExchangeCraftResultWithObjectIdMessage(Reader *input)
{
  ExchangeCraftResultMessage::deserialize(input);
  this->_objectGenericIdFunc(input);
}

void ExchangeCraftResultWithObjectIdMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftResultWithObjectIdMessage(tree);
}

void ExchangeCraftResultWithObjectIdMessage::deserializeAsyncAs_ExchangeCraftResultWithObjectIdMessage(FuncTree tree)
{
  ExchangeCraftResultMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ExchangeCraftResultWithObjectIdMessage::_objectGenericIdFunc, this, std::placeholders::_1));
}

void ExchangeCraftResultWithObjectIdMessage::_objectGenericIdFunc(Reader *input)
{
  this->objectGenericId = input->readVarUhShort();
  if(this->objectGenericId < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultWithObjectIdMessage -"<<"Forbidden value (" << this->objectGenericId << ") on element of ExchangeCraftResultWithObjectIdMessage.objectGenericId.";
  }
}

ExchangeCraftResultWithObjectIdMessage::ExchangeCraftResultWithObjectIdMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTWITHOBJECTIDMESSAGE;
}

