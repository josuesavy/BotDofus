#include "QuestObjectiveInformationsWithCompletion.h"

void QuestObjectiveInformationsWithCompletion::serialize(Writer *output)
{
  this->serializeAs_QuestObjectiveInformationsWithCompletion(output);
}

void QuestObjectiveInformationsWithCompletion::serializeAs_QuestObjectiveInformationsWithCompletion(Writer *output)
{
  QuestObjectiveInformations::serializeAs_QuestObjectiveInformations(output);
  if(this->curCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->curCompletion << ") on element curCompletion.";
  }
  output->writeVarShort((int)this->curCompletion);
  if(this->maxCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->maxCompletion << ") on element maxCompletion.";
  }
  output->writeVarShort((int)this->maxCompletion);
}

void QuestObjectiveInformationsWithCompletion::deserialize(Reader *input)
{
  this->deserializeAs_QuestObjectiveInformationsWithCompletion(input);
}

void QuestObjectiveInformationsWithCompletion::deserializeAs_QuestObjectiveInformationsWithCompletion(Reader *input)
{
  QuestObjectiveInformations::deserialize(input);
  this->_curCompletionFunc(input);
  this->_maxCompletionFunc(input);
}

void QuestObjectiveInformationsWithCompletion::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestObjectiveInformationsWithCompletion(tree);
}

void QuestObjectiveInformationsWithCompletion::deserializeAsyncAs_QuestObjectiveInformationsWithCompletion(FuncTree tree)
{
  QuestObjectiveInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&QuestObjectiveInformationsWithCompletion::_curCompletionFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestObjectiveInformationsWithCompletion::_maxCompletionFunc, this, std::placeholders::_1));
}

void QuestObjectiveInformationsWithCompletion::_curCompletionFunc(Reader *input)
{
  this->curCompletion = input->readVarUhShort();
  if(this->curCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->curCompletion << ") on element of QuestObjectiveInformationsWithCompletion.curCompletion.";
  }
}

void QuestObjectiveInformationsWithCompletion::_maxCompletionFunc(Reader *input)
{
  this->maxCompletion = input->readVarUhShort();
  if(this->maxCompletion < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformationsWithCompletion -"<<"Forbidden value (" << this->maxCompletion << ") on element of QuestObjectiveInformationsWithCompletion.maxCompletion.";
  }
}

QuestObjectiveInformationsWithCompletion::QuestObjectiveInformationsWithCompletion()
{
  m_types<<ClassEnum::QUESTOBJECTIVEINFORMATIONSWITHCOMPLETION;
}

bool QuestObjectiveInformationsWithCompletion::operator==(const QuestObjectiveInformationsWithCompletion &compared)
{
  if(curCompletion == compared.curCompletion)
  if(maxCompletion == compared.maxCompletion)
  return true;
  
  return false;
}

