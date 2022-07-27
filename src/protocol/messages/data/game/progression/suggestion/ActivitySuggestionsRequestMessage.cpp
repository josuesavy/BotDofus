#include "ActivitySuggestionsRequestMessage.h"

void ActivitySuggestionsRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ActivitySuggestionsRequestMessage(output);
}

void ActivitySuggestionsRequestMessage::serializeAs_ActivitySuggestionsRequestMessage(Writer *output)
{
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->minLevel << ") on element minLevel.";
  }
  output->writeVarShort((int)this->minLevel);
  if(this->maxLevel < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->maxLevel << ") on element maxLevel.";
  }
  output->writeVarShort((int)this->maxLevel);
  if(this->areaId < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->areaId << ") on element areaId.";
  }
  output->writeVarShort((int)this->areaId);
  if(this->activityCategoryId < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->activityCategoryId << ") on element activityCategoryId.";
  }
  output->writeVarShort((int)this->activityCategoryId);
  if(this->nbCards < 0 || this->nbCards > 65535)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->nbCards << ") on element nbCards.";
  }
  output->writeShort((short)this->nbCards);
}

void ActivitySuggestionsRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ActivitySuggestionsRequestMessage(input);
}

void ActivitySuggestionsRequestMessage::deserializeAs_ActivitySuggestionsRequestMessage(Reader *input)
{
  this->_minLevelFunc(input);
  this->_maxLevelFunc(input);
  this->_areaIdFunc(input);
  this->_activityCategoryIdFunc(input);
  this->_nbCardsFunc(input);
}

void ActivitySuggestionsRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActivitySuggestionsRequestMessage(tree);
}

void ActivitySuggestionsRequestMessage::deserializeAsyncAs_ActivitySuggestionsRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ActivitySuggestionsRequestMessage::_minLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActivitySuggestionsRequestMessage::_maxLevelFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActivitySuggestionsRequestMessage::_areaIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActivitySuggestionsRequestMessage::_activityCategoryIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActivitySuggestionsRequestMessage::_nbCardsFunc, this, std::placeholders::_1));
}

void ActivitySuggestionsRequestMessage::_minLevelFunc(Reader *input)
{
  this->minLevel = input->readVarUhShort();
  if(this->minLevel < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->minLevel << ") on element of ActivitySuggestionsRequestMessage.minLevel.";
  }
}

void ActivitySuggestionsRequestMessage::_maxLevelFunc(Reader *input)
{
  this->maxLevel = input->readVarUhShort();
  if(this->maxLevel < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->maxLevel << ") on element of ActivitySuggestionsRequestMessage.maxLevel.";
  }
}

void ActivitySuggestionsRequestMessage::_areaIdFunc(Reader *input)
{
  this->areaId = input->readVarUhShort();
  if(this->areaId < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->areaId << ") on element of ActivitySuggestionsRequestMessage.areaId.";
  }
}

void ActivitySuggestionsRequestMessage::_activityCategoryIdFunc(Reader *input)
{
  this->activityCategoryId = input->readVarUhShort();
  if(this->activityCategoryId < 0)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->activityCategoryId << ") on element of ActivitySuggestionsRequestMessage.activityCategoryId.";
  }
}

void ActivitySuggestionsRequestMessage::_nbCardsFunc(Reader *input)
{
  this->nbCards = input->readUShort();
  if(this->nbCards < 0 || this->nbCards > 65535)
  {
    qDebug()<<"ERREUR - ActivitySuggestionsRequestMessage -"<<"Forbidden value (" << this->nbCards << ") on element of ActivitySuggestionsRequestMessage.nbCards.";
  }
}

ActivitySuggestionsRequestMessage::ActivitySuggestionsRequestMessage()
{
  m_type = MessageEnum::ACTIVITYSUGGESTIONSREQUESTMESSAGE;
}

