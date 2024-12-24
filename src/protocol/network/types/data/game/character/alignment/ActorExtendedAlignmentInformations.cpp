#include "ActorExtendedAlignmentInformations.h"

void ActorExtendedAlignmentInformations::serialize(Writer *output)
{
  this->serializeAs_ActorExtendedAlignmentInformations(output);
}

void ActorExtendedAlignmentInformations::serializeAs_ActorExtendedAlignmentInformations(Writer *output)
{
  ActorAlignmentInformations::serializeAs_ActorAlignmentInformations(output);
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honor << ") on element honor.";
  }
  output->writeVarShort((int)this->honor);
  if(this->honorGradeFloor < 0 || this->honorGradeFloor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorGradeFloor << ") on element honorGradeFloor.";
  }
  output->writeVarShort((int)this->honorGradeFloor);
  if(this->honorNextGradeFloor < 0 || this->honorNextGradeFloor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorNextGradeFloor << ") on element honorNextGradeFloor.";
  }
  output->writeVarShort((int)this->honorNextGradeFloor);
  output->writeByte(this->aggressable);
}

void ActorExtendedAlignmentInformations::deserialize(Reader *input)
{
  this->deserializeAs_ActorExtendedAlignmentInformations(input);
}

void ActorExtendedAlignmentInformations::deserializeAs_ActorExtendedAlignmentInformations(Reader *input)
{
  ActorAlignmentInformations::deserialize(input);
  this->_honorFunc(input);
  this->_honorGradeFloorFunc(input);
  this->_honorNextGradeFloorFunc(input);
  this->_aggressableFunc(input);
}

void ActorExtendedAlignmentInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActorExtendedAlignmentInformations(tree);
}

void ActorExtendedAlignmentInformations::deserializeAsyncAs_ActorExtendedAlignmentInformations(FuncTree tree)
{
  ActorAlignmentInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&ActorExtendedAlignmentInformations::_honorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorExtendedAlignmentInformations::_honorGradeFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorExtendedAlignmentInformations::_honorNextGradeFloorFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorExtendedAlignmentInformations::_aggressableFunc, this, std::placeholders::_1));
}

void ActorExtendedAlignmentInformations::_honorFunc(Reader *input)
{
  this->honor = input->readVarUhShort();
  if(this->honor < 0 || this->honor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honor << ") on element of ActorExtendedAlignmentInformations.honor.";
  }
}

void ActorExtendedAlignmentInformations::_honorGradeFloorFunc(Reader *input)
{
  this->honorGradeFloor = input->readVarUhShort();
  if(this->honorGradeFloor < 0 || this->honorGradeFloor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorGradeFloor << ") on element of ActorExtendedAlignmentInformations.honorGradeFloor.";
  }
}

void ActorExtendedAlignmentInformations::_honorNextGradeFloorFunc(Reader *input)
{
  this->honorNextGradeFloor = input->readVarUhShort();
  if(this->honorNextGradeFloor < 0 || this->honorNextGradeFloor > 20000)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->honorNextGradeFloor << ") on element of ActorExtendedAlignmentInformations.honorNextGradeFloor.";
  }
}

void ActorExtendedAlignmentInformations::_aggressableFunc(Reader *input)
{
  this->aggressable = input->readByte();
  if(this->aggressable < 0)
  {
    qDebug()<<"ERREUR - ActorExtendedAlignmentInformations -"<<"Forbidden value (" << this->aggressable << ") on element of ActorExtendedAlignmentInformations.aggressable.";
  }
}

ActorExtendedAlignmentInformations::ActorExtendedAlignmentInformations()
{
  m_types<<ClassEnum::ACTOREXTENDEDALIGNMENTINFORMATIONS;
}

bool ActorExtendedAlignmentInformations::operator==(const ActorExtendedAlignmentInformations &compared)
{
  if(honor == compared.honor)
  if(honorGradeFloor == compared.honorGradeFloor)
  if(honorNextGradeFloor == compared.honorNextGradeFloor)
  if(aggressable == compared.aggressable)
  return true;
  
  return false;
}

