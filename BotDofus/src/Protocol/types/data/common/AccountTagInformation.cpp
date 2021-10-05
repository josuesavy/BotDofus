#include "AccountTagInformation.h"

void AccountTagInformation::serialize(Writer *output)
{
  this->serializeAs_AccountTagInformation(output);
}

void AccountTagInformation::serializeAs_AccountTagInformation(Writer *output)
{
  output->writeUTF(this->nickname);
  output->writeUTF(this->tagNumber);
}

void AccountTagInformation::deserialize(Reader *input)
{
  this->deserializeAs_AccountTagInformation(input);
}

void AccountTagInformation::deserializeAs_AccountTagInformation(Reader *input)
{
  this->_nicknameFunc(input);
  this->_tagNumberFunc(input);
}

void AccountTagInformation::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AccountTagInformation(tree);
}

void AccountTagInformation::deserializeAsyncAs_AccountTagInformation(FuncTree tree)
{
  tree.addChild(std::bind(&AccountTagInformation::_nicknameFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AccountTagInformation::_tagNumberFunc, this, std::placeholders::_1));
}

void AccountTagInformation::_nicknameFunc(Reader *input)
{
  this->nickname = input->readUTF();
}

void AccountTagInformation::_tagNumberFunc(Reader *input)
{
  this->tagNumber = input->readUTF();
}

AccountTagInformation::AccountTagInformation()
{
  m_types<<ClassEnum::ACCOUNTTAGINFORMATION;
}

bool AccountTagInformation::operator==(const AccountTagInformation &compared)
{
  if(nickname == compared.nickname)
  if(tagNumber == compared.tagNumber)
  return true;
  
  return false;
}

