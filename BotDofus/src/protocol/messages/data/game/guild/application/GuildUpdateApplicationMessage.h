#ifndef GUILDUPDATEAPPLICATIONMESSAGE_H
#define GUILDUPDATEAPPLICATIONMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildUpdateApplicationMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildUpdateApplicationMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildUpdateApplicationMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildUpdateApplicationMessage(FuncTree tree);
  GuildUpdateApplicationMessage();

  QString applyText;
  uint guildId;

private:
  void _applyTextFunc(Reader *input);
  void _guildIdFunc(Reader *input);
};

#endif // GUILDUPDATEAPPLICATIONMESSAGE_H