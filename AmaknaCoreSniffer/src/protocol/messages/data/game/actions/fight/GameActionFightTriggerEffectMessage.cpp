#include "GameActionFightTriggerEffectMessage.h"

void GameActionFightTriggerEffectMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightTriggerEffectMessage(output);
}

void GameActionFightTriggerEffectMessage::serializeAs_GameActionFightTriggerEffectMessage(Writer *output)
{
  GameActionFightDispellEffectMessage::serializeAs_GameActionFightDispellEffectMessage(output);
}

void GameActionFightTriggerEffectMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightTriggerEffectMessage(input);
}

void GameActionFightTriggerEffectMessage::deserializeAs_GameActionFightTriggerEffectMessage(Reader *input)
{
  GameActionFightDispellEffectMessage::deserialize(input);
}

void GameActionFightTriggerEffectMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightTriggerEffectMessage(tree);
}

void GameActionFightTriggerEffectMessage::deserializeAsyncAs_GameActionFightTriggerEffectMessage(FuncTree tree)
{
  GameActionFightDispellEffectMessage::deserializeAsync(tree);
}

GameActionFightTriggerEffectMessage::GameActionFightTriggerEffectMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTRIGGEREFFECTMESSAGE;
}

