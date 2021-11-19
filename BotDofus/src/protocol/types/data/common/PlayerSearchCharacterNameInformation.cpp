#include "PlayerSearchCharacterNameInformation.h"

void PlayerSearchCharacterNameInformation::serialize(Writer *output)
{
  this->serializeAs_PlayerSearchCharacterNameInformation(output);
}

void PlayerSearchCharacterNameInformation::serializeAs_PlayerSearchCharacterNameInformation(Writer *output)
{
  AbstractPlayerSearchInformation::serializeAs_AbstractPlayerSearchInformation(output);
  output->writeUTF(this->name);
}

void PlayerSearchCharacterNameInformation::deserialize(Reader *input)
{
  this->deserializeAs_PlayerSearchCharacterNameInformation(input);
}

void PlayerSearchCharacterNameInformation::deserializeAs_PlayerSearchCharacterNameInformation(Reader *input)
{
  AbstractPlayerSearchInformation::deserialize(input);
  this->_nameFunc(input);
}

void PlayerSearchCharacterNameInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_PlayerSearchCharacterNameInformation(tree);
}

void PlayerSearchCharacterNameInformation::deserializeAsyncAs_PlayerSearchCharacterNameInformation(FuncTree tree)
{
  AbstractPlayerSearchInformation::deserializeAsync(tree);
  tree.addChild(std::bind(&PlayerSearchCharacterNameInformation::_nameFunc, this, std::placeholders::_1));
}

void PlayerSearchCharacterNameInformation::_nameFunc(Reader *input)
{
  this->name = input->readUTF();
}

PlayerSearchCharacterNameInformation::PlayerSearchCharacterNameInformation()
{
  m_types<<ClassEnum::PLAYERSEARCHCHARACTERNAMEINFORMATION;
}

bool PlayerSearchCharacterNameInformation::operator==(const PlayerSearchCharacterNameInformation &compared)
{
  if(name == compared.name)
  return true;
  
  return false;
}

