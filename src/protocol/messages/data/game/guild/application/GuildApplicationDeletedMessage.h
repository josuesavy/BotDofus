#ifndef GUILDAPPLICATIONDELETEDMESSAGE_H
#define GUILDAPPLICATIONDELETEDMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildApplicationDeletedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildApplicationDeletedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildApplicationDeletedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildApplicationDeletedMessage(FuncTree tree);
  GuildApplicationDeletedMessage();

  bool deleted;

private:
  void _deletedFunc(Reader *input);
};

#endif // GUILDAPPLICATIONDELETEDMESSAGE_H