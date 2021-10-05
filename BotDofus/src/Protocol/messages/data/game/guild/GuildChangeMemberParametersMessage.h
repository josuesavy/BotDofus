#ifndef GUILDCHANGEMEMBERPARAMETERSMESSAGE_H
#define GUILDCHANGEMEMBERPARAMETERSMESSAGE_H

#include "src/engines/io/network/utils/FuncTree.h"
#include "src/protocol/messages/AbstractMessage.h"

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
  uint rank;
  uint experienceGivenPercent;
  uint rights;

private:
  void _memberIdFunc(Reader *input);
  void _rankFunc(Reader *input);
  void _experienceGivenPercentFunc(Reader *input);
  void _rightsFunc(Reader *input);
};

#endif // GUILDCHANGEMEMBERPARAMETERSMESSAGE_H