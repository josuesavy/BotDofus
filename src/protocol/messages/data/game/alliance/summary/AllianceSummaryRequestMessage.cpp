#include "AllianceSummaryRequestMessage.h"

void AllianceSummaryRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceSummaryRequestMessage(output);
}

void AllianceSummaryRequestMessage::serializeAs_AllianceSummaryRequestMessage(Writer *output)
{
  PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(output);
  output->writeUTF(this->nameFilter);
  output->writeUTF(this->tagFilter);
  output->writeUTF(this->playerNameFilter);
  output->writeByte(this->sortType);
  output->writeBool(this->sortDescending);
}

void AllianceSummaryRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceSummaryRequestMessage(input);
}

void AllianceSummaryRequestMessage::deserializeAs_AllianceSummaryRequestMessage(Reader *input)
{
  PaginationRequestAbstractMessage::deserialize(input);
  this->_nameFilterFunc(input);
  this->_tagFilterFunc(input);
  this->_playerNameFilterFunc(input);
  this->_sortTypeFunc(input);
  this->_sortDescendingFunc(input);
}

void AllianceSummaryRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceSummaryRequestMessage(tree);
}

void AllianceSummaryRequestMessage::deserializeAsyncAs_AllianceSummaryRequestMessage(FuncTree tree)
{
  PaginationRequestAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_nameFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_tagFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_playerNameFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_sortTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_sortDescendingFunc, this, std::placeholders::_1));
}

void AllianceSummaryRequestMessage::_nameFilterFunc(Reader *input)
{
  this->nameFilter = input->readUTF();
}

void AllianceSummaryRequestMessage::_tagFilterFunc(Reader *input)
{
  this->tagFilter = input->readUTF();
}

void AllianceSummaryRequestMessage::_playerNameFilterFunc(Reader *input)
{
  this->playerNameFilter = input->readUTF();
}

void AllianceSummaryRequestMessage::_sortTypeFunc(Reader *input)
{
  this->sortType = input->readByte();
  if(this->sortType < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->sortType << ") on element of AllianceSummaryRequestMessage.sortType.";
  }
}

void AllianceSummaryRequestMessage::_sortDescendingFunc(Reader *input)
{
  this->sortDescending = input->readBool();
}

AllianceSummaryRequestMessage::AllianceSummaryRequestMessage()
{
  m_type = MessageEnum::ALLIANCESUMMARYREQUESTMESSAGE;
}

