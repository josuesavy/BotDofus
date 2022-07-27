#include "CharacterCreationRequestMessage.h"

void CharacterCreationRequestMessage::serialize(Writer *output)
{
  this->serializeAs_CharacterCreationRequestMessage(output);
}

void CharacterCreationRequestMessage::serializeAs_CharacterCreationRequestMessage(Writer *output)
{
  output->writeUTF(this->name);
  output->writeByte(this->breed);
  output->writeBool(this->sex);
  for(uint _i4 = 0; _i4 < 5; _i4++)
  {
    output->writeInt((int)this->colors[_i4]);
  }
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->cosmeticId << ") on element cosmeticId.";
  }
  output->writeVarShort((int)this->cosmeticId);
}

void CharacterCreationRequestMessage::deserialize(Reader *input)
{
  this->deserializeAs_CharacterCreationRequestMessage(input);
}

void CharacterCreationRequestMessage::deserializeAs_CharacterCreationRequestMessage(Reader *input)
{
  this->_nameFunc(input);
  this->_breedFunc(input);
  this->_sexFunc(input);
  for(uint _i4 = 0; _i4 < 5; _i4++)
  {
    this->colors<<input->readInt();
  }
  this->_cosmeticIdFunc(input);
}

void CharacterCreationRequestMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_CharacterCreationRequestMessage(tree);
}

void CharacterCreationRequestMessage::deserializeAsyncAs_CharacterCreationRequestMessage(FuncTree tree)
{
  tree.addChild(std::bind(&CharacterCreationRequestMessage::_nameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCreationRequestMessage::_breedFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCreationRequestMessage::_sexFunc, this, std::placeholders::_1));
  this->_colorstree = tree.addChild(std::bind(&CharacterCreationRequestMessage::_colorstreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&CharacterCreationRequestMessage::_cosmeticIdFunc, this, std::placeholders::_1));
}

void CharacterCreationRequestMessage::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

void CharacterCreationRequestMessage::_breedFunc(Reader *input)
{
  this->breed = input->readByte();
  if(this->breed < (int)PlayableBreedEnum::FECA || this->breed > (int)PlayableBreedEnum::OUGINAK)
  {
    qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->breed << ") on element of CharacterCreationRequestMessage.breed.";
  }
}

void CharacterCreationRequestMessage::_sexFunc(Reader *input)
{
  this->sex = input->readBool();
}

void CharacterCreationRequestMessage::_colorstreeFunc(Reader *input)
{
  for(uint i = 0; i < 5; i++)
  {
    this->_colorstree.addChild(std::bind(&CharacterCreationRequestMessage::_colorsFunc, this, std::placeholders::_1));
  }
}

void CharacterCreationRequestMessage::_colorsFunc(Reader *input)
{
  this->colors<<input->readInt();
  this->_colorsindex++;
}

void CharacterCreationRequestMessage::_cosmeticIdFunc(Reader *input)
{
  this->cosmeticId = input->readVarUhShort();
  if(this->cosmeticId < 0)
  {
    qDebug()<<"ERREUR - CharacterCreationRequestMessage -"<<"Forbidden value (" << this->cosmeticId << ") on element of CharacterCreationRequestMessage.cosmeticId.";
  }
}

CharacterCreationRequestMessage::CharacterCreationRequestMessage()
{
  m_type = MessageEnum::CHARACTERCREATIONREQUESTMESSAGE;
}

