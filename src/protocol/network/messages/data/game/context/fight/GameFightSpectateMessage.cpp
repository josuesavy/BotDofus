#include "GameFightSpectateMessage.h"

void GameFightSpectateMessage::serialize(Writer *output)
{
  this->serializeAs_GameFightSpectateMessage(output);
}

void GameFightSpectateMessage::serializeAs_GameFightSpectateMessage(Writer *output)
{
  output->writeShort((short)this->effects.size());
  for(uint _i1 = 0; _i1 < this->effects.size(); _i1++)
  {
    qSharedPointerCast<FightDispellableEffectExtendedInformations>(this->effects[_i1])->serializeAs_FightDispellableEffectExtendedInformations(output);
  }
  output->writeShort((short)this->marks.size());
  for(uint _i2 = 0; _i2 < this->marks.size(); _i2++)
  {
    (this->marks[_i2]).serializeAs_GameActionMark(output);
  }
  if(this->gameTurn < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->gameTurn << ") on element gameTurn.";
  }
  output->writeVarShort((int)this->gameTurn);
  if(this->fightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->fightStart << ") on element fightStart.";
  }
  output->writeInt((int)this->fightStart);
  output->writeShort((short)this->idols.size());
  for(uint _i5 = 0; _i5 < this->idols.size(); _i5++)
  {
    qSharedPointerCast<Idol>(this->idols[_i5])->serializeAs_Idol(output);
  }
  output->writeShort((short)this->fxTriggerCounts.size());
  for(uint _i6 = 0; _i6 < this->fxTriggerCounts.size(); _i6++)
  {
    (this->fxTriggerCounts[_i6]).serializeAs_GameFightEffectTriggerCount(output);
  }
}

void GameFightSpectateMessage::deserialize(Reader *input)
{
  this->deserializeAs_GameFightSpectateMessage(input);
}

void GameFightSpectateMessage::deserializeAs_GameFightSpectateMessage(Reader *input)
{
  QSharedPointer<FightDispellableEffectExtendedInformations> _item1 ;
  GameActionMark _item2 ;
  QSharedPointer<Idol> _item5 ;
  GameFightEffectTriggerCount _item6 ;
  uint _effectsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _effectsLen; _i1++)
  {
    _item1 = QSharedPointer<FightDispellableEffectExtendedInformations>(new FightDispellableEffectExtendedInformations() );
    _item1->deserialize(input);
    this->effects.append(_item1);
  }
  uint _marksLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _marksLen; _i2++)
  {
    _item2 = GameActionMark();
    _item2.deserialize(input);
    this->marks.append(_item2);
  }
  this->_gameTurnFunc(input);
  this->_fightStartFunc(input);
  uint _idolsLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _idolsLen; _i5++)
  {
    _item5 = QSharedPointer<Idol>(new Idol() );
    _item5->deserialize(input);
    this->idols.append(_item5);
  }
  uint _fxTriggerCountsLen = uint(input->readUShort());
  for(uint _i6 = 0; _i6 < _fxTriggerCountsLen; _i6++)
  {
    _item6 = GameFightEffectTriggerCount();
    _item6.deserialize(input);
    this->fxTriggerCounts.append(_item6);
  }
}

void GameFightSpectateMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GameFightSpectateMessage(tree);
}

void GameFightSpectateMessage::deserializeAsyncAs_GameFightSpectateMessage(FuncTree tree)
{
  this->_effectstree = tree.addChild(std::bind(&GameFightSpectateMessage::_effectstreeFunc, this, std::placeholders::_1));
  this->_markstree = tree.addChild(std::bind(&GameFightSpectateMessage::_markstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightSpectateMessage::_gameTurnFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GameFightSpectateMessage::_fightStartFunc, this, std::placeholders::_1));
  this->_idolstree = tree.addChild(std::bind(&GameFightSpectateMessage::_idolstreeFunc, this, std::placeholders::_1));
  this->_fxTriggerCountstree = tree.addChild(std::bind(&GameFightSpectateMessage::_fxTriggerCountstreeFunc, this, std::placeholders::_1));
}

void GameFightSpectateMessage::_effectstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_effectstree.addChild(std::bind(&GameFightSpectateMessage::_effectsFunc, this, std::placeholders::_1));
  }
}

void GameFightSpectateMessage::_effectsFunc(Reader *input)
{
  QSharedPointer<FightDispellableEffectExtendedInformations> _item = QSharedPointer<FightDispellableEffectExtendedInformations>(new FightDispellableEffectExtendedInformations() );
  _item->deserialize(input);
  this->effects.append(_item);
}

void GameFightSpectateMessage::_markstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_markstree.addChild(std::bind(&GameFightSpectateMessage::_marksFunc, this, std::placeholders::_1));
  }
}

void GameFightSpectateMessage::_marksFunc(Reader *input)
{
  GameActionMark _item = GameActionMark();
  _item.deserialize(input);
  this->marks.append(_item);
}

void GameFightSpectateMessage::_gameTurnFunc(Reader *input)
{
  this->gameTurn = input->readVarUhShort();
  if(this->gameTurn < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->gameTurn << ") on element of GameFightSpectateMessage.gameTurn.";
  }
}

void GameFightSpectateMessage::_fightStartFunc(Reader *input)
{
  this->fightStart = input->readInt();
  if(this->fightStart < 0)
  {
    qDebug()<<"ERREUR - GameFightSpectateMessage -"<<"Forbidden value (" << this->fightStart << ") on element of GameFightSpectateMessage.fightStart.";
  }
}

void GameFightSpectateMessage::_idolstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_idolstree.addChild(std::bind(&GameFightSpectateMessage::_idolsFunc, this, std::placeholders::_1));
  }
}

void GameFightSpectateMessage::_idolsFunc(Reader *input)
{
  QSharedPointer<Idol> _item = QSharedPointer<Idol>(new Idol() );
  _item->deserialize(input);
  this->idols.append(_item);
}

void GameFightSpectateMessage::_fxTriggerCountstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_fxTriggerCountstree.addChild(std::bind(&GameFightSpectateMessage::_fxTriggerCountsFunc, this, std::placeholders::_1));
  }
}

void GameFightSpectateMessage::_fxTriggerCountsFunc(Reader *input)
{
  GameFightEffectTriggerCount _item = GameFightEffectTriggerCount();
  _item.deserialize(input);
  this->fxTriggerCounts.append(_item);
}

GameFightSpectateMessage::GameFightSpectateMessage()
{
  m_type = MessageEnum::GAMEFIGHTSPECTATEMESSAGE;
}

