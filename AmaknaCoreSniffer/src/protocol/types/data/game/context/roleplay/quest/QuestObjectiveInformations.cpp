#include "QuestObjectiveInformations.h"

void QuestObjectiveInformations::serialize(Writer *output)
{
  this->serializeAs_QuestObjectiveInformations(output);
}

void QuestObjectiveInformations::serializeAs_QuestObjectiveInformations(Writer *output)
{
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformations -"<<"Forbidden value (" << this->objectiveId << ") on element objectiveId.";
  }
  output->writeVarShort((int)this->objectiveId);
  output->writeBool(this->objectiveStatus);
  output->writeShort((short)this->dialogParams.size());
  for(uint _i3 = 0; _i3 < this->dialogParams.size(); _i3++)
  {
    output->writeUTF(this->dialogParams[_i3]);
  }
}

void QuestObjectiveInformations::deserialize(Reader *input)
{
  this->deserializeAs_QuestObjectiveInformations(input);
}

void QuestObjectiveInformations::deserializeAs_QuestObjectiveInformations(Reader *input)
{
  QString _val3 ;
  this->_objectiveIdFunc(input);
  this->_objectiveStatusFunc(input);
  uint _dialogParamsLen = input->readUShort();
  for(uint _i3 = 0; _i3 < _dialogParamsLen; _i3++)
  {
    _val3 = input->readUTF();
    this->dialogParams.append(_val3);
  }
}

void QuestObjectiveInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_QuestObjectiveInformations(tree);
}

void QuestObjectiveInformations::deserializeAsyncAs_QuestObjectiveInformations(FuncTree tree)
{
  tree.addChild(std::bind(&QuestObjectiveInformations::_objectiveIdFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&QuestObjectiveInformations::_objectiveStatusFunc, this, std::placeholders::_1));
  this->_dialogParamstree = tree.addChild(std::bind(&QuestObjectiveInformations::_dialogParamstreeFunc, this, std::placeholders::_1));
}

void QuestObjectiveInformations::_objectiveIdFunc(Reader *input)
{
  this->objectiveId = input->readVarUhShort();
  if(this->objectiveId < 0)
  {
    qDebug()<<"ERREUR - QuestObjectiveInformations -"<<"Forbidden value (" << this->objectiveId << ") on element of QuestObjectiveInformations.objectiveId.";
  }
}

void QuestObjectiveInformations::_objectiveStatusFunc(Reader *input)
{
  this->objectiveStatus = input->readBool();
}

void QuestObjectiveInformations::_dialogParamstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_dialogParamstree.addChild(std::bind(&QuestObjectiveInformations::_dialogParamsFunc, this, std::placeholders::_1));
  }
}

void QuestObjectiveInformations::_dialogParamsFunc(Reader *input)
{
  QString _val = input->readUTF();
  this->dialogParams.append(_val);
}

QuestObjectiveInformations::QuestObjectiveInformations()
{
  m_types<<ClassEnum::QUESTOBJECTIVEINFORMATIONS;
}

bool QuestObjectiveInformations::operator==(const QuestObjectiveInformations &compared)
{
  if(objectiveId == compared.objectiveId)
  if(objectiveStatus == compared.objectiveStatus)
  if(dialogParams == compared.dialogParams)
  if(_dialogParamstree == compared._dialogParamstree)
  return true;
  
  return false;
}

