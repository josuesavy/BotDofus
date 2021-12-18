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
    qSharedPointerCast<GuildApplicationInformation>(this->applies[_i1])->serializeAs_GuildApplicationInformation(output);
  }
}

void GuildListApplicationAnswerMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildListApplicationAnswerMessage(input);
}

void GuildListApplicationAnswerMessage::deserializeAs_GuildListApplicationAnswerMessage(Reader *input)
{
  QSharedPointer<GuildApplicationInformation> _item1 ;
  PaginationAnswerAbstractMessage::deserialize(input);
  uint _appliesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _appliesLen; _i1++)
  {
    _item1 = QSharedPointer<GuildApplicationInformation>(new GuildApplicationInformation() );
    _item1->deserialize(input);
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
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_appliestree.addChild(std::bind(&GuildListApplicationAnswerMessage::_appliesFunc, this, std::placeholders::_1));
  }
}

void GuildListApplicationAnswerMessage::_appliesFunc(Reader *input)
{
  QSharedPointer<GuildApplicationInformation> _item = QSharedPointer<GuildApplicationInformation>(new GuildApplicationInformation() );
  _item->deserialize(input);
  this->applies.append(_item);
}

GuildListApplicationAnswerMessage::GuildListApplicationAnswerMessage()
{
  m_type = MessageEnum::GUILDLISTAPPLICATIONANSWERMESSAGE;
}

