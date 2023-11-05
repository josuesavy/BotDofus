#ifndef GUILDPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H
#define GUILDPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"
#include "src/protocol/messages/data/game/guild/application/GuildPlayerApplicationAbstractMessage.h"

class GuildPlayerNoApplicationInformationMessage : public GuildPlayerApplicationAbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPlayerNoApplicationInformationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPlayerNoApplicationInformationMessage(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPlayerNoApplicationInformationMessage(FuncTree tree);
  GuildPlayerNoApplicationInformationMessage();
};

#endif // GUILDPLAYERNOAPPLICATIONINFORMATIONMESSAGE_H