#include "GameFightStartMessage.h"

void GameFightStartMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightStartMessage(output);
}

void GameFightStartMessage::serializeAs_GameFightStartMessage(Writer *output)
{
  output->writeShort((short)this->idols.size());
  for(uint _i1 = 0; _i1 < this->idols.size(); _i1++)
  {
    qSharedPointerCast<Idol>(this->idols[_i1])->serializeAs_Idol(output);
  }
}

void GameFightStartMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightStartMessage(input);
}

void GameFightStartMessage::deserializeAs_GameFightStartMessage(Reader *input)
{
  QSharedPointer<Idol> _item1 ;
  uint _idolsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _idolsLen; _i1++)
  {
    _item1 = QSharedPointer<Idol>(new Idol() );
    _item1->deserialize(input);
    this->idols.append(_item1);
  }
}

void GameFightStartMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightStartMessage(tree);
}

void GameFightStartMessage::deserializeAsyncAs_GameFightStartMessage(FuncTree tree)
{
  this->_idolstree = tree.addChild(std::bind(&GameFightStartMessage::_idolstreeFunc, this, std::placeholders::_1));
}

void GameFightStartMessage::_idolstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_idolstree.addChild(std::bind(&GameFightStartMessage::_idolsFunc, this, std::placeholders::_1));
  }
}

void GameFightStartMessage::_idolsFunc(Reader *input)
{
  QSharedPointer<Idol> _item = QSharedPointer<Idol>(new Idol() );
  _item->deserialize(input);
  this->idols.append(_item);
}

GameFightStartMessage::GameFightStartMessage()
{
  m_type = MessageEnum::GAMEFIGHTSTARTMESSAGE;
}

