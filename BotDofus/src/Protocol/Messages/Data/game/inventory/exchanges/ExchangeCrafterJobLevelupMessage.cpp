#include "ExchangeCrafterJobLevelupMessage.h"

void ExchangeCrafterJobLevelupMessage::serialize(Writer *output)
{
  this->serializeAs_ExchangeCrafterJobLevelupMessage(output);
}

void ExchangeCrafterJobLevelupMessage::serializeAs_ExchangeCrafterJobLevelupMessage(Writer *output)
{
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeCrafterJobLevelupMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element crafterJobLevel.";
  }
  output->writeByte(this->crafterJobLevel);
}

void ExchangeCrafterJobLevelupMessage::deserialize(Reader *input)
{
  this->deserializeAs_ExchangeCrafterJobLevelupMessage(input);
}

void ExchangeCrafterJobLevelupMessage::deserializeAs_ExchangeCrafterJobLevelupMessage(Reader *input)
{
  this->_crafterJobLevelFunc(input);
}

void ExchangeCrafterJobLevelupMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ExchangeCrafterJobLevelupMessage(tree);
}

void ExchangeCrafterJobLevelupMessage::deserializeAsyncAs_ExchangeCrafterJobLevelupMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ExchangeCrafterJobLevelupMessage::_crafterJobLevelFunc, this, std::placeholders::_1));
}

void ExchangeCrafterJobLevelupMessage::_crafterJobLevelFunc(Reader *input)
{
  this->crafterJobLevel = input->readUByte();
  if(this->crafterJobLevel < 0 || this->crafterJobLevel > 255)
  {
    qDebug()<<"ERREUR - ExchangeCrafterJobLevelupMessage -"<<"Forbidden value (" << this->crafterJobLevel << ") on element of ExchangeCrafterJobLevelupMessage.crafterJobLevel.";
  }
}

ExchangeCrafterJobLevelupMessage::ExchangeCrafterJobLevelupMessage()
{
  m_type = MessageEnum::EXCHANGECRAFTERJOBLEVELUPMESSAGE;
}

