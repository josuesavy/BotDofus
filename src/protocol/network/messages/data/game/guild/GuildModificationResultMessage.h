#ifndef GUILDMODIFICATIONRESULTMESSAGE_H
#define GUILDMODIFICATIONRESULTMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildModificationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationResultMessage(FuncTree tree);
  GuildModificationResultMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // GUILDMODIFICATIONRESULTMESSAGE_H