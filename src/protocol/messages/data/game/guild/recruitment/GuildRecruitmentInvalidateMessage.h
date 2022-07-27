#ifndef GUILDRECRUITMENTINVALIDATEMESSAGE_H
#define GUILDRECRUITMENTINVALIDATEMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

class GuildRecruitmentInvalidateMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRecruitmentInvalidateMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRecruitmentInvalidateMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRecruitmentInvalidateMessage(FuncTree tree);
  GuildRecruitmentInvalidateMessage();
};

#endif // GUILDRECRUITMENTINVALIDATEMESSAGE_H