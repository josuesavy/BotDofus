#include "AllianceSummaryMessage.h"

void AllianceSummaryMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceSummaryMessage(output);
}

void AllianceSummaryMessage::serializeAs_AllianceSummaryMessage(Writer *output)
{
  PaginationAnswerAbstractMessage::serializeAs_PaginationAnswerAbstractMessage(output);
  output->writeShort((short)this->alliances.size());
  for(uint _i1 = 0; _i1 < this->alliances.size(); _i1++)
  {
    qSharedPointerCast<AllianceFactSheetInformations>(this->alliances[_i1])->serializeAs_AllianceFactSheetInformations(output);
  }
}

void AllianceSummaryMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceSummaryMessage(input);
}

void AllianceSummaryMessage::deserializeAs_AllianceSummaryMessage(Reader *input)
{
  QSharedPointer<AllianceFactSheetInformations> _item1 ;
  PaginationAnswerAbstractMessage::deserialize(input);
  uint _alliancesLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _alliancesLen; _i1++)
  {
    _item1 = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
    _item1->deserialize(input);
    this->alliances.append(_item1);
  }
}

void AllianceSummaryMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceSummaryMessage(tree);
}

void AllianceSummaryMessage::deserializeAsyncAs_AllianceSummaryMessage(FuncTree tree)
{
  PaginationAnswerAbstractMessage::deserializeAsync(tree);
  this->_alliancestree = tree.addChild(std::bind(&AllianceSummaryMessage::_alliancestreeFunc, this, std::placeholders::_1));
}

void AllianceSummaryMessage::_alliancestreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_alliancestree.addChild(std::bind(&AllianceSummaryMessage::_alliancesFunc, this, std::placeholders::_1));
  }
}

void AllianceSummaryMessage::_alliancesFunc(Reader *input)
{
  QSharedPointer<AllianceFactSheetInformations> _item = QSharedPointer<AllianceFactSheetInformations>(new AllianceFactSheetInformations() );
  _item->deserialize(input);
  this->alliances.append(_item);
}

AllianceSummaryMessage::AllianceSummaryMessage()
{
  m_type = MessageEnum::ALLIANCESUMMARYMESSAGE;
}

