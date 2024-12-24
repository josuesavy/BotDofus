#ifndef GUILDLEVELUPMESSAGE_H
#define GUILDLEVELUPMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildLevelUpMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildLevelUpMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildLevelUpMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildLevelUpMessage(FuncTree tree);
  GuildLevelUpMessage();

  uint newLevel;

private:
  void _newLevelFunc(Reader *input);
};

#endif // GUILDLEVELUPMESSAGE_H