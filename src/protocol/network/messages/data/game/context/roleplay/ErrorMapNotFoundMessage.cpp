#include "ErrorMapNotFoundMessage.h"

void ErrorMapNotFoundMessage::serialize(Writer *output)
{
  this->serializeAs_ErrorMapNotFoundMessage(output);
}

void ErrorMapNotFoundMessage::serializeAs_ErrorMapNotFoundMessage(Writer *output)
{
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ErrorMapNotFoundMessage -"<<"Forbidden value (" << this->mapId << ") on element mapId.";
  }
  output->writeDouble(this->mapId);
}

void ErrorMapNotFoundMessage::deserialize(Reader *input)
{
  this->deserializeAs_ErrorMapNotFoundMessage(input);
}

void ErrorMapNotFoundMessage::deserializeAs_ErrorMapNotFoundMessage(Reader *input)
{
  this->_mapIdFunc(input);
}

void ErrorMapNotFoundMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ErrorMapNotFoundMessage(tree);
}

void ErrorMapNotFoundMessage::deserializeAsyncAs_ErrorMapNotFoundMessage(FuncTree tree)
{
  tree.addChild(std::bind(&ErrorMapNotFoundMessage::_mapIdFunc, this, std::placeholders::_1));
}

void ErrorMapNotFoundMessage::_mapIdFunc(Reader *input)
{
  this->mapId = input->readDouble();
  if(this->mapId < 0 || this->mapId > 9007199254740992)
  {
    qDebug()<<"ERREUR - ErrorMapNotFoundMessage -"<<"Forbidden value (" << this->mapId << ") on element of ErrorMapNotFoundMessage.mapId.";
  }
}

ErrorMapNotFoundMessage::ErrorMapNotFoundMessage()
{
  m_type = MessageEnum::ERRORMAPNOTFOUNDMESSAGE;
}

