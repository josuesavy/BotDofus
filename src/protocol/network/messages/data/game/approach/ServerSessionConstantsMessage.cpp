#include "ServerSessionConstantsMessage.h"

void ServerSessionConstantsMessage::serialize(Writer *output)
{
  this->serializeAs_ServerSessionConstantsMessage(output);
}

void ServerSessionConstantsMessage::serializeAs_ServerSessionConstantsMessage(Writer *output)
{
  output->writeShort((short)this->variables.size());
  for(uint _i1 = 0; _i1 < this->variables.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<ServerSessionConstant>(this->variables[_i1])->getTypes().last());
    qSharedPointerCast<ServerSessionConstant>(this->variables[_i1])->serialize(output);
  }
}

void ServerSessionConstantsMessage::deserialize(Reader *input)
{
  this->deserializeAs_ServerSessionConstantsMessage(input);
}

void ServerSessionConstantsMessage::deserializeAs_ServerSessionConstantsMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<ServerSessionConstant> _item1 ;
  uint _variablesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _variablesLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<ServerSessionConstant>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->variables.append(_item1);
  }
}

void ServerSessionConstantsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ServerSessionConstantsMessage(tree);
}

void ServerSessionConstantsMessage::deserializeAsyncAs_ServerSessionConstantsMessage(FuncTree tree)
{
  this->_variablestree = tree.addChild(std::bind(&ServerSessionConstantsMessage::_variablestreeFunc, this, std::placeholders::_1));
}

void ServerSessionConstantsMessage::_variablestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_variablestree.addChild(std::bind(&ServerSessionConstantsMessage::_variablesFunc, this, std::placeholders::_1));
  }
}

void ServerSessionConstantsMessage::_variablesFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<ServerSessionConstant> _item = qSharedPointerCast<ServerSessionConstant>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->variables.append(_item);
}

ServerSessionConstantsMessage::ServerSessionConstantsMessage()
{
  m_type = MessageEnum::SERVERSESSIONCONSTANTSMESSAGE;
}

