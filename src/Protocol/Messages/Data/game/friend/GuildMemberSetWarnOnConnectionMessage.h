#ifndef GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H
#define GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildMemberSetWarnOnConnectionMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildMemberSetWarnOnConnectionMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildMemberSetWarnOnConnectionMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildMemberSetWarnOnConnectionMessage(FuncTree tree);
  GuildMemberSetWarnOnConnectionMessage();

  bool enable;

private:
  void _enableFunc(Reader *input);
};

#endif // GUILDMEMBERSETWARNONCONNECTIONMESSAGE_H