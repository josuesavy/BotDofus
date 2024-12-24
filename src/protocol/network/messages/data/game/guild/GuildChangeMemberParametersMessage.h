#ifndef GUILDCHANGEMEMBERPARAMETERSMESSAGE_H
#define GUILDCHANGEMEMBERPARAMETERSMESSAGE_H

#include "src/utils/io/type/FuncTree.h"
#include "src/protocol/network/messages/AbstractMessage.h"

class GuildChangeMemberParametersMessage : public AbstractMessage
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildChangeMemberParametersMessage(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildChangeMemberParametersMessage(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildChangeMemberParametersMessage(FuncTree tree);
  GuildChangeMemberParametersMessage();

  double memberId;
  uint rankId;
  uint experienceGivenPercent;

private:
  void _memberIdFunc(Reader *input);
  void _rankIdFunc(Reader *input);
  void _experienceGivenPercentFunc(Reader *input);
};

#endif // GUILDCHANGEMEMBERPARAMETERSMESSAGE_H