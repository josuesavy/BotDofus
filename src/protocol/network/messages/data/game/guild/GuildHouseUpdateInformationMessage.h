#ifndef GUILDHOUSEUPDATEINFORMATIONMESSAGE_H
#define GUILDHOUSEUPDATEINFORMATIONMESSAGE_H

#include "src/protocol/network/types/data/game/house/HouseInformationsForGuild.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildHouseUpdateInformationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildHouseUpdateInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildHouseUpdateInformationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildHouseUpdateInformationMessage(FuncTree tree);
  GuildHouseUpdateInformationMessage();

  QSharedPointer<HouseInformationsForGuild> housesInformations;

private:
  void _housesInformationstreeFunc(Reader *input);

  FuncTree _housesInformationstree;
};

#endif // GUILDHOUSEUPDATEINFORMATIONMESSAGE_H