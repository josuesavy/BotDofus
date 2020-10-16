#ifndef GUILDCREATIONVALIDMESSAGE_H
#define GUILDCREATIONVALIDMESSAGE_H

#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildCreationValidMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildCreationValidMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildCreationValidMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildCreationValidMessage(FuncTree tree);
  GuildCreationValidMessage();

  QString guildName;
  GuildEmblem guildEmblem;

private:
  void _guildNameFunc(Reader *input);
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDCREATIONVALIDMESSAGE_H