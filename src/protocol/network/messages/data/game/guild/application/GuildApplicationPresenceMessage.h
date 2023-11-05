#ifndef GUILDAPPLICATIONPRESENCEMESSAGE_H
#define GUILDAPPLICATIONPRESENCEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildApplicationPresenceMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationPresenceMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationPresenceMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationPresenceMessage(FuncTree tree);
  GuildApplicationPresenceMessage();

  bool isApplication;

private:
  void _isApplicationFunc(Reader *input);
};

#endif // GUILDAPPLICATIONPRESENCEMESSAGE_H