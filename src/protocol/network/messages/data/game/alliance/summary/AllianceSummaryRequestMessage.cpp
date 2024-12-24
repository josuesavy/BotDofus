#include "AllianceSummaryRequestMessage.h"

void AllianceSummaryRequestMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceSummaryRequestMessage(output);
}

void AllianceSummaryRequestMessage::serializeAs_AllianceSummaryRequestMessage(Writer *output)
{
  PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->hideFullFilter);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->followingAllianceCriteria);
  _box0 = BooleanByteWrapper::setFlag(_box0, 2, this->sortDescending);
  output->writeByte(_box0);
  output->writeInt((int)this->filterType);
  output->writeUTF(this->textFilter);
  output->writeShort((short)this->criterionFilter.size());
  for(uint _i5 = 0; _i5 < this->criterionFilter.size(); _i5++)
  {
    if(this->criterionFilter[_i5] < 0)
    {
      qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->criterionFilter[_i5] << ") on element 5 (starting at 1) of criterionFilter.";
    }
    output->writeVarInt((int)this->criterionFilter[_i5]);
  }
  output->writeByte(this->sortType);
  output->writeShort((short)this->languagesFilter.size());
  for(uint _i8 = 0; _i8 < this->languagesFilter.size(); _i8++)
  {
    if(this->languagesFilter[_i8] < 0)
    {
      qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->languagesFilter[_i8] << ") on element 8 (starting at 1) of languagesFilter.";
    }
    output->writeVarInt((int)this->languagesFilter[_i8]);
  }
  output->writeShort((short)this->recruitmentTypeFilter.size());
  for(uint _i9 = 0; _i9 < this->recruitmentTypeFilter.size(); _i9++)
  {
    output->writeByte(this->recruitmentTypeFilter[_i9]);
  }
  if(this->minPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->minPlayerLevelFilter << ") on element minPlayerLevelFilter.";
  }
  output->writeShort((short)this->minPlayerLevelFilter);
  if(this->maxPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->maxPlayerLevelFilter << ") on element maxPlayerLevelFilter.";
  }
  output->writeShort((short)this->maxPlayerLevelFilter);
}

void AllianceSummaryRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceSummaryRequestMessage(input);
}

void AllianceSummaryRequestMessage::deserializeAs_AllianceSummaryRequestMessage(Reader *input)
{
  uint _val5 = 0;
  uint _val8 = 0;
  uint _val9 = 0;
  PaginationRequestAbstractMessage::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_filterTypeFunc(input);
  this->_textFilterFunc(input);
  uint _criterionFilterLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _criterionFilterLen; _i5++)
  {
    _val5 = input->readVarUhInt();
    if(_val5 < 0)
    {
      qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val5 << ") on elements of criterionFilter.";
    }
    this->criterionFilter.append(_val5);
  }
  this->_sortTypeFunc(input);
  uint _languagesFilterLen = uint(input->readUShort());
  for(uint _i8 = 0; _i8 < _languagesFilterLen; _i8++)
  {
    _val8 = input->readVarUhInt();
    if(_val8 < 0)
    {
      qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val8 << ") on elements of languagesFilter.";
    }
    this->languagesFilter.append(_val8);
  }
  uint _recruitmentTypeFilterLen = uint(input->readUShort());
  for(uint _i9 = 0; _i9 < _recruitmentTypeFilterLen; _i9++)
  {
    _val9 = uint(input->readByte());
    if(_val9 < 0)
    {
      qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val9 << ") on elements of recruitmentTypeFilter.";
    }
    this->recruitmentTypeFilter.append(_val9);
  }
  this->_minPlayerLevelFilterFunc(input);
  this->_maxPlayerLevelFilterFunc(input);
}

void AllianceSummaryRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceSummaryRequestMessage(tree);
}

void AllianceSummaryRequestMessage::deserializeAsyncAs_AllianceSummaryRequestMessage(FuncTree tree)
{
  PaginationRequestAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_filterTypeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_textFilterFunc, this, std::placeholders::_1));
  this->_criterionFiltertree = tree.addChild(std::bind(&AllianceSummaryRequestMessage::_criterionFiltertreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_sortTypeFunc, this, std::placeholders::_1));
  this->_languagesFiltertree = tree.addChild(std::bind(&AllianceSummaryRequestMessage::_languagesFiltertreeFunc, this, std::placeholders::_1));
  this->_recruitmentTypeFiltertree = tree.addChild(std::bind(&AllianceSummaryRequestMessage::_recruitmentTypeFiltertreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_minPlayerLevelFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceSummaryRequestMessage::_maxPlayerLevelFilterFunc, this, std::placeholders::_1));
}

void AllianceSummaryRequestMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->hideFullFilter = BooleanByteWrapper::getFlag(_box0, 0);
  this->followingAllianceCriteria = BooleanByteWrapper::getFlag(_box0, 1);
  this->sortDescending = BooleanByteWrapper::getFlag(_box0, 2);
}

void AllianceSummaryRequestMessage::_filterTypeFunc(Reader *input)
{
  this->filterType = input->readInt();
}

void AllianceSummaryRequestMessage::_textFilterFunc(Reader *input)
{
  this->textFilter = input->readUTF();
}

void AllianceSummaryRequestMessage::_criterionFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_criterionFiltertree.addChild(std::bind(&AllianceSummaryRequestMessage::_criterionFilterFunc, this, std::placeholders::_1));
  }
}

void AllianceSummaryRequestMessage::_criterionFilterFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of criterionFilter.";
  }
  this->criterionFilter.append(_val);
}

void AllianceSummaryRequestMessage::_sortTypeFunc(Reader *input)
{
  this->sortType = input->readByte();
  if(this->sortType < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->sortType << ") on element of AllianceSummaryRequestMessage.sortType.";
  }
}

void AllianceSummaryRequestMessage::_languagesFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_languagesFiltertree.addChild(std::bind(&AllianceSummaryRequestMessage::_languagesFilterFunc, this, std::placeholders::_1));
  }
}

void AllianceSummaryRequestMessage::_languagesFilterFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of languagesFilter.";
  }
  this->languagesFilter.append(_val);
}

void AllianceSummaryRequestMessage::_recruitmentTypeFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_recruitmentTypeFiltertree.addChild(std::bind(&AllianceSummaryRequestMessage::_recruitmentTypeFilterFunc, this, std::placeholders::_1));
  }
}

void AllianceSummaryRequestMessage::_recruitmentTypeFilterFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of recruitmentTypeFilter.";
  }
  this->recruitmentTypeFilter.append(_val);
}

void AllianceSummaryRequestMessage::_minPlayerLevelFilterFunc(Reader *input)
{
  this->minPlayerLevelFilter = input->readShort();
  if(this->minPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->minPlayerLevelFilter << ") on element of AllianceSummaryRequestMessage.minPlayerLevelFilter.";
  }
}

void AllianceSummaryRequestMessage::_maxPlayerLevelFilterFunc(Reader *input)
{
  this->maxPlayerLevelFilter = input->readShort();
  if(this->maxPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - AllianceSummaryRequestMessage -"<<"Forbidden value (" << this->maxPlayerLevelFilter << ") on element of AllianceSummaryRequestMessage.maxPlayerLevelFilter.";
  }
}

AllianceSummaryRequestMessage::AllianceSummaryRequestMessage()
{
  m_type = MessageEnum::ALLIANCESUMMARYREQUESTMESSAGE;
}

