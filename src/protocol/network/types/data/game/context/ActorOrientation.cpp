#include "ActorOrientation.h"

void ActorOrientation::serialize(Writer *output)
{
  this->serializeAs_ActorOrientation(output);
}

void ActorOrientation::serializeAs_ActorOrientation(Writer *output)
{
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->id << ") on element id.";
  }
  output->writeDouble(this->id);
  output->writeByte(this->direction);
}

void ActorOrientation::deserialize(Reader *input)
{
  this->deserializeAs_ActorOrientation(input);
}

void ActorOrientation::deserializeAs_ActorOrientation(Reader *input)
{
  this->_idFunc(input);
  this->_directionFunc(input);
}

void ActorOrientation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActorOrientation(tree);
}

void ActorOrientation::deserializeAsyncAs_ActorOrientation(FuncTree tree)
{
  tree.addChild(std::bind(&ActorOrientation::_idFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&ActorOrientation::_directionFunc, this, std::placeholders::_1));
}

void ActorOrientation::_idFunc(Reader *input)
{
  this->id = input->readDouble();
  if(this->id < -9007199254740992 || this->id > 9007199254740992)
  {
    qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->id << ") on element of ActorOrientation.id.";
  }
}

void ActorOrientation::_directionFunc(Reader *input)
{
  this->direction = input->readByte();
  if(this->direction < 0)
  {
    qDebug()<<"ERREUR - ActorOrientation -"<<"Forbidden value (" << this->direction << ") on element of ActorOrientation.direction.";
  }
}

ActorOrientation::ActorOrientation()
{
  m_types<<ClassEnum::ACTORORIENTATION;
}

bool ActorOrientation::operator==(const ActorOrientation &compared)
{
  if(id == compared.id)
  if(direction == compared.direction)
  return true;
  
  return false;
}

