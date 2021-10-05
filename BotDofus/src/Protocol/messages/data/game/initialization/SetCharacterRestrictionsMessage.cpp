#include "SetCharacterRestrictionsMessage.h"

void SetCharacterRestrictionsMessage::serialize(Writer *output)
{
  this->serializeAs_SetCharacterRestrictionsMessage(output);
}

void SetCharacterRestrictionsMessage::serializeAs_SetCharacterRestrictionsMessage(Writer *output)
{
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SetCharacterRestrictionsMessage -"<<"Forbidden value (" << this->actorId << ") on element actorId.";
  }
  output->writeDouble(this->actorId);
  this->restrictions.serializeAs_ActorRestrictionsInformations(output);
}

void SetCharacterRestrictionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_SetCharacterRestrictionsMessage(input);
}

void SetCharacterRestrictionsMessage::deserializeAs_SetCharacterRestrictionsMessage(Reader *input)
{
  this->_actorIdFunc(input);
  this->restrictions = ActorRestrictionsInformations();
  this->restrictions.deserialize(input);
}

void SetCharacterRestrictionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SetCharacterRestrictionsMessage(tree);
}

void SetCharacterRestrictionsMessage::deserializeAsyncAs_SetCharacterRestrictionsMessage(FuncTree tree)
{
  tree.addChild(std::bind(&SetCharacterRestrictionsMessage::_actorIdFunc, this, std::placeholders::_1));
  this->_restrictionstree = tree.addChild(std::bind(&SetCharacterRestrictionsMessage::_restrictionstreeFunc, this, std::placeholders::_1));
}

void SetCharacterRestrictionsMessage::_actorIdFunc(Reader *input)
{
  this->actorId = input->readDouble();
  if(this->actorId < -9.007199254740992E15 || this->actorId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - SetCharacterRestrictionsMessage -"<<"Forbidden value (" << this->actorId << ") on element of SetCharacterRestrictionsMessage.actorId.";
  }
}

void SetCharacterRestrictionsMessage::_restrictionstreeFunc(Reader *input)
{
  this->restrictions = ActorRestrictionsInformations();
  this->restrictions.deserializeAsync(this->_restrictionstree);
}

SetCharacterRestrictionsMessage::SetCharacterRestrictionsMessage()
{
  m_type = MessageEnum::SETCHARACTERRESTRICTIONSMESSAGE;
}

