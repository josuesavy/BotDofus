#include "ServerExperienceModificatorMessage.h"

void ServerExperienceModificatorMessage::serialize(Writer *output)
{
  this->serializeAs_ServerExperienceModificatorMessage(output);
}

void ServerExperienceModificatorMessage::serializeAs_ServerExperienceModificatorMessage(Writer *output)
{
  if(this->experiencePercent < 0)
  {
    qDebug()<<"ERREUR - ServerExperienceModificatorMessage -"<<"Forbidden value (" << this->experiencePercent << ") on element experiencePercent.";
  }
  output->writeVarShort((int)this->experiencePercent);
}

void ServerExperienceModificatorMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerExperienceModificatorMessage(input);
}

void ServerExperienceModificatorMessage::deserializeAs_ServerExperienceModificatorMessage(Reader *input)
{
  this->_experiencePercentFunc(input);
}

void ServerExperienceModificatorMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerExperienceModificatorMessage(tree);
}

void ServerExperienceModificatorMessage::deserializeAsyncAs_ServerExperienceModificatorMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ServerExperienceModificatorMessage::_experiencePercentFunc, this, std::placeholders::_1));
}

void ServerExperienceModificatorMessage::_experiencePercentFunc(Reader *input)
{
  this->experiencePercent = input->readVarUhShort();
  if(this->experiencePercent < 0)
  {
    qDebug()<<"ERREUR - ServerExperienceModificatorMessage -"<<"Forbidden value (" << this->experiencePercent << ") on element of ServerExperienceModificatorMessage.experiencePercent.";
  }
}

ServerExperienceModificatorMessage::ServerExperienceModificatorMessage()
{
  m_type = MessageEnum::SERVEREXPERIENCEMODIFICATORMESSAGE;
}

