#include "QuestActiveInformations.h"

void QuestActiveInformations::serialize(Writer *output)
{
  this->serializeAs_QuestActiveInformations(output);
}

void QuestActiveInformations::serializeAs_QuestActiveInformations(Writer *output)
{
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveInformations -"<<"Forbidden value (" << this->questId << ") on element questId.";
  }
  output->writeVarShort((int)this->questId);
}

void QuestActiveInformations::deserialize(Reader *input)
{
  this->deserializeAs_QuestActiveInformations(input);
}

void QuestActiveInformations::deserializeAs_QuestActiveInformations(Reader *input)
{
  this->_questIdFunc(input);
}

void QuestActiveInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestActiveInformations(tree);
}

void QuestActiveInformations::deserializeAsyncAs_QuestActiveInformations(FuncTree tree)
{
  tree.addChild(std::bind(&QuestActiveInformations::_questIdFunc, this, std::placeholders::_1));
}

void QuestActiveInformations::_questIdFunc(Reader *input)
{
  this->questId = input->readVarUhShort();
  if(this->questId < 0)
  {
    qDebug()<<"ERREUR - QuestActiveInformations -"<<"Forbidden value (" << this->questId << ") on element of QuestActiveInformations.questId.";
  }
}

QuestActiveInformations::QuestActiveInformations()
{
  m_types<<ClassEnum::QUESTACTIVEINFORMATIONS;
}

bool QuestActiveInformations::operator==(const QuestActiveInformations &compared)
{
  if(questId == compared.questId)
  return true;
  
  return false;
}

