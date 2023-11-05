#include "GuildInsiderFactSheetInformations.h"

void GuildInsiderFactSheetInformations::serialize(Writer *output)
{
  this->serializeAs_GuildInsiderFactSheetInformations(output);
}

void GuildInsiderFactSheetInformations::serializeAs_GuildInsiderFactSheetInformations(Writer *output)
{
  GuildFactSheetInformations::serializeAs_GuildFactSheetInformations(output);
  output->writeUTF(this->leaderName);
}

void GuildInsiderFactSheetInformations::deserialize(Reader *input)
{
  this->deserializeAs_GuildInsiderFactSheetInformations(input);
}

void GuildInsiderFactSheetInformations::deserializeAs_GuildInsiderFactSheetInformations(Reader *input)
{
  GuildFactSheetInformations::deserialize(input);
  this->_leaderNameFunc(input);
}

void GuildInsiderFactSheetInformations::deserializeAsync(FuncTree tree)
{
  this->deserializeAsyncAs_GuildInsiderFactSheetInformations(tree);
}

void GuildInsiderFactSheetInformations::deserializeAsyncAs_GuildInsiderFactSheetInformations(FuncTree tree)
{
  GuildFactSheetInformations::deserializeAsync(tree);
  tree.addChild(std::bind(&GuildInsiderFactSheetInformations::_leaderNameFunc, this, std::placeholders::_1));
}

void GuildInsiderFactSheetInformations::_leaderNameFunc(Reader *input)
{
  this->leaderName = input->readUTF();
}

GuildInsiderFactSheetInformations::GuildInsiderFactSheetInformations()
{
  m_types<<ClassEnum::GUILDINSIDERFACTSHEETINFORMATIONS;
}

bool GuildInsiderFactSheetInformations::operator==(const GuildInsiderFactSheetInformations &compared)
{
  if(leaderName == compared.leaderName)
  return true;
  
  return false;
}

