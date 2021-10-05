#include "CurrentMapInstanceMessage.h"

void CurrentMapInstanceMessage::serialize(Writer *output)
{
  this->serializeAs_CurrentMapInstanceMessage(output);
}

void CurrentMapInstanceMessage::serializeAs_CurrentMapInstanceMessage(Writer *output)
{
  CurrentMapMessage::serializeAs_CurrentMapMessage(output);
  if(this->instantiatedMapId < 0 || this->instantiatedMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CurrentMapInstanceMessage -"<<"Forbidden value (" << this->instantiatedMapId << ") on element instantiatedMapId.";
  }
  output->writeDouble(this->instantiatedMapId);
}

void CurrentMapInstanceMessage::deserialize(Reader *input)
{
  this->deserializeAs_CurrentMapInstanceMessage(input);
}

void CurrentMapInstanceMessage::deserializeAs_CurrentMapInstanceMessage(Reader *input)
{
  CurrentMapMessage::deserialize(input);
  this->_instantiatedMapIdFunc(input);
}

void CurrentMapInstanceMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CurrentMapInstanceMessage(tree);
}

void CurrentMapInstanceMessage::deserializeAsyncAs_CurrentMapInstanceMessage(FuncTree tree)
{
  CurrentMapMessage::deserializeAsync(tree);
  tree.addChild(std::bind(&CurrentMapInstanceMessage::_instantiatedMapIdFunc, this, std::placeholders::_1));
}

void CurrentMapInstanceMessage::_instantiatedMapIdFunc(Reader *input)
{
  this->instantiatedMapId = input->readDouble();
  if(this->instantiatedMapId < 0 || this->instantiatedMapId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - CurrentMapInstanceMessage -"<<"Forbidden value (" << this->instantiatedMapId << ") on element of CurrentMapInstanceMessage.instantiatedMapId.";
  }
}

CurrentMapInstanceMessage::CurrentMapInstanceMessage()
{
  m_type = MessageEnum::CURRENTMAPINSTANCEMESSAGE;
}

