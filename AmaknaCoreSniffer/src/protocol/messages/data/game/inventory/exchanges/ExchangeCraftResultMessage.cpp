#include "ExchangeCraftResultMessage.h"

void ExchangeCraftResultMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCraftResultMessage(output);
}

void ExchangeCraftResultMessage::serializeAs_ExchangeCraftResultMessage(Writer *output)
{
  output->writeByte(this->craftResult);
}

void ExchangeCraftResultMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCraftResultMessage(input);
}

void ExchangeCraftResultMessage::deserializeAs_ExchangeCraftResultMessage(Reader *input)
{
  this->_craftResultFunc(input);
}

void ExchangeCraftResultMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCraftResultMessage(tree);
}

void ExchangeCraftResultMessage::deserializeAsyncAs_ExchangeCraftResultMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCraftResultMessage::_craftResultFunc, this, std::placeholders::_1));
}

void ExchangeCraftResultMessage::_craftResultFunc(Reader *input)
{
  this->craftResult = input->readByte();
  if(this->craftResult < 0)
  {
    qDebug()<<"ERREUR - ExchangeCraftResultMessage -"<<"Forbidden value (" << this->craftResult << ") on element of ExchangeCraftResultMessage.craftResult.";
  }
}

ExchangeCraftResultMessage::ExchangeCraftResultMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTRESULTMESSAGE;
}

