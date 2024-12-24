#include "EmotePlayMassiveMessage.h"

void EmotePlayMassiveMessage::serialize(Writer *output)
{
  this->serializeAs_EmotePlayMassiveMessage(output);
}

void EmotePlayMassiveMessage::serializeAs_EmotePlayMassiveMessage(Writer *output)
{
  EmotePlayAbstractMessage::serializeAs_EmotePlayAbstractMessage(output);
  output->writeShort((short)this->actorIds.size());
  for(uint _i1 = 0; _i1 < this->actorIds.size(); _i1++)
  {
    if(this->actorIds[_i1] < -9007199254740992 || this->actorIds[_i1] > 9007199254740992)
    {
      qDebug()<<"ERREUR - EmotePlayMassiveMessage -"<<"Forbidden value (" << this->actorIds[_i1] << ") on element 1 (starting at 1) of actorIds.";
    }
    output->writeDouble(this->actorIds[_i1]);
  }
}

void EmotePlayMassiveMessage::deserialize(Reader *input)
{
  this->deserializeAs_EmotePlayMassiveMessage(input);
}

void EmotePlayMassiveMessage::deserializeAs_EmotePlayMassiveMessage(Reader *input)
{
  double _val1 = NULL;
  EmotePlayAbstractMessage::deserialize(input);
  uint _actorIdsLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _actorIdsLen; _i1++)
  {
    _val1 = double(input->readDouble());
    if(_val1 < -9007199254740992 || _val1 > 9007199254740992)
    {
      qDebug()<<"ERREUR - EmotePlayMassiveMessage -"<<"Forbidden value (" << _val1 << ") on elements of actorIds.";
    }
    this->actorIds.append(_val1);
  }
}

void EmotePlayMassiveMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_EmotePlayMassiveMessage(tree);
}

void EmotePlayMassiveMessage::deserializeAsyncAs_EmotePlayMassiveMessage(FuncTree tree)
{
  EmotePlayAbstractMessage::deserializeAsync(tree);
  this->_actorIdstree = tree.addChild(std::bind(&EmotePlayMassiveMessage::_actorIdstreeFunc, this, std::placeholders::_1));
}

void EmotePlayMassiveMessage::_actorIdstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_actorIdstree.addChild(std::bind(&EmotePlayMassiveMessage::_actorIdsFunc, this, std::placeholders::_1));
  }
}

void EmotePlayMassiveMessage::_actorIdsFunc(Reader *input)
{
  double _val = double(input->readDouble());
  if(_val < -9007199254740992 || _val > 9007199254740992)
  {
    qDebug()<<"ERREUR - EmotePlayMassiveMessage -"<<"Forbidden value (" << _val << ") on elements of actorIds.";
  }
  this->actorIds.append(_val);
}

EmotePlayMassiveMessage::EmotePlayMassiveMessage()
{
  m_type = MessageEnum::EMOTEPLAYMASSIVEMESSAGE;
}

