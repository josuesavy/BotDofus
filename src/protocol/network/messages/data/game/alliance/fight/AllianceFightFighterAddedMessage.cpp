#include "AllianceFightFighterAddedMessage.h"

void AllianceFightFighterAddedMessage::serialize(Writer *output)
{
  this->serializeAs_AllianceFightFighterAddedMessage(output);
}

void AllianceFightFighterAddedMessage::serializeAs_AllianceFightFighterAddedMessage(Writer *output)
{
  this->allianceFightInfo.serializeAs_SocialFightInfo(output);
  this->fighter->serializeAs_CharacterMinimalPlusLookInformations(output);
  output->writeByte(this->team);
}

void AllianceFightFighterAddedMessage::deserialize(Reader *input)
{
  this->deserializeAs_AllianceFightFighterAddedMessage(input);
}

void AllianceFightFighterAddedMessage::deserializeAs_AllianceFightFighterAddedMessage(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserialize(input);
  this->fighter = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
  this->fighter->deserialize(input);
  this->_teamFunc(input);
}

void AllianceFightFighterAddedMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_AllianceFightFighterAddedMessage(tree);
}

void AllianceFightFighterAddedMessage::deserializeAsyncAs_AllianceFightFighterAddedMessage(FuncTree tree)
{
  this->_allianceFightInfotree = tree.addChild(std::bind(&AllianceFightFighterAddedMessage::_allianceFightInfotreeFunc, this, std::placeholders::_1));
  this->_fightertree = tree.addChild(std::bind(&AllianceFightFighterAddedMessage::_fightertreeFunc, this, std::placeholders::_1));
  tree.addChild(std::bind(&AllianceFightFighterAddedMessage::_teamFunc, this, std::placeholders::_1));
}

void AllianceFightFighterAddedMessage::_allianceFightInfotreeFunc(Reader *input)
{
  this->allianceFightInfo = SocialFightInfo();
  this->allianceFightInfo.deserializeAsync(this->_allianceFightInfotree);
}

void AllianceFightFighterAddedMessage::_fightertreeFunc(Reader *input)
{
  this->fighter = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
  this->fighter->deserializeAsync(this->_fightertree);
}

void AllianceFightFighterAddedMessage::_teamFunc(Reader *input)
{
  this->team = input->readByte();
  if(this->team < 0)
  {
    qDebug()<<"ERREUR - AllianceFightFighterAddedMessage -"<<"Forbidden value (" << this->team << ") on element of AllianceFightFighterAddedMessage.team.";
  }
}

AllianceFightFighterAddedMessage::AllianceFightFighterAddedMessage()
{
  m_type = MessageEnum::ALLIANCEFIGHTFIGHTERADDEDMESSAGE;
}

