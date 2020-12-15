#include "QuestStepInfoMessage.h"

void QuestStepInfoMessage::serialize(Writer *output)
{
  this->serializeAs_QuestStepInfoMessage(output);
}

void QuestStepInfoMessage::serializeAs_QuestStepInfoMessage(Writer *output)
{
  output->writeShort((short)this->infos->getTypes().last());
  this->infos->serialize(output);
}

void QuestStepInfoMessage::deserialize(Reader *input)
{
  this->deserializeAs_QuestStepInfoMessage(input);
}

void QuestStepInfoMessage::deserializeAs_QuestStepInfoMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->infos = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->infos->deserialize(input);
}

void QuestStepInfoMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestStepInfoMessage(tree);
}

void QuestStepInfoMessage::deserializeAsyncAs_QuestStepInfoMessage(FuncTree tree)
{
  this->_infostree = tree.addChild(std::bind(&QuestStepInfoMessage::_infostreeFunc, this, std::placeholders::_1));
}

void QuestStepInfoMessage::_infostreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->infos = qSharedPointerCast<QuestActiveInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->infos->deserializeAsync(this->_infostree);
}

QuestStepInfoMessage::QuestStepInfoMessage()
{
  m_type = MessageEnum::QUESTSTEPINFOMESSAGE;
}

