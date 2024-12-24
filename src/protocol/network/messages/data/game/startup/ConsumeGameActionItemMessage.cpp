#include "ConsumeGameActionItemMessage.h"

void ConsumeGameActionItemMessage::serialize(Writer *output)
{
  this->serializeAs_ConsumeGameActionItemMessage(output);
}

void ConsumeGameActionItemMessage::serializeAs_ConsumeGameActionItemMessage(Writer *output)
{
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ConsumeGameActionItemMessage -"<<"Forbidden value (" << this->actionId << ") on element actionId.";
  }
  output->writeInt((int)this->actionId);
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ConsumeGameActionItemMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void ConsumeGameActionItemMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConsumeGameActionItemMessage(input);
}

void ConsumeGameActionItemMessage::deserializeAs_ConsumeGameActionItemMessage(Reader *input)
{
  this->_actionIdFunc(input);
  this->_characterIdFunc(input);
}

void ConsumeGameActionItemMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConsumeGameActionItemMessage(tree);
}

void ConsumeGameActionItemMessage::deserializeAsyncAs_ConsumeGameActionItemMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ConsumeGameActionItemMessage::_actionIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ConsumeGameActionItemMessage::_characterIdFunc, this, std::placeholders::_1));
}

void ConsumeGameActionItemMessage::_actionIdFunc(Reader *input)
{
  this->actionId = input->readInt();
  if(this->actionId < 0)
  {
    qDebug()<<"ERREUR - ConsumeGameActionItemMessage -"<<"Forbidden value (" << this->actionId << ") on element of ConsumeGameActionItemMessage.actionId.";
  }
}

void ConsumeGameActionItemMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ConsumeGameActionItemMessage -"<<"Forbidden value (" << this->characterId << ") on element of ConsumeGameActionItemMessage.characterId.";
  }
}

ConsumeGameActionItemMessage::ConsumeGameActionItemMessage()
{
  m_type = MessageEnum::CONSUMEGAMEACTIONITEMMESSAGE;
}

