#ifndef GUILDMODIFICATIONNAMEVALIDMESSAGE_H
#define GUILDMODIFICATIONNAMEVALIDMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildModificationNameValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationNameValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationNameValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationNameValidMessage(FuncTree tree);
  GuildModificationNameValidMessage();

  QString guildName;

private:
  void _guildNameFunc(Reader *input);
};

#endif // GUILDMODIFICATIONNAMEVALIDMESSAGE_H