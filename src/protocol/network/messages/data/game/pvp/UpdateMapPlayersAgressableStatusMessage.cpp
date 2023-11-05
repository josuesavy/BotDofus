#include "UpdateMapPlayersAgressableStatusMessage.h"

void UpdateMapPlayersAgressableStatusMessage::serialize(Writer *output)
{
  this->serializeAs_UpdateMapPlayersAgressableStatusMessage(output);
}

void UpdateMapPlayersAgressableStatusMessage::serializeAs_UpdateMapPlayersAgressableStatusMessage(Writer *output)
{
  output->writeShort((short)this->playerAvAMessages.size());
  for(uint _i1 = 0; _i1 < this->playerAvAMessages.size(); _i1++)
  {
    (this->playerAvAMessages[_i1]).serializeAs_AgressableStatusMessage(output);
  }
}

void UpdateMapPlayersAgressableStatusMessage::deserialize(Reader *input)
{
  this->deserializeAs_UpdateMapPlayersAgressableStatusMessage(input);
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAs_UpdateMapPlayersAgressableStatusMessage(Reader *input)
{
  AgressableStatusMessage _item1 ;
  uint _playerAvAMessagesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _playerAvAMessagesLen; _i1++)
  {
    _item1 = AgressableStatusMessage();
    _item1.deserialize(input);
    this->playerAvAMessages.append(_item1);
  }
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_UpdateMapPlayersAgressableStatusMessage(tree);
}

void UpdateMapPlayersAgressableStatusMessage::deserializeAsyncAs_UpdateMapPlayersAgressableStatusMessage(FuncTree tree)
{
  this->_playerAvAMessagestree = tree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_playerAvAMessagestreeFunc, this, std::placeholders::_1));
}

void UpdateMapPlayersAgressableStatusMessage::_playerAvAMessagestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_playerAvAMessagestree.addChild(std::bind(&UpdateMapPlayersAgressableStatusMessage::_playerAvAMessagesFunc, this, std::placeholders::_1));
  }
}

void UpdateMapPlayersAgressableStatusMessage::_playerAvAMessagesFunc(Reader *input)
{
  AgressableStatusMessage _item = AgressableStatusMessage();
  _item.deserialize(input);
  this->playerAvAMessages.append(_item);
}

UpdateMapPlayersAgressableStatusMessage::UpdateMapPlayersAgressableStatusMessage()
{
  m_type = MessageEnum::UPDATEMAPPLAYERSAGRESSABLESTATUSMESSAGE;
}

