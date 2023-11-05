#include "GuildListApplicationAnswerMessage.h"

void GuildListApplicationAnswerMessage::serialize(Writer *output)
{
  this->serializeAs_GuildListApplicationAnswerMessage(output);
}

void GuildListApplicationAnswerMessage::serializeAs_GuildListApplicationAnswerMessage(Writer *output)
{
  PaginationAnswerAbstractMessage::serializeAs_PaginationAnswerAbstractMessage(output);
  output->writeShort((short)this->applies.size());
  for(uint _i1 = 0; _i1 < this->applies.size(); _i1++)
  {
    (this->applies[_i1]).serializeAs_SocialApplicationInformation(output);
  }
}

void GuildListApplicationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildListApplicationAnswerMessage(input);
}

void GuildListApplicationAnswerMessage::deserializeAs_GuildListApplicationAnswerMessage(Reader *input)
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

void GuildListApplicationAnswerMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildListApplicationAnswerMessage(tree);
}

void GuildListApplicationAnswerMessage::deserializeAsyncAs_GuildListApplicationAnswerMessage(FuncTree tree)
{
  PaginationAnswerAbstractMessage::deserializeAsync(tree);
  this->_appliestree = tree.addChild(std::bind(&GuildListApplicationAnswerMessage::_appliestreeFunc, this, std::placeholders::_1));
}

void GuildListApplicationAnswerMessage::_appliestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_appliestree.addChild(std::bind(&GuildListApplicationAnswerMessage::_appliesFunc, this, std::placeholders::_1));
  }
}

void GuildListApplicationAnswerMessage::_appliesFunc(Reader *input)
{
  SocialApplicationInformation _item = SocialApplicationInformation();
  _item.deserialize(input);
  this->applies.append(_item);
}

GuildListApplicationAnswerMessage::GuildListApplicationAnswerMessage()
{
  m_type = MessageEnum::GUILDLISTAPPLICATIONANSWERMESSAGE;
}

