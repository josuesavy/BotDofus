#include "GameActionFightDispellEffectMessage.h"

void GameActionFightDispellEffectMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightDispellEffectMessage(output);
}

void GameActionFightDispellEffectMessage::serializeAs_GameActionFightDispellEffectMessage(Writer *output)
{
  GameActionFightDispellMessage::serializeAs_GameActionFightDispellMessage(output);
  if(this->boostUID < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellEffectMessage -"<<"Forbidden value (" << this->boostUID << ") on element boostUID.";
  }
  output->writeInt((int)this->boostUID);
}

void GameActionFightDispellEffectMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightDispellEffectMessage(input);
}

void GameActionFightDispellEffectMessage::deserializeAs_GameActionFightDispellEffectMessage(Reader *input)
{
  GameActionFightDispellMessage::deserialize(input);
  this->_boostUIDFunc(input);
}

void GameActionFightDispellEffectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightDispellEffectMessage(tree);
}

void GameActionFightDispellEffectMessage::deserializeAsyncAs_GameActionFightDispellEffectMessage(FuncTree tree)
{
  GameActionFightDispellMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GameActionFightDispellEffectMessage::_boostUIDFunc, this, std::placeholders::_1));
}

void GameActionFightDispellEffectMessage::_boostUIDFunc(Reader *input)
{
  this->boostUID = input->readInt();
  if(this->boostUID < 0)
  {
    qDebug()<<"ERREUR - GameActionFightDispellEffectMessage -"<<"Forbidden value (" << this->boostUID << ") on element of GameActionFightDispellEffectMessage.boostUID.";
  }
}

GameActionFightDispellEffectMessage::GameActionFightDispellEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTDISPELLEFFECTMESSAGE;
}

