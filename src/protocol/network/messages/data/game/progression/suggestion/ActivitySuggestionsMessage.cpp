#include "ActivitySuggestionsMessage.h"

void ActivitySuggestionsMessage::serialize(Writer *output)
{
  this->serializeAs_ActivitySuggestionsMessage(output);
}

void ActivitySuggestionsMessage::serializeAs_ActivitySuggestionsMessage(Writer *output)
{
  output->writeShort((short)this->lockedActivitiesIds.size());
  for(uint _i1 = 0; _i1 < this->lockedActivitiesIds.size(); _i1++)
  {
    if(this->lockedActivitiesIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << this->lockedActivitiesIds[_i1] << ") on element 1 (starting at 1) of lockedActivitiesIds.";
    }
    output->writeVarShort((int)this->lockedActivitiesIds[_i1]);
  }
  output->writeShort((short)this->unlockedActivitiesIds.size());
  for(uint _i2 = 0; _i2 < this->unlockedActivitiesIds.size(); _i2++)
  {
    if(this->unlockedActivitiesIds[_i2] < 0)
    {
      qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << this->unlockedActivitiesIds[_i2] << ") on element 2 (starting at 1) of unlockedActivitiesIds.";
    }
    output->writeVarShort((int)this->unlockedActivitiesIds[_i2]);
  }
}

void ActivitySuggestionsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ActivitySuggestionsMessage(input);
}

void ActivitySuggestionsMessage::deserializeAs_ActivitySuggestionsMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _lockedActivitiesIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _lockedActivitiesIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << _val1 << ") on elements of lockedActivitiesIds.";
    }
    this->lockedActivitiesIds.append(_val1);
  }
  uint _unlockedActivitiesIdsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _unlockedActivitiesIdsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << _val2 << ") on elements of unlockedActivitiesIds.";
    }
    this->unlockedActivitiesIds.append(_val2);
  }
}

void ActivitySuggestionsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActivitySuggestionsMessage(tree);
}

void ActivitySuggestionsMessage::deserializeAsyncAs_ActivitySuggestionsMessage(FuncTree tree)
{
  this->_lockedActivitiesIdstree = tree.addChild(std::bind(&ActivitySuggestionsMessage::_lockedActivitiesIdstreeFunc, this, std::placeholders::_1));
  this->_unlockedActivitiesIdstree = tree.addChild(std::bind(&ActivitySuggestionsMessage::_unlockedActivitiesIdstreeFunc, this, std::placeholders::_1));
}

void ActivitySuggestionsMessage::_lockedActivitiesIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_lockedActivitiesIdstree.addChild(std::bind(&ActivitySuggestionsMessage::_lockedActivitiesIdsFunc, this, std::placeholders::_1));
  }
}

void ActivitySuggestionsMessage::_lockedActivitiesIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << _val << ") on elements of lockedActivitiesIds.";
  }
  this->lockedActivitiesIds.append(_val);
}

void ActivitySuggestionsMessage::_unlockedActivitiesIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_unlockedActivitiesIdstree.addChild(std::bind(&ActivitySuggestionsMessage::_unlockedActivitiesIdsFunc, this, std::placeholders::_1));
  }
}

void ActivitySuggestionsMessage::_unlockedActivitiesIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsMessage -"<<"Forbidden value (" << _val << ") on elements of unlockedActivitiesIds.";
  }
  this->unlockedActivitiesIds.append(_val);
}

ActivitySuggestionsMessage::ActivitySuggestionsMessage()
{
  m_type = MessageEnum::ACTIVITYSUGGESTIONSMESSAGE;
}

