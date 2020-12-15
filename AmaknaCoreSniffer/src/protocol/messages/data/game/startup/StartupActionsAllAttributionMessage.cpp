#include "StartupActionsAllAttributionMessage.h"

void StartupActionsAllAttributionMessage::serialize(Writer *output)
{
  this->serializeAs_StartupActionsAllAttributionMessage(output);
}

void StartupActionsAllAttributionMessage::serializeAs_StartupActionsAllAttributionMessage(Writer *output)
{
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsAllAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element characterId.";
  }
  output->writeVarLong((double)this->characterId);
}

void StartupActionsAllAttributionMessage::deserialize(Reader *input)
{
  this->deserializeAs_StartupActionsAllAttributionMessage(input);
}

void StartupActionsAllAttributionMessage::deserializeAs_StartupActionsAllAttributionMessage(Reader *input)
{
  this->_characterIdFunc(input);
}

void StartupActionsAllAttributionMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_StartupActionsAllAttributionMessage(tree);
}

void StartupActionsAllAttributionMessage::deserializeAsyncAs_StartupActionsAllAttributionMessage(FuncTree tree)
{
  tree.addChild(std::bind(&StartupActionsAllAttributionMessage::_characterIdFunc, this, std::placeholders::_1));
}

void StartupActionsAllAttributionMessage::_characterIdFunc(Reader *input)
{
  this->characterId = input->readVarUhLong();
  if(this->characterId < 0 || this->characterId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - StartupActionsAllAttributionMessage -"<<"Forbidden value (" << this->characterId << ") on element of StartupActionsAllAttributionMessage.characterId.";
  }
}

StartupActionsAllAttributionMessage::StartupActionsAllAttributionMessage()
{
  m_type = MessageEnum::STARTUPACTIONSALLATTRIBUTIONMESSAGE;
}

