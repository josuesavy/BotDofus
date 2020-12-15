#include "QuestListMessage.h"

void QuestListMessage::serialize(Writer *output)
{
  this->serializeAs_QuestListMessage(output);
}

void QuestListMessage::serializeAs_QuestListMessage(Writer *output)
{
  output->writeShort((short)this->finishedQuestsIds.size());
  for(uint _i1 = 0; _i1 < this->finishedQuestsIds.size(); _i1++)
  {
    if(this->finishedQuestsIds[_i1] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->finishedQuestsIds[_i1] << ") on element 1 (starting at 1) of finishedQuestsIds.";
    }
    output->writeVarShort((int)this->finishedQuestsIds[_i1]);
  }
  output->writeShort((short)this->finishedQuestsCounts.size());
  for(uint _i2 = 0; _i2 < this->finishedQuestsCounts.size(); _i2++)
  {
    if(this->finishedQuestsCounts[_i2] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->finishedQuestsCounts[_i2] << ") on element 2 (starting at 1) of finishedQuestsCounts.";
    }
    output->writeVarShort((int)this->finishedQuestsCounts[_i2]);
  }
  output->writeShort((short)this->activeQuests.size());
  for(uint _i3 = 0; _i3 < this->activeQuests.size(); _i3++)
  {
    output->writeShort((short)qSharedPointerCast<QuestActiveInformations>(this->activeQuests[_i3])->getTypes().last());
    qSharedPointerCast<QuestActiveInformations>(this->activeQuests[_i3])->serialize(output);
  }
  output->writeShort((short)this->reinitDoneQuestsIds.size());
  for(uint _i4 = 0; _i4 < this->reinitDoneQuestsIds.size(); _i4++)
  {
    if(this->reinitDoneQuestsIds[_i4] < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << this->reinitDoneQuestsIds[_i4] << ") on element 4 (starting at 1) of reinitDoneQuestsIds.";
    }
    output->writeVarShort((int)this->reinitDoneQuestsIds[_i4]);
  }
}

void QuestListMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestListMessage(input);
}

void QuestListMessage::deserializeAs_QuestListMessage(Reader *input)
{
  uint _val1 = 0;
  uint _val2 = 0;
  uint _id3 = 0;
  QSharedPointer<QuestActiveInformations> _item3 ;
  uint _val4 = 0;
  uint _finishedQuestsIdsLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _finishedQuestsIdsLen; _i1++)
  {
    _val1 = input->readVarUhShort();
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val1 << ") on elements of finishedQuestsIds.";
    }
    this->finishedQuestsIds.append(_val1);
  }
  uint _finishedQuestsCountsLen = input->readUShort();
  for(uint _i2 = 0; _i2 < _finishedQuestsCountsLen; _i2++)
  {
    _val2 = input->readVarUhShort();
    if(_val2 < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val2 << ") on elements of finishedQuestsCounts.";
    }
    this->finishedQuestsCounts.append(_val2);
  }
  uint _activeQuestsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _activeQuestsLen; _i3++)
  {
    _id3 = input->readUShort();
    _item3 = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_id3));
    _item3->deserialize(input);
    this->activeQuests.append(_item3);
  }
  uint _reinitDoneQuestsIdsLen = input->readUShort();
  for(uint _i4 = 0; _i4 < _reinitDoneQuestsIdsLen; _i4++)
  {
    _val4 = input->readVarUhShort();
    if(_val4 < 0)
    {
      qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val4 << ") on elements of reinitDoneQuestsIds.";
    }
    this->reinitDoneQuestsIds.append(_val4);
  }
}

void QuestListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestListMessage(tree);
}

void QuestListMessage::deserializeAsyncAs_QuestListMessage(FuncTree tree)
{
  this->_finishedQuestsIdstree = tree.addChild(std::bind(&QuestListMessage::_finishedQuestsIdstreeFunc, this, std::placeholders::_1));
  this->_finishedQuestsCountstree = tree.addChild(std::bind(&QuestListMessage::_finishedQuestsCountstreeFunc, this, std::placeholders::_1));
  this->_activeQueststree = tree.addChild(std::bind(&QuestListMessage::_activeQueststreeFunc, this, std::placeholders::_1));
  this->_reinitDoneQuestsIdstree = tree.addChild(std::bind(&QuestListMessage::_reinitDoneQuestsIdstreeFunc, this, std::placeholders::_1));
}

void QuestListMessage::_finishedQuestsIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_finishedQuestsIdstree.addChild(std::bind(&QuestListMessage::_finishedQuestsIdsFunc, this, std::placeholders::_1));
  }
}

void QuestListMessage::_finishedQuestsIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val << ") on elements of finishedQuestsIds.";
  }
  this->finishedQuestsIds.append(_val);
}

void QuestListMessage::_finishedQuestsCountstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_finishedQuestsCountstree.addChild(std::bind(&QuestListMessage::_finishedQuestsCountsFunc, this, std::placeholders::_1));
  }
}

void QuestListMessage::_finishedQuestsCountsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val << ") on elements of finishedQuestsCounts.";
  }
  this->finishedQuestsCounts.append(_val);
}

void QuestListMessage::_activeQueststreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_activeQueststree.addChild(std::bind(&QuestListMessage::_activeQuestsFunc, this, std::placeholders::_1));
  }
}

void QuestListMessage::_activeQuestsFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<QuestActiveInformations> _item = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->activeQuests.append(_item);
}

void QuestListMessage::_reinitDoneQuestsIdstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_reinitDoneQuestsIdstree.addChild(std::bind(&QuestListMessage::_reinitDoneQuestsIdsFunc, this, std::placeholders::_1));
  }
}

void QuestListMessage::_reinitDoneQuestsIdsFunc(Reader *input)
{
  uint _val = input->readVarUhShort();
  if(_val < 0)
  {
    qDebug()<<"ERREUR - QuestListMessage -"<<"Forbidden value (" << _val << ") on elements of reinitDoneQuestsIds.";
  }
  this->reinitDoneQuestsIds.append(_val);
}

QuestListMessage::QuestListMessage()
{
  m_type = MessageEnum::QUESTLISTMESSAGE;
}

