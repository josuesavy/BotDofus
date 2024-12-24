#include "AllianceAllRanksUpdateRequestMessage.h"

void AllianceAllRanksUpdateRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceAllRanksUpdateRequestMessage(output);
}

void AllianceAllRanksUpdateRequestMessage::serializeAs_AllianceAllRanksUpdateRequestMessage(Writer *output)
{
  output->writeShort((short)this->ranks.size());
  for(uint _i1 = 0; _i1 < this->ranks.size(); _i1++)
  {
    (this->ranks[_i1]).serializeAs_RankInformation(output);
  }
}

void AllianceAllRanksUpdateRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceAllRanksUpdateRequestMessage(input);
}

void AllianceAllRanksUpdateRequestMessage::deserializeAs_AllianceAllRanksUpdateRequestMessage(Reader *input)
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

void AllianceAllRanksUpdateRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceAllRanksUpdateRequestMessage(tree);
}

void AllianceAllRanksUpdateRequestMessage::deserializeAsyncAs_AllianceAllRanksUpdateRequestMessage(FuncTree tree)
{
  this->_rankstree = tree.addChild(std::bind(&AllianceAllRanksUpdateRequestMessage::_rankstreeFunc, this, std::placeholders::_1));
}

void AllianceAllRanksUpdateRequestMessage::_rankstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_rankstree.addChild(std::bind(&AllianceAllRanksUpdateRequestMessage::_ranksFunc, this, std::placeholders::_1));
  }
}

void AllianceAllRanksUpdateRequestMessage::_ranksFunc(Reader *input)
{
  RankInformation _item = RankInformation();
  _item.deserialize(input);
  this->ranks.append(_item);
}

AllianceAllRanksUpdateRequestMessage::AllianceAllRanksUpdateRequestMessage()
{
  m_type = MessageEnum::ALLIANCEALLRANKSUPDATEREQUESTMESSAGE;
}

