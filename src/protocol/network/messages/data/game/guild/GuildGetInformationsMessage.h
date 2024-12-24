#ifndef GUILDGETINFORMATIONSMESSAGE_H
#define GUILDGETINFORMATIONSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildGetInformationsMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildGetInformationsMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildGetInformationsMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildGetInformationsMessage(FuncTree tree);
  GuildGetInformationsMessage();

  uint infoType;

private:
  void _infoTypeFunc(Reader *input);
};

#endif // GUILDGETINFORMATIONSMESSAGE_H