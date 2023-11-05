#ifndef HUMANOPTIONGUILD_H
#define HUMANOPTIONGUILD_H

#include "src/protocol/types/AbstractClass.h"
#include "src/protocol/types/data/game/context/roleplay/HumanOption.h"
#include "src/engines/io/network/utils/FuncTree.h"

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

   guildInformations;

private:
  void _guildInformationstreeFunc(Reader *input);

  FuncTree _guildInformationstree;
};

#endif // HUMANOPTIONGUILD_H