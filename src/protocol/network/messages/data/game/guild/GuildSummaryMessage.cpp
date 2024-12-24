#include "GuildSummaryMessage.h"

void GuildSummaryMessage::serialize(Writer *output)
{
  this->serializeAs_GuildSummaryMessage(output);
}

void GuildSummaryMessage::serializeAs_GuildSummaryMessage(Writer *output)
{
  PaginationAnswerAbstractMessage::serializeAs_PaginationAnswerAbstractMessage(output);
  output->writeShort((short)this->guilds.size());
  for(uint _i1 = 0; _i1 < this->guilds.size(); _i1++)
  {
    qSharedPointerCast<GuildFactSheetInformations>(this->guilds[_i1])->serializeAs_GuildFactSheetInformations(output);
  }
}

void GuildSummaryMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildSummaryMessage(input);
}

void GuildSummaryMessage::deserializeAs_GuildSummaryMessage(Reader *input)
{
  QSharedPointer<GuildFactSheetInformations> _item1 ;
  PaginationAnswerAbstractMessage::deserialize(input);
  uint _guildsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _guildsLen; _i1++)
  {
    _item1 = QSharedPointer<GuildFactSheetInformations>(new GuildFactSheetInformations() );
    _item1->deserialize(input);
    this->guilds.append(_item1);
  }
}

void GuildSummaryMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildSummaryMessage(tree);
}

void GuildSummaryMessage::deserializeAsyncAs_GuildSummaryMessage(FuncTree tree)
{
  PaginationAnswerAbstractMessage::deserializeAsync(tree);
  this->_guildstree = tree.addChild(std::bind(&GuildSummaryMessage::_guildstreeFunc, this, std::placeholders::_1));
}

void GuildSummaryMessage::_guildstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_guildstree.addChild(std::bind(&GuildSummaryMessage::_guildsFunc, this, std::placeholders::_1));
  }
}

void GuildSummaryMessage::_guildsFunc(Reader *input)
{
  QSharedPointer<GuildFactSheetInformations> _item = QSharedPointer<GuildFactSheetInformations>(new GuildFactSheetInformations() );
  _item->deserialize(input);
  this->guilds.append(_item);
}

GuildSummaryMessage::GuildSummaryMessage()
{
  m_type = MessageEnum::GUILDSUMMARYMESSAGE;
}

