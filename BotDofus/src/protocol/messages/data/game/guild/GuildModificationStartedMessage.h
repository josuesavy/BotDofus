#ifndef GUILDMODIFICATIONSTARTEDMESSAGE_H
#define GUILDMODIFICATIONSTARTEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/engines/io/network/utils/BooleanByteWrapper.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildModificationStartedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationStartedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationStartedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationStartedMessage(FuncTree tree);
  GuildModificationStartedMessage();

  bool canChangeName;
  bool canChangeEmblem;

private:
  void deserializeByteBoxes(Reader *input);
};

#endif // GUILDMODIFICATIONSTARTEDMESSAGE_H