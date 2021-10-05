#ifndef GUILDHOUSESINFORMATIONMESSAGE_H
#define GUILDHOUSESINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/house/HouseInformationsForGuild.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildHousesInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildHousesInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildHousesInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildHousesInformationMessage(FuncTree tree);
  GuildHousesInformationMessage();

  QList<QSharedPointer<HouseInformationsForGuild>> housesInformations;

private:
  void _housesInformationstreeFunc(Reader *input);
  void _housesInformationsFunc(Reader *input);

  FuncTree _housesInformationstree;
};

#endif // GUILDHOUSESINFORMATIONMESSAGE_H