#include "BasicCharactersListMessage.h"

void BasicCharactersListMessage::serialize(Writer *output)
{
  this->serializeAs_BasicCharactersListMessage(output);
}

void BasicCharactersListMessage::serializeAs_BasicCharactersListMessage(Writer *output)
{
  output->writeShort((short)this->characters.size());
  for(uint _i1 = 0; _i1 < this->characters.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterBaseInformations>(this->characters[_i1])->getTypes().last());
    qSharedPointerCast<CharacterBaseInformations>(this->characters[_i1])->serialize(output);
  }
}

void BasicCharactersListMessage::deserialize(Reader *input)
{
  this->deserializeAs_BasicCharactersListMessage(input);
}

void BasicCharactersListMessage::deserializeAs_BasicCharactersListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<CharacterBaseInformations> _item1 ;
  uint _charactersLen = input->readUShort();
  for(uint _i1 = 0; _i1 < _charactersLen; _i1++)
  {
    _id1 = input->readUShort();
    _item1 = qSharedPointerCast<CharacterBaseInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->characters.append(_item1);
  }
}

void BasicCharactersListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_BasicCharactersListMessage(tree);
}

void BasicCharactersListMessage::deserializeAsyncAs_BasicCharactersListMessage(FuncTree tree)
{
  this->_characterstree = tree.addChild(std::bind(&BasicCharactersListMessage::_characterstreeFunc, this, std::placeholders::_1));
}

void BasicCharactersListMessage::_characterstreeFunc(Reader *input)
{
  uint length = input->readUShort();
  for(uint i = 0; i < length; i++)
  {
    this->_characterstree.addChild(std::bind(&BasicCharactersListMessage::_charactersFunc, this, std::placeholders::_1));
  }
}

void BasicCharactersListMessage::_charactersFunc(Reader *input)
{
  uint _id = input->readUShort();
  QSharedPointer<CharacterBaseInformations> _item = qSharedPointerCast<CharacterBaseInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->characters.append(_item);
}

BasicCharactersListMessage::BasicCharactersListMessage()
{
  m_type = MessageEnum::BASICCHARACTERSLISTMESSAGE;
}

