#include "GuildFightPlayersHelpersJoinMessage.h"

void GuildFightPlayersHelpersJoinMessage::serialize(Writer *output)
{
  this->serializeAs_GuildFightPlayersHelpersJoinMessage(output);
}

void GuildFightPlayersHelpersJoinMessage::serializeAs_GuildFightPlayersHelpersJoinMessage(Writer *output)
{
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersJoinMessage -"<<"Forbidden value (" << this->fightId << ") on element fightId.";
  }
  output->writeDouble(this->fightId);
  this->playerInfo->serializeAs_CharacterMinimalPlusLookInformations(output);
}

void GuildFightPlayersHelpersJoinMessage::deserialize(Reader *input)
{
  this->deserializeAs_GuildFightPlayersHelpersJoinMessage(input);
}

void GuildFightPlayersHelpersJoinMessage::deserializeAs_GuildFightPlayersHelpersJoinMessage(Reader *input)
{
  this->_fightIdFunc(input);
  this->playerInfo = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
  this->playerInfo->deserialize(input);
}

void GuildFightPlayersHelpersJoinMessage::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildFightPlayersHelpersJoinMessage(tree);
}

void GuildFightPlayersHelpersJoinMessage::deserializeAsyncAs_GuildFightPlayersHelpersJoinMessage(FuncTree tree)
{
  tree.addChild(std::bind(&GuildFightPlayersHelpersJoinMessage::_fightIdFunc, this, std::placeholders::_1));
  this->_playerInfotree = tree.addChild(std::bind(&GuildFightPlayersHelpersJoinMessage::_playerInfotreeFunc, this, std::placeholders::_1));
}

void GuildFightPlayersHelpersJoinMessage::_fightIdFunc(Reader *input)
{
  this->fightId = input->readDouble();
  if(this->fightId < 0 || this->fightId > 9.007199254740992E15)
  {
    qDebug()<<"ERREUR - GuildFightPlayersHelpersJoinMessage -"<<"Forbidden value (" << this->fightId << ") on element of GuildFightPlayersHelpersJoinMessage.fightId.";
  }
}

void GuildFightPlayersHelpersJoinMessage::_playerInfotreeFunc(Reader *input)
{
  this->playerInfo = QSharedPointer<CharacterMinimalPlusLookInformations>(new CharacterMinimalPlusLookInformations() );
  this->playerInfo->deserializeAsync(this->_playerInfotree);
}

GuildFightPlayersHelpersJoinMessage::GuildFightPlayersHelpersJoinMessage()
{
  m_type = MessageEnum::GUILDFIGHTPLAYERSHELPERSJOINMESSAGE;
}

