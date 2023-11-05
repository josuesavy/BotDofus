#include "CharactersListWithRemodelingMessage.h"

void CharactersListWithRemodelingMessage::serialize(Writer *output)
{
  this->serializeAs_CharactersListWithRemodelingMessage(output);
}

void CharactersListWithRemodelingMessage::serializeAs_CharactersListWithRemodelingMessage(Writer *output)
{
  CharactersListMessage::serializeAs_CharactersListMessage(output);
  output->writeShort((short)this->charactersToRemodel.size());
  for(uint _i1 = 0; _i1 < this->charactersToRemodel.size(); _i1++)
  {
    (this->charactersToRemodel[_i1]).serializeAs_CharacterToRemodelInformations(output);
  }
}

void CharactersListWithRemodelingMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharactersListWithRemodelingMessage(input);
}

void CharactersListWithRemodelingMessage::deserializeAs_CharactersListWithRemodelingMessage(Reader *input)
{
  CharacterToRemodelInformations _item1 ;
  CharactersListMessage::deserialize(input);
  uint _charactersToRemodelLen = uint(input->readUShort());
  for(uint _i1 = 0; _i1 < _charactersToRemodelLen; _i1++)
  {
    _item1 = CharacterToRemodelInformations();
    _item1.deserialize(input);
    this->charactersToRemodel.append(_item1);
  }
}

void CharactersListWithRemodelingMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharactersListWithRemodelingMessage(tree);
}

void CharactersListWithRemodelingMessage::deserializeAsyncAs_CharactersListWithRemodelingMessage(FuncTree tree)
{
  CharactersListMessage::deserializeAsync(tree);
  this->_charactersToRemodeltree = tree.addChild(std::bind(&CharactersListWithRemodelingMessage::_charactersToRemodeltreeFunc, this, std::placeholders::_1));
}

void CharactersListWithRemodelingMessage::_charactersToRemodeltreeFunc(Reader *input)
{
  uint length = uint(input->readUShort());
  for(uint i = 0; i < length; i++)
  {
    this->_charactersToRemodeltree.addChild(std::bind(&CharactersListWithRemodelingMessage::_charactersToRemodelFunc, this, std::placeholders::_1));
  }
}

void CharactersListWithRemodelingMessage::_charactersToRemodelFunc(Reader *input)
{
  CharacterToRemodelInformations _item = CharacterToRemodelInformations();
  _item.deserialize(input);
  this->charactersToRemodel.append(_item);
}

CharactersListWithRemodelingMessage::CharactersListWithRemodelingMessage()
{
  m_type = MessageEnum::CHARACTERSLISTWITHREMODELINGMESSAGE;
}

