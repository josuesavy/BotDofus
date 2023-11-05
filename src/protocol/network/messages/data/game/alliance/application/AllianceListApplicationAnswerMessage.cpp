#include "AllianceListApplicationAnswerMessage.h"

void AllianceListApplicationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceListApplicationAnswerMessage(output);
}

void AllianceListApplicationAnswerMessage::serializeAs_AllianceListApplicationAnswerMessage(Writer *output)
{
  PaginationAnswerAbstractMessage::serializeAs_PaginationAnswerAbstractMessage(output);
  output->writeShort((short)this->applies.size());
  for(uint _i1 = 0; _i1 < this->applies.size(); _i1++)
  {
    (this->applies[_i1]).serializeAs_SocialApplicationInformation(output);
  }
}

void AllianceListApplicationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceListApplicationAnswerMessage(input);
}

void AllianceListApplicationAnswerMessage::deserializeAs_AllianceListApplicationAnswerMessage(Reader *input)
{
  SocialApplicationInformation _item1 ;
  PaginationAnswerAbstractMessage::deserialize(input);
  uint _appliesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _appliesLen; _i1++)
  {
    _item1 = SocialApplicationInformation();
    _item1.deserialize(input);
    this->applies.append(_item1);
  }
}

void AllianceListApplicationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceListApplicationAnswerMessage(tree);
}

void AllianceListApplicationAnswerMessage::deserializeAsyncAs_AllianceListApplicationAnswerMessage(FuncTree tree)
{
  PaginationAnswerAbstractMessage::deserializeAsync(tree);
  this->_appliestree = tree.addChild(std::bind(&AllianceListApplicationAnswerMessage::_appliestreeFunc, this, std::placeholders::_1));
}

void AllianceListApplicationAnswerMessage::_appliestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_appliestree.addChild(std::bind(&AllianceListApplicationAnswerMessage::_appliesFunc, this, std::placeholders::_1));
  }
}

void AllianceListApplicationAnswerMessage::_appliesFunc(Reader *input)
{
  SocialApplicationInformation _item = SocialApplicationInformation();
  _item.deserialize(input);
  this->applies.append(_item);
}

AllianceListApplicationAnswerMessage::AllianceListApplicationAnswerMessage()
{
  m_type = MessageEnum::ALLIANCELISTAPPLICATIONANSWERMESSAGE;
}

