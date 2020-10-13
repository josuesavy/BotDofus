#ifndef GUILDCREATIONRESULTMESSAGE_H
#define GUILDCREATIONRESULTMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildCreationResultMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildCreationResultMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildCreationResultMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildCreationResultMessage(FuncTree tree);
  GuildCreationResultMessage();

  uint result;

private:
  void _resultFunc(Reader *input);
};

#endif // GUILDCREATIONRESULTMESSAGE_H