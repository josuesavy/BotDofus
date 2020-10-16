#ifndef GUILDFACTSERRORMESSAGE_H
#define GUILDFACTSERRORMESSAGE_H

#include "src/Engines/IO/Network/Utils/FuncTree.h"
#include "src/Protocol/Messages/AbstractMessage.h"

class GuildFactsErrorMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildFactsErrorMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildFactsErrorMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildFactsErrorMessage(FuncTree tree);
  GuildFactsErrorMessage();

  uint guildId;

private:
  void _guildIdFunc(Reader *input);
};

#endif // GUILDFACTSERRORMESSAGE_H