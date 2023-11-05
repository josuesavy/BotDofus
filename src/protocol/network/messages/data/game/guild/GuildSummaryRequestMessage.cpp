#include "GuildSummaryRequestMessage.h"

void GuildSummaryRequestMessage::serialize(Writer *output)
{
  this->serializeAs_GuildSummaryRequestMessage(output);
}

void GuildSummaryRequestMessage::serializeAs_GuildSummaryRequestMessage(Writer *output)
{
  PaginationRequestAbstractMessage::serializeAs_PaginationRequestAbstractMessage(output);
  uint _box0 = 0;
  _box0 = BooleanByteWrapper::setFlag(_box0, 0, this->hideFullFilter);
  _box0 = BooleanByteWrapper::setFlag(_box0, 1, this->sortDescending);
  output->writeByte(_box0);
  output->writeUTF(this->nameFilter);
  output->writeShort((short)this->criterionFilter.size());
  for(uint _i3 = 0; _i3 < this->criterionFilter.size(); _i3++)
  {
    if(this->criterionFilter[_i3] < 0)
    {
      qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->criterionFilter[_i3] << ") on element 3 (starting at 1) of criterionFilter.";
    }
    output->writeVarInt((int)this->criterionFilter[_i3]);
  }
  output->writeShort((short)this->languagesFilter.size());
  for(uint _i4 = 0; _i4 < this->languagesFilter.size(); _i4++)
  {
    if(this->languagesFilter[_i4] < 0)
    {
      qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->languagesFilter[_i4] << ") on element 4 (starting at 1) of languagesFilter.";
    }
    output->writeVarInt((int)this->languagesFilter[_i4]);
  }
  output->writeShort((short)this->recruitmentTypeFilter.size());
  for(uint _i5 = 0; _i5 < this->recruitmentTypeFilter.size(); _i5++)
  {
    output->writeByte(this->recruitmentTypeFilter[_i5]);
  }
  if(this->minLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minLevelFilter << ") on element minLevelFilter.";
  }
  output->writeShort((short)this->minLevelFilter);
  if(this->maxLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxLevelFilter << ") on element maxLevelFilter.";
  }
  output->writeShort((short)this->maxLevelFilter);
  if(this->minPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minPlayerLevelFilter << ") on element minPlayerLevelFilter.";
  }
  output->writeShort((short)this->minPlayerLevelFilter);
  if(this->maxPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxPlayerLevelFilter << ") on element maxPlayerLevelFilter.";
  }
  output->writeShort((short)this->maxPlayerLevelFilter);
  if(this->minSuccessFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minSuccessFilter << ") on element minSuccessFilter.";
  }
  output->writeVarInt((int)this->minSuccessFilter);
  if(this->maxSuccessFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxSuccessFilter << ") on element maxSuccessFilter.";
  }
  output->writeVarInt((int)this->maxSuccessFilter);
  output->writeByte(this->sortType);
}

void GuildSummaryRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildSummaryRequestMessage(input);
}

void GuildSummaryRequestMessage::deserializeAs_GuildSummaryRequestMessage(Reader *input)
{
  uint _val3 = 0;
  uint _val4 = 0;
  uint _val5 = 0;
  PaginationRequestAbstractMessage::deserialize(input);
  this->deserializeByteBoxes(input);
  this->_nameFilterFunc(input);
  uint _criterionFilterLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _criterionFilterLen; _i3++)
  {
    _val3 = input->readVarUhInt();
    if(_val3 < 0)
    {
      qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val3 << ") on elements of criterionFilter.";
    }
    this->criterionFilter.append(_val3);
  }
  uint _languagesFilterLen = uint(input->readUShort());
  for(uint _i4 = 0; _i4 < _languagesFilterLen; _i4++)
  {
    _val4 = input->readVarUhInt();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val4 << ") on elements of languagesFilter.";
    }
    this->languagesFilter.append(_val4);
  }
  uint _recruitmentTypeFilterLen = uint(input->readUShort());
  for(uint _i5 = 0; _i5 < _recruitmentTypeFilterLen; _i5++)
  {
    _val5 = uint(input->readByte());
    if(_val5 < 0)
    {
      qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val5 << ") on elements of recruitmentTypeFilter.";
    }
    this->recruitmentTypeFilter.append(_val5);
  }
  this->_minLevelFilterFunc(input);
  this->_maxLevelFilterFunc(input);
  this->_minPlayerLevelFilterFunc(input);
  this->_maxPlayerLevelFilterFunc(input);
  this->_minSuccessFilterFunc(input);
  this->_maxSuccessFilterFunc(input);
  this->_sortTypeFunc(input);
}

void GuildSummaryRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildSummaryRequestMessage(tree);
}

void GuildSummaryRequestMessage::deserializeAsyncAs_GuildSummaryRequestMessage(FuncTree tree)
{
  PaginationRequestAbstractMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildSummaryRequestMessage::deserializeByteBoxes, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_nameFilterFunc, this, std::placeholders::_1));
  this->_criterionFiltertree = tree.addChild(std::bind(&GuildSummaryRequestMessage::_criterionFiltertreeFunc, this, std::placeholders::_1));
  this->_languagesFiltertree = tree.addChild(std::bind(&GuildSummaryRequestMessage::_languagesFiltertreeFunc, this, std::placeholders::_1));
  this->_recruitmentTypeFiltertree = tree.addChild(std::bind(&GuildSummaryRequestMessage::_recruitmentTypeFiltertreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_minLevelFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_maxLevelFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_minPlayerLevelFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_maxPlayerLevelFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_minSuccessFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_maxSuccessFilterFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&GuildSummaryRequestMessage::_sortTypeFunc, this, std::placeholders::_1));
}

void GuildSummaryRequestMessage::deserializeByteBoxes(Reader *input)
{
  uint _box0 = uint(input->readByte());
  this->hideFullFilter = BooleanByteWrapper::getFlag(_box0, 0);
  this->sortDescending = BooleanByteWrapper::getFlag(_box0, 1);
}

void GuildSummaryRequestMessage::_nameFilterFunc(Reader *input)
{
  this->nameFilter = input->readUTF();
}

void GuildSummaryRequestMessage::_criterionFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_criterionFiltertree.addChild(std::bind(&GuildSummaryRequestMessage::_criterionFilterFunc, this, std::placeholders::_1));
  }
}

void GuildSummaryRequestMessage::_criterionFilterFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of criterionFilter.";
  }
  this->criterionFilter.append(_val);
}

void GuildSummaryRequestMessage::_languagesFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_languagesFiltertree.addChild(std::bind(&GuildSummaryRequestMessage::_languagesFilterFunc, this, std::placeholders::_1));
  }
}

void GuildSummaryRequestMessage::_languagesFilterFunc(Reader *input)
{
  uint _val = input->readVarUhInt();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of languagesFilter.";
  }
  this->languagesFilter.append(_val);
}

void GuildSummaryRequestMessage::_recruitmentTypeFiltertreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_recruitmentTypeFiltertree.addChild(std::bind(&GuildSummaryRequestMessage::_recruitmentTypeFilterFunc, this, std::placeholders::_1));
  }
}

void GuildSummaryRequestMessage::_recruitmentTypeFilterFunc(Reader *input)
{
  uint _val = uint(input->readByte());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << _val << ") on elements of recruitmentTypeFilter.";
  }
  this->recruitmentTypeFilter.append(_val);
}

void GuildSummaryRequestMessage::_minLevelFilterFunc(Reader *input)
{
  this->minLevelFilter = input->readShort();
  if(this->minLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minLevelFilter << ") on element of GuildSummaryRequestMessage.minLevelFilter.";
  }
}

void GuildSummaryRequestMessage::_maxLevelFilterFunc(Reader *input)
{
  this->maxLevelFilter = input->readShort();
  if(this->maxLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxLevelFilter << ") on element of GuildSummaryRequestMessage.maxLevelFilter.";
  }
}

void GuildSummaryRequestMessage::_minPlayerLevelFilterFunc(Reader *input)
{
  this->minPlayerLevelFilter = input->readShort();
  if(this->minPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minPlayerLevelFilter << ") on element of GuildSummaryRequestMessage.minPlayerLevelFilter.";
  }
}

void GuildSummaryRequestMessage::_maxPlayerLevelFilterFunc(Reader *input)
{
  this->maxPlayerLevelFilter = input->readShort();
  if(this->maxPlayerLevelFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxPlayerLevelFilter << ") on element of GuildSummaryRequestMessage.maxPlayerLevelFilter.";
  }
}

void GuildSummaryRequestMessage::_minSuccessFilterFunc(Reader *input)
{
  this->minSuccessFilter = input->readVarUhInt();
  if(this->minSuccessFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->minSuccessFilter << ") on element of GuildSummaryRequestMessage.minSuccessFilter.";
  }
}

void GuildSummaryRequestMessage::_maxSuccessFilterFunc(Reader *input)
{
  this->maxSuccessFilter = input->readVarUhInt();
  if(this->maxSuccessFilter < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->maxSuccessFilter << ") on element of GuildSummaryRequestMessage.maxSuccessFilter.";
  }
}

void GuildSummaryRequestMessage::_sortTypeFunc(Reader *input)
{
  this->sortType = input->readByte();
  if(this->sortType < 0)
  {
    qDebug()<<"ERREUR - GuildSummaryRequestMessage -"<<"Forbidden value (" << this->sortType << ") on element of GuildSummaryRequestMessage.sortType.";
  }
}

GuildSummaryRequestMessage::GuildSummaryRequestMessage()
{
  m_type = MessageEnum::GUILDSUMMARYREQUESTMESSAGE;
}

