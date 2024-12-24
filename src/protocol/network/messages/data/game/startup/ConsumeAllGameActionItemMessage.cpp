#include "ConsumeAllGameActionItemMessage.h"

void ConsumeAllGameActionItemMessage::serialize(Writer *output)
{
  this->serializeAs_ConsumeAllGameActionItemMessage(output);
}

void ConsumeAllGameActionItemMessage::serializeAs_ConsumeAllGameActionItemMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ConsumeAllGameActionItemMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void ConsumeAllGameActionItemMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConsumeAllGameActionItemMessage(input);
}

void ConsumeAllGameActionItemMessage::deserializeAs_ConsumeAllGameActionItemMessage(Reader *input)
{
  this->_characterIdFunc(input);
}

void ConsumeAllGameActionItemMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConsumeAllGameActionItemMessage(tree);
}

void ConsumeAllGameActionItemMessage::deserializeAsyncAs_ConsumeAllGameActionItemMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ConsumeAllGameActionItemMessage::_characterIdFunc, this, std::placeholders::_1));
}

void ConsumeAllGameActionItemMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ConsumeAllGameActionItemMessage -"<<"Forbidden value (" << this->characterId << ") on element of ConsumeAllGameActionItemMessage.characterId.";
  }
}

ConsumeAllGameActionItemMessage::ConsumeAllGameActionItemMessage()
{
  m_type = MessageEnum::CONSUMEALLGAMEACTIONITEMMESSAGE;
}

