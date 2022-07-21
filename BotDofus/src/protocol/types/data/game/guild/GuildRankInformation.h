#ifndef GUILDRANKINFORMATION_H
#define GUILDRANKINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/GuildRankMinimalInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRankInformation : public GuildRankMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRankInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRankInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRankInformation(FuncTree tree);
  GuildRankInformation();
  bool operator==(const GuildRankInformation &compared);

  uint order;
  uint gfxId;
  bool modifiable;
  QList<uint> rights;

private:
  void _orderFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
  void _modifiableFunc(Reader *input);
  void _rightstreeFunc(Reader *input);
  void _rightsFunc(Reader *input);

  FuncTree _rightstree;
};

#endif // GUILDRANKINFORMATION_H