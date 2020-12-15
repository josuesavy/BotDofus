#include "SpouseInformationsMessage.h"

void SpouseInformationsMessage::serialize(Writer *output)
{
  this->serializeAs_SpouseInformationsMessage(output);
}

void SpouseInformationsMessage::serializeAs_SpouseInformationsMessage(Writer *output)
{
  output->writeShort((short)this->spouse->getTypes().last());
  this->spouse->serialize(output);
}

void SpouseInformationsMessage::deserialize(Reader *input)
{
  this->deserializeAs_SpouseInformationsMessage(input);
}

void SpouseInformationsMessage::deserializeAs_SpouseInformationsMessage(Reader *input)
{
  uint _id1 = input->readUShort();
  this->spouse = qSharedPointerCast<FriendSpouseInformations>(ClassManagerSingleton::get()->getClass(_id1));
  this->spouse->deserialize(input);
}

void SpouseInformationsMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_SpouseInformationsMessage(tree);
}

void SpouseInformationsMessage::deserializeAsyncAs_SpouseInformationsMessage(FuncTree tree)
{
  this->_spousetree = tree.addChild(std::bind(&SpouseInformationsMessage::_spousetreeFunc, this, std::placeholders::_1));
}

void SpouseInformationsMessage::_spousetreeFunc(Reader *input)
{
  uint _id = input->readUShort();
  this->spouse = qSharedPointerCast<FriendSpouseInformations>(ClassManagerSingleton::get()->getClass(_id));
  this->spouse->deserializeAsync(this->_spousetree);
}

SpouseInformationsMessage::SpouseInformationsMessage()
{
  m_type = MessageEnum::SPOUSEINFORMATIONSMESSAGE;
}

