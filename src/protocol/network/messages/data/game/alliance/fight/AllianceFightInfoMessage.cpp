#include "AllianceFightInfoMessage.h"

void AllianceFightInfoMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightInfoMessage(output);
}

void AllianceFightInfoMessage::serializeAs_AllianceFightInfoMessage(Writer *output)
{
  output->writeShort((short)this->allianceFights.size());
  for(uint _i1 = 0; _i1 < this->allianceFights.size(); _i1++)
  {
    qSharedPointerCast<SocialFight>(this->allianceFights[_i1])->serializeAs_SocialFight(output);
  }
}

void AllianceFightInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightInfoMessage(input);
}

void AllianceFightInfoMessage::deserializeAs_AllianceFightInfoMessage(Reader *input)
{
  QSharedPointer<SocialFight> _item1 ;
  uint _allianceFightsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _allianceFightsLen; _i1++)
  {
    _item1 = QSharedPointer<SocialFight>(new SocialFight() );
    _item1->deserialize(input);
    this->allianceFights.append(_item1);
  }
}

void AllianceFightInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightInfoMessage(tree);
}

void AllianceFightInfoMessage::deserializeAsyncAs_AllianceFightInfoMessage(FuncTree tree)
{
  this->_allianceFightstree = tree.addChild(std::bind(&AllianceFightInfoMessage::_allianceFightstreeFunc, this, std::placeholders::_1));
}

void AllianceFightInfoMessage::_allianceFightstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_allianceFightstree.addChild(std::bind(&AllianceFightInfoMessage::_allianceFightsFunc, this, std::placeholders::_1));
  }
}

void AllianceFightInfoMessage::_allianceFightsFunc(Reader *input)
{
  QSharedPointer<SocialFight> _item = QSharedPointer<SocialFight>(new SocialFight() );
  _item->deserialize(input);
  this->allianceFights.append(_item);
}

AllianceFightInfoMessage::AllianceFightInfoMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTINFOMESSAGE;
}

