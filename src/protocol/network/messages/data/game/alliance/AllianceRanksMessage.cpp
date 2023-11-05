#include "AllianceRanksMessage.h"

void AllianceRanksMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceRanksMessage(output);
}

void AllianceRanksMessage::serializeAs_AllianceRanksMessage(Writer *output)
{
  output->writeShort((short)this->ranks.size());
  for(uint _i1 = 0; _i1 < this->ranks.size(); _i1++)
  {
    (this->ranks[_i1]).serializeAs_RankInformation(output);
  }
}

void AllianceRanksMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceRanksMessage(input);
}

void AllianceRanksMessage::deserializeAs_AllianceRanksMessage(Reader *input)
{
  RankInformation _item1 ;
  uint _ranksLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _ranksLen; _i1++)
  {
    _item1 = RankInformation();
    _item1.deserialize(input);
    this->ranks.append(_item1);
  }
}

void AllianceRanksMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceRanksMessage(tree);
}

void AllianceRanksMessage::deserializeAsyncAs_AllianceRanksMessage(FuncTree tree)
{
  this->_rankstree = tree.addChild(std::bind(&AllianceRanksMessage::_rankstreeFunc, this, std::placeholders::_1));
}

void AllianceRanksMessage::_rankstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_rankstree.addChild(std::bind(&AllianceRanksMessage::_ranksFunc, this, std::placeholders::_1));
  }
}

void AllianceRanksMessage::_ranksFunc(Reader *input)
{
  RankInformation _item = RankInformation();
  _item.deserialize(input);
  this->ranks.append(_item);
}

AllianceRanksMessage::AllianceRanksMessage()
{
  m_type = MessageEnum::ALLIANCERANKSMESSAGE;
}

