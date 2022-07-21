#ifndef GUILDRANKPUBLICINFORMATION_H
#define GUILDRANKPUBLICINFORMATION_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/guild/GuildRankMinimalInformation.h"
#include "src/engines/io/network/utils/FuncTree.h"

class GuildRankPublicInformation : public GuildRankMinimalInformation
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildRankPublicInformation(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildRankPublicInformation(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildRankPublicInformation(FuncTree tree);
  GuildRankPublicInformation();
  bool operator==(const GuildRankPublicInformation &compared);

  uint order;
  uint gfxId;

private:
  void _orderFunc(Reader *input);
  void _gfxIdFunc(Reader *input);
};

#endif // GUILDRANKPUBLICINFORMATION_H