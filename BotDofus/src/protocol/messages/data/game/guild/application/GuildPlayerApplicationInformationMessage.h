#ifndef GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H
#define GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H

#include "src/protocol/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/types/data/game/guild/application/GuildApplicationInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/guild/application/GuildPlayerApplicationAbstractMessage.h"

class GuildPlayerApplicationInformationMessage : public GuildPlayerApplicationAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPlayerApplicationInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPlayerApplicationInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPlayerApplicationInformationMessage(FuncTree tree);
  GuildPlayerApplicationInformationMessage();

  QSharedPointer<GuildInformations> guildInformation;
  QSharedPointer<GuildApplicationInformation> apply;

private:
  void _guildInformationtreeFunc(Reader *input);
  void _applytreeFunc(Reader *input);

  FuncTree _guildInformationtree;
  FuncTree _applytree;
};

#endif // GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H