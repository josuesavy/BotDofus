#include "GameActionFightTackledMessage.h"

void GameActionFightTackledMessage::serialize(Writer *output)
{
  this->serializeAs_GameActionFightTackledMessage(output);
}

void GameActionFightTackledMessage::serializeAs_GameActionFightTackledMessage(Writer *output)
{
  AbstractGameActionMessage::serializeAs_AbstractGameActionMessage(output);
  output->writeShort((short)this->tacklersIds.size());
  for(uint _i1 = 0; _i1 < this->tacklersIds.size(); _i1++)
  {
    if(this->tacklersIds[_i1] < -9007199254740992 || this->tacklersIds[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - GameActionFightTackledMessage -"<<"Forbidden value (" << this->tacklersIds[_i1] << ") on element 1 (starting at 1) of tacklersIds.";
    }
    output->writeDouble(this->tacklersIds[_i1]);
  }
}

void GameActionFightTackledMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameActionFightTackledMessage(input);
}

void GameActionFightTackledMessage::deserializeAs_GameActionFightTackledMessage(Reader *input)
{
  double _val1 = NULL;
  AbstractGameActionMessage::deserialize(input);
  uint _tacklersIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _tacklersIdsLen; _i1++)
  {
    _val1 = Number(input->readDouble());
    if(_val1 < -9007199254740992 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - GameActionFightTackledMessage -"<<"Forbidden value (" << _val1 << ") on elements of tacklersIds.";
    }
    this->tacklersIds.append(_val1);
  }
}

void GameActionFightTackledMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameActionFightTackledMessage(tree);
}

void GameActionFightTackledMessage::deserializeAsyncAs_GameActionFightTackledMessage(FuncTree tree)
{
  AbstractGameActionMessage::deserializeAsync(tree);
  this->_tacklersIdstree = tree.addChild(std::bind(&GameActionFightTackledMessage::_tacklersIdstreeFunc, this, std::placeholders::_1));
}

void GameActionFightTackledMessage::_tacklersIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_tacklersIdstree.addChild(std::bind(&GameActionFightTackledMessage::_tacklersIdsFunc, this, std::placeholders::_1));
  }
}

void GameActionFightTackledMessage::_tacklersIdsFunc(Reader *input)
{
  double _val = Number(input->readDouble());
  if(_val < -9007199254740992 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - GameActionFightTackledMessage -"<<"Forbidden value (" << _val << ") on elements of tacklersIds.";
  }
  this->tacklersIds.append(_val);
}

GameActionFightTackledMessage::GameActionFightTackledMessage()
{
  m_type = MessageEnum::GAMEACTIONFIGHTTACKLEDMESSAGE;
}

