#include "ServerOptionalFeaturesMessage.h"

void ServerOptionalFeaturesMessage::serialize(Writer *output)
{
  this->serializeAs_ServerOptionalFeaturesMessage(output);
}

void ServerOptionalFeaturesMessage::serializeAs_ServerOptionalFeaturesMessage(Writer *output)
{
  output->writeShort((short)this->features.size());
  for(uint _i1 = 0; _i1 < this->features.size(); _i1++)
  {
    if(this->features[_i1] < 0)
    {
      qDebug()<<"ERREUR - ServerOptionalFeaturesMessage -"<<"Forbidden value (" << this->features[_i1] << ") on element 1 (starting at 1) of features.";
    }
    output->writeInt((int)this->features[_i1]);
  }
}

void ServerOptionalFeaturesMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerOptionalFeaturesMessage(input);
}

void ServerOptionalFeaturesMessage::deserializeAs_ServerOptionalFeaturesMessage(Reader *input)
{
  uint _val1 = 0;
  uint _featuresLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _featuresLen; _i1++)
  {
    _val1 = uint(input->readInt());
    if(_val1 < 0)
    {
      qDebug()<<"ERREUR - ServerOptionalFeaturesMessage -"<<"Forbidden value (" << _val1 << ") on elements of features.";
    }
    this->features.append(_val1);
  }
}

void ServerOptionalFeaturesMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerOptionalFeaturesMessage(tree);
}

void ServerOptionalFeaturesMessage::deserializeAsyncAs_ServerOptionalFeaturesMessage(FuncTree tree)
{
  this->_featurestree = tree.addChild(std::bind(&ServerOptionalFeaturesMessage::_featurestreeFunc, this, std::placeholders::_1));
}

void ServerOptionalFeaturesMessage::_featurestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_featurestree.addChild(std::bind(&ServerOptionalFeaturesMessage::_featuresFunc, this, std::placeholders::_1));
  }
}

void ServerOptionalFeaturesMessage::_featuresFunc(Reader *input)
{
  uint _val = uint(input->readInt());
  if(_val < 0)
  {
    qDebug()<<"ERREUR - ServerOptionalFeaturesMessage -"<<"Forbidden value (" << _val << ") on elements of features.";
  }
  this->features.append(_val);
}

ServerOptionalFeaturesMessage::ServerOptionalFeaturesMessage()
{
  m_type = MessageEnum::SERVEROPTIONALFEATURESMESSAGE;
}

