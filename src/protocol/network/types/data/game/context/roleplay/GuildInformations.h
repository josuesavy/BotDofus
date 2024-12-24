#ifndef GUILDINFORMATIONS_H
#define GUILDINFORMATIONS_H

#include "src/protocol/network/types/AbstractClass.h"
#include "src/protocol/network/types/data/game/social/SocialEmblem.h"
#include "src/protocol/network/types/data/game/context/roleplay/BasicGuildInformations.h"
#include "src/utils/io/type/FuncTree.h"

class GuildInformations : public BasicGuildInformations
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_GuildInformations(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_GuildInformations(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_GuildInformations(FuncTree tree);
  GuildInformations();
  bool operator==(const GuildInformations &compared);

  SocialEmblem guildEmblem;

private:
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDINFORMATIONS_H