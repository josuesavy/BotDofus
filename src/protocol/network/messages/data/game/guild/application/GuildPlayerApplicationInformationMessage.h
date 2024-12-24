#ifndef GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H
#define GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H

#include "src/protocol/network/types/data/game/context/roleplay/GuildInformations.h"
#include "src/protocol/network/types/data/game/social/application/SocialApplicationInformation.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"
#include "src/protocol/network/messages/data/game/guild/application/GuildPlayerApplicationAbstractMessage.h"

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
  QSharedPointer<SocialApplicationInformation> apply;

private:
  void _guildInformationtreeFunc(Reader *input);
  void _applytreeFunc(Reader *input);

  FuncTree _guildInformationtree;
  FuncTree _applytree;
};

#endif // GUILDPLAYERAPPLICATIONINFORMATIONMESSAGE_H