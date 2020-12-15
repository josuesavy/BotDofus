#ifndef GUILDVERSATILEINFORMATIONS_H
#define GUILDVERSATILEINFORMATIONS_H

#include "src/protocol/types/AbstractClass.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildVersatileInformations : public AbstractClass
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildVersatileInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildVersatileInformations(Reader *input);
  void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildVersatileInformations(FuncTree tree);
  GuildVersatileInformations();
  bool operator==(const GuildVersatileInformations &compared);

  uint guildId;
  double leaderId;
  uint guildLevel;
  uint nbMembers;

private:
  void _guildIdFunc(Reader *input);
  void _leaderIdFunc(Reader *input);
  void _guildLevelFunc(Reader *input);
  void _nbMembersFunc(Reader *input);
};

#endif // GUILDVERSATILEINFORMATIONS_H