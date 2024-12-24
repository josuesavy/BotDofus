#include "CharactersListMessage.h"

void CharactersListMessage::serialize(Writer *output)
{
  this->serializeAs_CharactersListMessage(output);
}

void CharactersListMessage::serializeAs_CharactersListMessage(Writer *output)
{
  output->writeShort((short)this->characters.size());
  for(uint _i1 = 0; _i1 < this->characters.size(); _i1++)
  {
    output->writeShort((short)qSharedPointerCast<CharacterBaseInformations>(this->characters[_i1])->getTypes().last());
    qSharedPointerCast<CharacterBaseInformations>(this->characters[_i1])->serialize(output);
  }
}

void CharactersListMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharactersListMessage(input);
}

void CharactersListMessage::deserializeAs_CharactersListMessage(Reader *input)
{
  uint _id1 = 0;
  QSharedPointer<CharacterBaseInformations> _item1 ;
  uint _charactersLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _charactersLen; _i1++)
  {
    _id1 = uint(input->readUShort());
    _item1 = qSharedPointerCast<CharacterBaseInformations>(ClassManagerSingleton::get()->getClass(_id1));
    _item1->deserialize(input);
    this->characters.append(_item1);
  }
}

void CharactersListMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharactersListMessage(tree);
}

void CharactersListMessage::deserializeAsyncAs_CharactersListMessage(FuncTree tree)
{
  this->_characterstree = tree.addChild(std::bind(&CharactersListMessage::_characterstreeFunc, this, std::placeholders::_1));
}

void CharactersListMessage::_characterstreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_characterstree.addChild(std::bind(&CharactersListMessage::_charactersFunc, this, std::placeholders::_1));
  }
}

void CharactersListMessage::_charactersFunc(Reader *input)
{
  uint _id = uint(input->readUShort());
  QSharedPointer<CharacterBaseInformations> _item = qSharedPointerCast<CharacterBaseInformations>(ClassManagerSingleton::get()->getClass(_id));
  _item->deserialize(input);
  this->characters.append(_item);
}

CharactersListMessage::CharactersListMessage()
{
  m_type = MessageEnum::CHARACTERSLISTMESSAGE;
}

