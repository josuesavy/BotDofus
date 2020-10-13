#ifndef GUILDPADDOCKREMOVEDMESSAGE_H
#define GUILDPADDOCKREMOVEDMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildPaddockRemovedMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildPaddockRemovedMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildPaddockRemovedMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildPaddockRemovedMessage(FuncTree tree);
  GuildPaddockRemovedMessage();

  double paddockId;

private:
  void _paddockIdFunc(Reader *input);
};

#endif // GUILDPADDOCKREMOVEDMESSAGE_H