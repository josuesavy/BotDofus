#include "ActivityHideRequestMessage.h"

void ActivityHideRequestMessage::serialize(Writer *output)
{
  this->serializeAs_ActivityHideRequestMessage(output);
}

void ActivityHideRequestMessage::serializeAs_ActivityHideRequestMessage(Writer *output)
{
  if(this->activityId < 0)
  {
    qDebug()<<"ERREUR - ActivityHideRequestMessage -"<<"Forbidden value (" << this->activityId << ") on element activityId.";
  }
  output->writeVarShort((int)this->activityId);
}

void ActivityHideRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_ActivityHideRequestMessage(input);
}

void ActivityHideRequestMessage::deserializeAs_ActivityHideRequestMessage(Reader *input)
{
  this->_activityIdFunc(input);
}

void ActivityHideRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ActivityHideRequestMessage(tree);
}

void ActivityHideRequestMessage::deserializeAsyncAs_ActivityHideRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ActivityHideRequestMessage::_activityIdFunc, this, std::placeholders::_1));
}

void ActivityHideRequestMessage::_activityIdFunc(Reader *input)
{
  this->activityId = input->readVarUhShort();
  if(this->activityId < 0)
  {
    qDebug()<<"ERREUR - ActivityHideRequestMessage -"<<"Forbidden value (" << this->activityId << ") on element of ActivityHideRequestMessage.activityId.";
  }
}

ActivityHideRequestMessage::ActivityHideRequestMessage()
{
  m_type = MessageEnum::ACTIVITYHIDEREQUESTMESSAGE;
}

