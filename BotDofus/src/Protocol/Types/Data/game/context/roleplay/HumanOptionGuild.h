#ifndef HUMANOPTIONGUILD_H
#define HUMANOPTIONGUILD_H

#include "src/Protocol/Types/AbstractClass.h"
#include "src/Protocol/Types/Data/game/context/roleplay/GuildInformations.h"
#include "src/Protocol/Types/Data/game/context/roleplay/HumanOption.h"
#include "src/Engines/IO/Network/Utils/FuncTree.h"

class HumanOptionGuild : public HumanOption
{
public:
  virtual void serialize(Writer *output);
  void serializeAs_HumanOptionGuild(Writer *output);
  virtual void deserialize(Reader *input);
  void deserializeAs_HumanOptionGuild(Reader *input);
  virtual void deserializeAsync(FuncTree tree);
  void deserializeAsyncAs_HumanOptionGuild(FuncTree tree);
  HumanOptionGuild();
  bool operator==(const HumanOptionGuild &compared);

  QSharedPointer<GuildInformations> guildInformations;

private:
  void _guildInformationstreeFunc(Reader *input);

  FuncTree _guildInformationstree;
};

#endif // HUMANOPTIONGUILD_H