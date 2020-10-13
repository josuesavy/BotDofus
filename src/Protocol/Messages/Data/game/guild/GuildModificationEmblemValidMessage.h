#ifndef GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H
#define GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildModificationEmblemValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildModificationEmblemValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildModificationEmblemValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildModificationEmblemValidMessage(FuncTree tree);
  GuildModificationEmblemValidMessage();

  GuildEmblem guildEmblem;

private:
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDMODIFICATIONEMBLEMVALIDMESSAGE_H