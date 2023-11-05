#include "ConsoleCommandsListMessage.h"

void ConsoleCommandsListMessage::serialize(Writer *output)
{
  this->serializeAs_ConsoleCommandsListMessage(output);
}

void ConsoleCommandsListMessage::serializeAs_ConsoleCommandsListMessage(Writer *output)
{
  output->writeShort((short)this->aliases.size());
  for(uint _i1 = 0; _i1 < this->aliases.size(); _i1++)
  {
    output->writeUTF(this->aliases[_i1]);
  }
  output->writeShort((short)this->args.size());
  for(uint _i2 = 0; _i2 < this->args.size(); _i2++)
  {
    output->writeUTF(this->args[_i2]);
  }
  output->writeShort((short)this->descriptions.size());
  for(uint _i3 = 0; _i3 < this->descriptions.size(); _i3++)
  {
    output->writeUTF(this->descriptions[_i3]);
  }
}

void ConsoleCommandsListMessage::deserialize(Reader *input)
{
  this->deserializeAs_ConsoleCommandsListMessage(input);
}

void ConsoleCommandsListMessage::deserializeAs_ConsoleCommandsListMessage(Reader *input)
{
  QString _val1 ;
  QString _val2 ;
  QString _val3 ;
  uint _aliasesLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _aliasesLen; _i1++)
  {
    _val1 = String(input->readUTF());
    this->aliases.append(_val1);
  }
  uint _argsLen = uint(input->readUShort());
  for(uint _i2 = 0; _i2 < _argsLen; _i2++)
  {
    _val2 = String(input->readUTF());
    this->args.append(_val2);
  }
  uint _descriptionsLen = uint(input->readUShort());
  for(uint _i3 = 0; _i3 < _descriptionsLen; _i3++)
  {
    _val3 = String(input->readUTF());
    this->descriptions.append(_val3);
  }
}

void ConsoleCommandsListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_ConsoleCommandsListMessage(tree);
}

void ConsoleCommandsListMessage::deserializeAsyncAs_ConsoleCommandsListMessage(FuncTree tree)
{
  this->_aliasestree = tree.addChild(std::bind(&ConsoleCommandsListMessage::_aliasestreeFunc, this, std::placeholders::_1));
  this->_argstree = tree.addChild(std::bind(&ConsoleCommandsListMessage::_argstreeFunc, this, std::placeholders::_1));
  this->_descriptionstree = tree.addChild(std::bind(&ConsoleCommandsListMessage::_descriptionstreeFunc, this, std::placeholders::_1));
}

void ConsoleCommandsListMessage::_aliasestreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_aliasestree.addChild(std::bind(&ConsoleCommandsListMessage::_aliasesFunc, this, std::placeholders::_1));
  }
}

void ConsoleCommandsListMessage::_aliasesFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->aliases.append(_val);
}

void ConsoleCommandsListMessage::_argstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_argstree.addChild(std::bind(&ConsoleCommandsListMessage::_argsFunc, this, std::placeholders::_1));
  }
}

void ConsoleCommandsListMessage::_argsFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->args.append(_val);
}

void ConsoleCommandsListMessage::_descriptionstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_descriptionstree.addChild(std::bind(&ConsoleCommandsListMessage::_descriptionsFunc, this, std::placeholders::_1));
  }
}

void ConsoleCommandsListMessage::_descriptionsFunc(Reader *input)
{
  QString _val = String(input->readUTF());
  this->descriptions.append(_val);
}

ConsoleCommandsListMessage::ConsoleCommandsListMessage()
{
  m_type = MessageEnum::CONSOLECOMMANDSLISTMESSAGE;
}

