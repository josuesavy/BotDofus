#include "ShowCellSpectatorMessage.h"

void ShowCellSpectatorMessage::serialize(Writer *output)
{
  this->serializeAs_ShowCellSpectatorMessage(output);
}

void ShowCellSpectatorMessage::serializeAs_ShowCellSpectatorMessage(Writer *output)
{
  ShowCellMessage::serializeAs_ShowCellMessage(output);
  output->writeUTF(this->playerName);
}

void ShowCellSpectatorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ShowCellSpectatorMessage(input);
}

void ShowCellSpectatorMessage::deserializeAs_ShowCellSpectatorMessage(Reader *input)
{
  ShowCellMessage::deserialize(input);
  this->_playerNameFunc(input);
}

void ShowCellSpectatorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ShowCellSpectatorMessage(tree);
}

void ShowCellSpectatorMessage::deserializeAsyncAs_ShowCellSpectatorMessage(FuncTree tree)
{
  ShowCellMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&ShowCellSpectatorMessage::_playerNameFunc, this, std::placeholders::_1));
}

void ShowCellSpectatorMessage::_playerNameFunc(Reader *input)
{
  this->playerName = input->readUTF();
}

ShowCellSpectatorMessage::ShowCellSpectatorMessage()
{
  m_type = MessageEnum::SHOWCELLSPECTATORMESSAGE;
}

