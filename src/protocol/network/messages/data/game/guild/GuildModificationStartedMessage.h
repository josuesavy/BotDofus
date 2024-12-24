#ifndef GUILDMODIFICATIONSTARTEDMESSAGE_H
#define GUILDMODIFICATIONSTARTEDMESSAGE_H

#include "src/utils/io/type/BooleanByteWrapper.h"
#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

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