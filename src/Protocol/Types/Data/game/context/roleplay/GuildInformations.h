#ifndef GUILDINFORMATIONS_H
#define GUILDINFORMATIONS_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/guild/GuildEmblem.h"
#include "src/Protocol/Types/Data/game/context/roleplay/BasicGuildInformations.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

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

  GuildEmblem guildEmblem;

private:
  void _guildEmblemtreeFunc(Reader *input);

  FuncTree _guildEmblemtree;
};

#endif // GUILDINFORMATIONS_H