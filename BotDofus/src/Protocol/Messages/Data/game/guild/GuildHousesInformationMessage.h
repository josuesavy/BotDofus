#ifndef GUILDHOUSESINFORMATIONMESSAGE_H
#define GUILDHOUSESINFORMATIONMESSAGE_H

#include "src/Protocol/Types/Data/game/house/HouseInformationsForGuild.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

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